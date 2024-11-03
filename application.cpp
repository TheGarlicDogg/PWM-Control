#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    TCP_Server = new QTcpServer();
   if(!TCP_Server->listen(QHostAddress::Any, 8080)){
       QMessageBox::information(this,"Контроль светодиода","Неудачный запуск сервера");
   } else{
       connect(TCP_Server, SIGNAL(newConnection()), this, SLOT(newConnection()));
   }
   qDebug() << TCP_Server->errorString();
   setWindowTitle("Контроль ШИМ");
   ui->timeEdit->setCurrentSection(QDateTimeEdit::SecondSection);
   ui->timeEdit_2->setCurrentSection(QDateTimeEdit::SecondSection);
   ui->timeEdit_3->setCurrentSection(QDateTimeEdit::SecondSection);
   //ui->textEdit_Client_Messages->append(QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Клиент " + "1927" + ": Подключился к серверу");
   //ui->comboBox_Client_List->addItem("1927");
}

Application::~Application()
{
    foreach(QTcpSocket *socket, Client_Connection_List){
        socket->write("ce");
    }
    TCP_Server->close();
    this->close();
    delete ui;
}

void Application::newConnection()
{
    while(TCP_Server->hasPendingConnections()){
        Add_New_Client_Connection(TCP_Server->nextPendingConnection());
    }
}

void Application::Add_New_Client_Connection(QTcpSocket *socket)
{
    connect(socket, &QAbstractSocket::stateChanged, this, &Application::socketDisconnected);
    Client_Connection_List.append(socket);
    // ui->comboBox_Client_List->addItem(QString::number(socket->socketDescriptor())); использовать если комбо бокс использовать в качестве списка клиентов
    QString Client = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Клиент " + QString::number(socket->socketDescriptor()) + ": Подключился к серверу";
    ui->textEdit_Client_Messages->append(Client);
}

void Application::on_pushButton_clicked()
{
    QString Message_For_Client;
    QString Receiver = ui->comboBox_Client_List->currentText();
    QString Log_Message;
    if(Client_Connection_List.empty()){
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> К серверу не подключен ни один клиент";
        ui->textEdit_Client_Messages->append(Log_Message);
        return;
    }

    if(ui->comboBox_Client_List->currentText() == "Всем"){
        QString Message_For_Client = ui->spinBox_Freq->text()+" "+ui->spinBox_DutyCycle->text()+" "+QString::number(ui->timeEdit->time().hour()*3600+ui->timeEdit->time().minute()*60+ui->timeEdit->time().second())+" "+ui->spinBox_Freq_2->text()+" "+ui->spinBox_DutyCycle_2->text()+" "+QString::number(ui->timeEdit_2->time().hour()*3600+ui->timeEdit_2->time().minute()*60+ui->timeEdit_2->time().second())+" " + ui->spinBox_Freq_3->text()+" "+ui->spinBox_DutyCycle_3->text()+" "+QString::number(ui->timeEdit_3->time().hour()*3600+ui->timeEdit_3->time().minute()*60+ui->timeEdit_3->time().second())+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу всех датчиков c параметрами" + getSensorsLogText(1) + getSensorsLogText(2) + getSensorsLogText(3);
    } else if (ui->comboBox_Client_List->currentText() == "1"){
        QString Message_For_Client = ui->spinBox_Freq->text()+" "+ui->spinBox_DutyCycle->text()+" "+QString::number(ui->timeEdit->time().hour()*3600+ui->timeEdit->time().minute()*60+ui->timeEdit->time().second())+" 10 0 0 10 0 0"+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 1 датчика c параметрами" + getSensorsLogText(1);
    } else if (ui->comboBox_Client_List->currentText() == "2"){
        QString Message_For_Client = "10 0 0 " + ui->spinBox_Freq_2->text()+" "+ui->spinBox_DutyCycle_2->text()+" "+QString::number(ui->timeEdit_2->time().hour()*3600+ui->timeEdit_2->time().minute()*60+ui->timeEdit_2->time().second())+ " 10 0 0" +"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 2 датчика c параметрами" + getSensorsLogText(2);
    } else if (ui->comboBox_Client_List->currentText() == "3"){
        QString Message_For_Client = "10 0 0 10 0 0 " + ui->spinBox_Freq_3->text()+" "+ui->spinBox_DutyCycle_3->text()+" "+QString::number(ui->timeEdit_3->time().hour()*3600+ui->timeEdit_3->time().minute()*60+ui->timeEdit_3->time().second())+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 3 датчика c параметрами" + getSensorsLogText(3);
    } else if (ui->comboBox_Client_List->currentText() == "1 & 2"){
        QString Message_For_Client = ui->spinBox_Freq->text()+" "+ui->spinBox_DutyCycle->text()+" "+QString::number(ui->timeEdit->time().hour()*3600+ui->timeEdit->time().minute()*60+ui->timeEdit->time().second())+" "+ui->spinBox_Freq_2->text()+" "+ui->spinBox_DutyCycle_2->text()+" "+QString::number(ui->timeEdit_2->time().hour()*3600+ui->timeEdit_2->time().minute()*60+ui->timeEdit_2->time().second())+ " 10 0 0"+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 1 и 2 датчика c параметрами" + getSensorsLogText(1)+ getSensorsLogText(2);
    } else if (ui->comboBox_Client_List->currentText() == "1 & 3"){
        QString Message_For_Client = ui->spinBox_Freq->text()+" "+ui->spinBox_DutyCycle->text()+" "+QString::number(ui->timeEdit->time().hour()*3600+ui->timeEdit->time().minute()*60+ui->timeEdit->time().second())+ " 10 0 0 "+ui->spinBox_Freq_3->text()+" "+ui->spinBox_DutyCycle_3->text()+" "+QString::number(ui->timeEdit_3->time().hour()*3600+ui->timeEdit_3->time().minute()*60+ui->timeEdit_3->time().second())+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 1 и 3 датчика c параметрами" + getSensorsLogText(1) + getSensorsLogText(3);
    } else if (ui->comboBox_Client_List->currentText() == "2 & 3"){
        QString Message_For_Client = "10 0 0 " + ui->spinBox_Freq_2->text()+" "+ui->spinBox_DutyCycle_2->text()+" "+QString::number(ui->timeEdit_2->time().hour()*3600+ui->timeEdit_2->time().minute()*60+ui->timeEdit_2->time().second())+" " + ui->spinBox_Freq_3->text()+" "+ui->spinBox_DutyCycle_3->text()+" "+QString::number(ui->timeEdit_3->time().hour()*3600+ui->timeEdit_3->time().minute()*60+ui->timeEdit_3->time().second())+"\n";
        qDebug() << Message_For_Client;
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу 2 и 3 датчика c параметрами" + getSensorsLogText(2)+ getSensorsLogText(3);
    }

    /*
    {
        foreach(QTcpSocket *socket, Client_Connection_List){
            if(socket->socketDescriptor()== Receiver.toLongLong()){
                socket->write(Message_For_Client.toStdString().c_str());
            }
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу клиента " + Receiver + " c параметрами { "+ ui->spinBox_Freq->text()+ " Гц, " + ui->spinBox_DutyCycle->text()+"%, " +Timer.toString("hh:mm:ss") + " }";
    }
*/

    //QTimer::singleShot(time*1000, 0, QApplication::beep);
    ui->textEdit_Client_Messages->append(Log_Message);
}
void Application::socketDisconnected(QAbstractSocket::SocketState state)
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    QString Client = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Клиент " + QString::number(socket->socketDescriptor()) + ": Отключился от сервера";
    ui->textEdit_Client_Messages->append(Client);
    qDebug() << "disc " << state;
}
void Application::on_pushButton_2_clicked()
{
    QString Message_For_Client = "cs"; //command_exit
    //QString Receiver = ui->comboBox_Client_List->currentText();
    QString Log_Message;
    if(Client_Connection_List.empty()){
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> К серверу не подключен ни один клиент";
    }
    /* else if(ui->comboBox_Client_List->currentText() == "Всем"){
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
       Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер остановил работу всех клиентов";
    } else{
        foreach(QTcpSocket *socket, Client_Connection_List){
            if(socket->socketDescriptor()== Receiver.toLongLong()){
                socket->write(Message_For_Client.toStdString().c_str());
            }
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер остановил работу клиента " + Receiver;
    }
    */
    foreach(QTcpSocket *socket, Client_Connection_List){
        socket->write(Message_For_Client.toStdString().c_str());
    }
    Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер остановил работу клиента";
    ui->textEdit_Client_Messages->append(Log_Message);
}
QString Application::getSensorsLogText(int num){
    if (num==1){
        return " { " + ui->spinBox_Freq->text()+ " Гц, " + ui->spinBox_DutyCycle->text()+"%, " +ui->timeEdit->time().toString("hh:mm:ss") + " }";
    }
    if (num==2){
        return " { " + ui->spinBox_Freq_2->text()+ " Гц, " + ui->spinBox_DutyCycle_2->text()+"%, " +ui->timeEdit_2->time().toString("hh:mm:ss") + " }";
    }
    if (num==3){
        return " { " + ui->spinBox_Freq_3->text()+ " Гц, " + ui->spinBox_DutyCycle_3->text()+"%, " +ui->timeEdit_3->time().toString("hh:mm:ss") + " }";
    }
}

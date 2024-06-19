#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);

    TCP_Server = new QTcpServer();
   if(!TCP_Server->listen(QHostAddress::Any, 8080)){
       QMessageBox::information(this,"Контроль светодиода","Неудачный запуск сервера");
   } else{
       connect(TCP_Server, SIGNAL(newConnection()), this, SLOT(newConnection()));
   }
   setWindowTitle("Контроль ШИМ");
   ui->timeEdit->setCurrentSection(QDateTimeEdit::SecondSection);
}

Application::~Application()
{
    foreach(QTcpSocket *socket, Client_Connection_List){
        socket->write("ce");
    }
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
    ui->comboBox_Client_List->addItem(QString::number(socket->socketDescriptor()));
    QString Client = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Клиент " + QString::number(socket->socketDescriptor()) + ": Подключился к серверу";
    ui->textEdit_Client_Messages->append(Client);
}
/*
void Application::Read_Data_From_Socket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray Message_From_Server;
    static QTime timeStart = QTime::currentTime();
    while(socket->bytesAvailable()){
        Message_From_Server = socket->read(3);
        double key = timeStart.msecsTo(QTime::currentTime())/1000.0;
        ui->customPlot->graph(socketToGraph[QString::number(socket->socketDescriptor())])->addData(key, Message_From_Server.toInt());
        ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
        QString Message = "Клиент " + QString::number(socket->socketDescriptor()) + ": " + QString::fromStdString(Message_From_Server.toStdString()) + " " + QString::number(Message_From_Server.size()) + "_" + QString::number(socket->bytesAvailable());
        ui->textEdit_Client_Messages->append(Message);
    }
    ui->customPlot->replot();
}
*/

void Application::on_pushButton_clicked()
{
    QTime Timer = ui->timeEdit->time();
    int time = Timer.hour()*3600+Timer.minute()*60+Timer.second();
    QString Message_For_Client = ui->spinBox_Freq->text()+" "+ui->spinBox_DutyCycle->text()+" "+QString::number(time)+"\n";
    QString Receiver = ui->comboBox_Client_List->currentText();
    QString Log_Message;
    if(Client_Connection_List.empty()){
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> К серверу не подключен ни один клиент";
    } else if(ui->comboBox_Client_List->currentText() == "Всем"){
        foreach(QTcpSocket *socket, Client_Connection_List){
            socket->write(Message_For_Client.toStdString().c_str());
        }
       Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу всех клиентов c параметрами { "+ ui->spinBox_Freq->text()+ " Гц, " + ui->spinBox_DutyCycle->text()+"%, " +Timer.toString("hh:mm:ss") + " }";
    } else{
        foreach(QTcpSocket *socket, Client_Connection_List){
            if(socket->socketDescriptor()== Receiver.toLongLong()){
                socket->write(Message_For_Client.toStdString().c_str());
            }
        }
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> Сервер запустил работу клиента " + Receiver + " c параметрами { "+ ui->spinBox_Freq->text()+ " Гц, " + ui->spinBox_DutyCycle->text()+"%, " +Timer.toString("hh:mm:ss") + " }";
    }
    ui->textEdit_Client_Messages->append(Log_Message);
    QTimer::singleShot(time*1000, 0, QApplication::beep);
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
    QString Receiver = ui->comboBox_Client_List->currentText();
    QString Log_Message;
    if(Client_Connection_List.empty()){
        Log_Message = QDateTime::currentDateTime().toString("hh:mm:ss") + " -> К серверу не подключен ни один клиент";
    } else if(ui->comboBox_Client_List->currentText() == "Всем"){
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
    ui->textEdit_Client_Messages->append(Log_Message);
}

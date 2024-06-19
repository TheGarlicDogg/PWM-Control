#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QMessageBox>
#include <QAbstractSocket>
#include <QDateTime>
#include <QTimer>
//#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

//    void setupRealtimeData(QCustomPlot *customPlot);

private slots:
    void newConnection();
//    void Read_Data_From_Socket();
    void on_pushButton_clicked();
    void socketDisconnected(QAbstractSocket::SocketState state);
    void on_pushButton_2_clicked();

private:
    void Add_New_Client_Connection(QTcpSocket *socket);
    void standaloneFunc();

private:
    Ui::Application *ui;
    QTcpServer *TCP_Server;
    QList<QTcpSocket*> Client_Connection_List;
    QString windowName;
//    QTimer dataTimer;
    QMap<QString, int> socketToGraph;
};
#endif // APPLICATION_H

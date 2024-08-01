#include "application.h"
#include "display.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application app;
    app.show();
    Display display;
    display.show();
    return a.exec();
}

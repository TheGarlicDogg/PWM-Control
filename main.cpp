#include <QApplication>
#include "application.h"
#include "display.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;
    menu.show();
    return a.exec();
}

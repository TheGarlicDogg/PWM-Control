#include "menu.h"
#include "ui_menu.h"
#include "application.h"
#include "display.h"
#include <QFileDialog>
#include <QDialog>
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Меню");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pwmAppButton_clicked()
{
    Application* app = new Application;
    app->setWindowModality(Qt::ApplicationModal);
    app->show();
}

void Menu::on_edfDisplayAppButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выберите файл ЭЭГ"),
                                                    nullptr,
                                                    tr("Файлы ЭЭГ (*.edf *.bdf)"));
    if (fileName == ""){
        QMessageBox::warning(this, "Ошибка", "Некорректный путь к файлу.");
        return;
    }
    for(int i = 0; i < fileName.length(); i++){
        if(fileName[i].unicode()<=1103 && fileName[i].unicode()>=1040){
            QMessageBox::warning(this, "Ошибка", "В пути содержится кириллица. Измените путь к файлу.");
            return;
        }
    }
    Display* display = new Display(fileName);
    display->setWindowModality(Qt::ApplicationModal);
    display->show();
}


void Menu::on_exitButton_clicked()
{
    this->close();
}

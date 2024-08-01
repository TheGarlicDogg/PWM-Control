/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QComboBox *comboBox_Client_List;
    QTextEdit *textEdit_Client_Messages;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox_Freq;
    QTimeEdit *timeEdit;
    QSpinBox *spinBox_DutyCycle;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QString::fromUtf8("Application"));
        Application->resize(800, 416);
        Application->setMinimumSize(QSize(800, 416));
        Application->setMaximumSize(QSize(800, 416));
        QFont font;
        font.setPointSize(12);
        Application->setFont(font);
        Application->setAutoFillBackground(false);
        Application->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Application);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 340, 281, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        comboBox_Client_List = new QComboBox(centralwidget);
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->setObjectName(QString::fromUtf8("comboBox_Client_List"));
        comboBox_Client_List->setGeometry(QRect(590, 340, 201, 51));
        comboBox_Client_List->setFont(font1);
        textEdit_Client_Messages = new QTextEdit(centralwidget);
        textEdit_Client_Messages->setObjectName(QString::fromUtf8("textEdit_Client_Messages"));
        textEdit_Client_Messages->setGeometry(QRect(470, 10, 321, 321));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        textEdit_Client_Messages->setFont(font2);
        textEdit_Client_Messages->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 291, 41));
        QFont font3;
        font3.setPointSize(14);
        label->setFont(font3);
        label->setAutoFillBackground(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 301, 51));
        label_2->setFont(font3);
        label_2->setAutoFillBackground(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 220, 341, 51));
        label_3->setFont(font3);
        label_3->setAutoFillBackground(true);
        spinBox_Freq = new QSpinBox(centralwidget);
        spinBox_Freq->setObjectName(QString::fromUtf8("spinBox_Freq"));
        spinBox_Freq->setGeometry(QRect(20, 60, 161, 41));
        spinBox_Freq->setFont(font3);
        spinBox_Freq->setStyleSheet(QString::fromUtf8(""));
        spinBox_Freq->setWrapping(true);
        spinBox_Freq->setFrame(false);
        spinBox_Freq->setSuffix(QString::fromUtf8(""));
        spinBox_Freq->setMinimum(0);
        spinBox_Freq->setMaximum(1000);
        spinBox_Freq->setSingleStep(10);
        spinBox_Freq->setValue(10);
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(20, 280, 161, 41));
        timeEdit->setFont(font3);
        timeEdit->setStyleSheet(QString::fromUtf8(""));
        timeEdit->setFrame(false);
        timeEdit->setCurrentSection(QDateTimeEdit::HourSection);
        timeEdit->setCalendarPopup(false);
        spinBox_DutyCycle = new QSpinBox(centralwidget);
        spinBox_DutyCycle->setObjectName(QString::fromUtf8("spinBox_DutyCycle"));
        spinBox_DutyCycle->setGeometry(QRect(20, 170, 161, 41));
        spinBox_DutyCycle->setFont(font3);
        spinBox_DutyCycle->setStyleSheet(QString::fromUtf8(""));
        spinBox_DutyCycle->setWrapping(true);
        spinBox_DutyCycle->setFrame(false);
        spinBox_DutyCycle->setMinimum(0);
        spinBox_DutyCycle->setMaximum(100);
        spinBox_DutyCycle->setSingleStep(5);
        spinBox_DutyCycle->setValue(0);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 340, 281, 51));
        pushButton_2->setFont(font1);
        Application->setCentralWidget(centralwidget);

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QCoreApplication::translate("Application", "Application", nullptr));
        pushButton->setText(QCoreApplication::translate("Application", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        comboBox_Client_List->setItemText(0, QCoreApplication::translate("Application", "\320\222\321\201\320\265\320\274", nullptr));

        label->setText(QCoreApplication::translate("Application", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 (0-1000, \320\223\321\206)", nullptr));
        label_2->setText(QCoreApplication::translate("Application", "\320\241\320\272\320\262\320\260\320\266\320\275\320\276\321\201\321\202\321\214 (0-100, %)", nullptr));
        label_3->setText(QCoreApplication::translate("Application", "\320\222\321\200\320\265\320\274\321\217 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 (\321\207\321\207:\320\274\320\274:\321\201\321\201)", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("Application", "HH:mm:ss", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Application", "\320\241\321\202\320\276\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H

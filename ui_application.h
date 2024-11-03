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
#include <QtWidgets/QFrame>
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
    QSpinBox *spinBox_Freq_2;
    QSpinBox *spinBox_Freq_3;
    QSpinBox *spinBox_DutyCycle_2;
    QSpinBox *spinBox_DutyCycle_3;
    QTimeEdit *timeEdit_2;
    QTimeEdit *timeEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;

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
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->addItem(QString());
        comboBox_Client_List->setObjectName(QString::fromUtf8("comboBox_Client_List"));
        comboBox_Client_List->setGeometry(QRect(590, 340, 201, 51));
        comboBox_Client_List->setFont(font1);
        textEdit_Client_Messages = new QTextEdit(centralwidget);
        textEdit_Client_Messages->setObjectName(QString::fromUtf8("textEdit_Client_Messages"));
        textEdit_Client_Messages->setGeometry(QRect(480, 10, 311, 320));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        textEdit_Client_Messages->setFont(font2);
        textEdit_Client_Messages->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 241, 31));
        QFont font3;
        font3.setPointSize(14);
        label->setFont(font3);
        label->setAutoFillBackground(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 271, 31));
        label_2->setFont(font3);
        label_2->setAutoFillBackground(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 240, 321, 31));
        label_3->setFont(font3);
        label_3->setAutoFillBackground(true);
        spinBox_Freq = new QSpinBox(centralwidget);
        spinBox_Freq->setObjectName(QString::fromUtf8("spinBox_Freq"));
        spinBox_Freq->setGeometry(QRect(20, 100, 120, 30));
        spinBox_Freq->setFont(font3);
        spinBox_Freq->setStyleSheet(QString::fromUtf8(""));
        spinBox_Freq->setWrapping(true);
        spinBox_Freq->setFrame(false);
        spinBox_Freq->setSuffix(QString::fromUtf8(""));
        spinBox_Freq->setMinimum(10);
        spinBox_Freq->setMaximum(1000);
        spinBox_Freq->setSingleStep(10);
        spinBox_Freq->setValue(10);
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(20, 280, 120, 30));
        timeEdit->setFont(font3);
        timeEdit->setStyleSheet(QString::fromUtf8(""));
        timeEdit->setFrame(false);
        timeEdit->setCurrentSection(QDateTimeEdit::SecondSection);
        timeEdit->setCalendarPopup(false);
        timeEdit->setCurrentSectionIndex(2);
        spinBox_DutyCycle = new QSpinBox(centralwidget);
        spinBox_DutyCycle->setObjectName(QString::fromUtf8("spinBox_DutyCycle"));
        spinBox_DutyCycle->setGeometry(QRect(20, 190, 120, 30));
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
        spinBox_Freq_2 = new QSpinBox(centralwidget);
        spinBox_Freq_2->setObjectName(QString::fromUtf8("spinBox_Freq_2"));
        spinBox_Freq_2->setGeometry(QRect(180, 100, 120, 30));
        spinBox_Freq_2->setFont(font3);
        spinBox_Freq_2->setStyleSheet(QString::fromUtf8(""));
        spinBox_Freq_2->setWrapping(true);
        spinBox_Freq_2->setFrame(false);
        spinBox_Freq_2->setSuffix(QString::fromUtf8(""));
        spinBox_Freq_2->setMinimum(10);
        spinBox_Freq_2->setMaximum(1000);
        spinBox_Freq_2->setSingleStep(10);
        spinBox_Freq_2->setValue(10);
        spinBox_Freq_3 = new QSpinBox(centralwidget);
        spinBox_Freq_3->setObjectName(QString::fromUtf8("spinBox_Freq_3"));
        spinBox_Freq_3->setGeometry(QRect(340, 100, 120, 30));
        spinBox_Freq_3->setFont(font3);
        spinBox_Freq_3->setStyleSheet(QString::fromUtf8(""));
        spinBox_Freq_3->setWrapping(true);
        spinBox_Freq_3->setFrame(false);
        spinBox_Freq_3->setSuffix(QString::fromUtf8(""));
        spinBox_Freq_3->setMinimum(10);
        spinBox_Freq_3->setMaximum(1000);
        spinBox_Freq_3->setSingleStep(10);
        spinBox_Freq_3->setValue(10);
        spinBox_DutyCycle_2 = new QSpinBox(centralwidget);
        spinBox_DutyCycle_2->setObjectName(QString::fromUtf8("spinBox_DutyCycle_2"));
        spinBox_DutyCycle_2->setGeometry(QRect(180, 190, 120, 30));
        spinBox_DutyCycle_2->setFont(font3);
        spinBox_DutyCycle_2->setStyleSheet(QString::fromUtf8(""));
        spinBox_DutyCycle_2->setWrapping(true);
        spinBox_DutyCycle_2->setFrame(false);
        spinBox_DutyCycle_2->setMinimum(0);
        spinBox_DutyCycle_2->setMaximum(100);
        spinBox_DutyCycle_2->setSingleStep(5);
        spinBox_DutyCycle_2->setValue(0);
        spinBox_DutyCycle_3 = new QSpinBox(centralwidget);
        spinBox_DutyCycle_3->setObjectName(QString::fromUtf8("spinBox_DutyCycle_3"));
        spinBox_DutyCycle_3->setGeometry(QRect(340, 190, 120, 30));
        spinBox_DutyCycle_3->setFont(font3);
        spinBox_DutyCycle_3->setStyleSheet(QString::fromUtf8(""));
        spinBox_DutyCycle_3->setWrapping(true);
        spinBox_DutyCycle_3->setFrame(false);
        spinBox_DutyCycle_3->setMinimum(0);
        spinBox_DutyCycle_3->setMaximum(100);
        spinBox_DutyCycle_3->setSingleStep(5);
        spinBox_DutyCycle_3->setValue(0);
        timeEdit_2 = new QTimeEdit(centralwidget);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(180, 280, 120, 30));
        timeEdit_2->setFont(font3);
        timeEdit_2->setStyleSheet(QString::fromUtf8(""));
        timeEdit_2->setFrame(false);
        timeEdit_2->setCurrentSection(QDateTimeEdit::SecondSection);
        timeEdit_2->setCalendarPopup(false);
        timeEdit_2->setCurrentSectionIndex(2);
        timeEdit_3 = new QTimeEdit(centralwidget);
        timeEdit_3->setObjectName(QString::fromUtf8("timeEdit_3"));
        timeEdit_3->setGeometry(QRect(340, 280, 120, 30));
        timeEdit_3->setFont(font3);
        timeEdit_3->setStyleSheet(QString::fromUtf8(""));
        timeEdit_3->setFrame(false);
        timeEdit_3->setCurrentSection(QDateTimeEdit::SecondSection);
        timeEdit_3->setCalendarPopup(false);
        timeEdit_3->setCurrentSectionIndex(2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 10, 121, 31));
        label_4->setFont(font3);
        label_4->setAutoFillBackground(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 10, 121, 31));
        label_5->setFont(font3);
        label_5->setAutoFillBackground(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 10, 121, 31));
        label_6->setFont(font3);
        label_6->setAutoFillBackground(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 481, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(320, 0, 16, 48));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(160, 0, 16, 49));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 322, 481, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        Application->setCentralWidget(centralwidget);
        line_3->raise();
        line_2->raise();
        pushButton->raise();
        comboBox_Client_List->raise();
        textEdit_Client_Messages->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        spinBox_Freq->raise();
        timeEdit->raise();
        spinBox_DutyCycle->raise();
        pushButton_2->raise();
        spinBox_Freq_2->raise();
        spinBox_Freq_3->raise();
        spinBox_DutyCycle_2->raise();
        spinBox_DutyCycle_3->raise();
        timeEdit_2->raise();
        timeEdit_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        line->raise();
        line_4->raise();

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QCoreApplication::translate("Application", "Application", nullptr));
        pushButton->setText(QCoreApplication::translate("Application", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        comboBox_Client_List->setItemText(0, QCoreApplication::translate("Application", "\320\222\321\201\320\265\320\274", nullptr));
        comboBox_Client_List->setItemText(1, QCoreApplication::translate("Application", "1", nullptr));
        comboBox_Client_List->setItemText(2, QCoreApplication::translate("Application", "2", nullptr));
        comboBox_Client_List->setItemText(3, QCoreApplication::translate("Application", "3", nullptr));
        comboBox_Client_List->setItemText(4, QCoreApplication::translate("Application", "1 & 2", nullptr));
        comboBox_Client_List->setItemText(5, QCoreApplication::translate("Application", "1 & 3", nullptr));
        comboBox_Client_List->setItemText(6, QCoreApplication::translate("Application", "2 & 3", nullptr));

        label->setText(QCoreApplication::translate("Application", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 (10-1000, \320\223\321\206)", nullptr));
        label_2->setText(QCoreApplication::translate("Application", "\320\241\320\272\320\262\320\260\320\266\320\275\320\276\321\201\321\202\321\214 (0-100, %)", nullptr));
        label_3->setText(QCoreApplication::translate("Application", "\320\222\321\200\320\265\320\274\321\217 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 (\321\207\321\207:\320\274\320\274:\321\201\321\201)", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("Application", "HH:mm:ss", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Application", "\320\241\321\202\320\276\320\277", nullptr));
        timeEdit_2->setDisplayFormat(QCoreApplication::translate("Application", "HH:mm:ss", nullptr));
        timeEdit_3->setDisplayFormat(QCoreApplication::translate("Application", "HH:mm:ss", nullptr));
        label_4->setText(QCoreApplication::translate("Application", "\320\224\320\260\321\202\321\207\320\270\320\272 1", nullptr));
        label_5->setText(QCoreApplication::translate("Application", "\320\224\320\260\321\202\321\207\320\270\320\272 2", nullptr));
        label_6->setText(QCoreApplication::translate("Application", "\320\224\320\260\321\202\321\207\320\270\320\272 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H

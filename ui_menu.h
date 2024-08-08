/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pwmAppButton;
    QPushButton *edfDisplayAppButton;
    QPushButton *exitButton;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(400, 300);
        Menu->setMinimumSize(QSize(400, 300));
        Menu->setMaximumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pwmAppButton = new QPushButton(Menu);
        pwmAppButton->setObjectName(QString::fromUtf8("pwmAppButton"));
        pwmAppButton->setMinimumSize(QSize(0, 70));
        QFont font;
        font.setPointSize(12);
        pwmAppButton->setFont(font);

        verticalLayout->addWidget(pwmAppButton);

        edfDisplayAppButton = new QPushButton(Menu);
        edfDisplayAppButton->setObjectName(QString::fromUtf8("edfDisplayAppButton"));
        edfDisplayAppButton->setMinimumSize(QSize(0, 70));
        edfDisplayAppButton->setFont(font);

        verticalLayout->addWidget(edfDisplayAppButton);

        exitButton = new QPushButton(Menu);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setMinimumSize(QSize(0, 70));
        exitButton->setFont(font);

        verticalLayout->addWidget(exitButton);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        pwmAppButton->setText(QCoreApplication::translate("Menu", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \320\250\320\230\320\234", nullptr));
        edfDisplayAppButton->setText(QCoreApplication::translate("Menu", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\255\320\255\320\223", nullptr));
        exitButton->setText(QCoreApplication::translate("Menu", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H

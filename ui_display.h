/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QWidget *centralwidget;
    QCustomPlot *customPlot;
    QPushButton *PlayButton;
    QPushButton *MoveRightButton;
    QPushButton *MoveLeftButton;
    QPushButton *StopButton;
    QSlider *timeSlider;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QString::fromUtf8("Display"));
        Display->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy);
        Display->setMinimumSize(QSize(800, 600));
        Display->setMaximumSize(QSize(800, 600));
        Display->setStyleSheet(QString::fromUtf8("\320\270"));
        Display->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(Display);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1600000, 1600000));
        centralwidget->setSizeIncrement(QSize(0, 0));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 771, 491));
        PlayButton = new QPushButton(centralwidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setGeometry(QRect(10, 550, 41, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("imgs/play-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon);
        PlayButton->setIconSize(QSize(24, 24));
        PlayButton->setCheckable(false);
        MoveRightButton = new QPushButton(centralwidget);
        MoveRightButton->setObjectName(QString::fromUtf8("MoveRightButton"));
        MoveRightButton->setGeometry(QRect(160, 550, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("imgs/right-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        MoveRightButton->setIcon(icon1);
        MoveRightButton->setIconSize(QSize(24, 24));
        MoveLeftButton = new QPushButton(centralwidget);
        MoveLeftButton->setObjectName(QString::fromUtf8("MoveLeftButton"));
        MoveLeftButton->setGeometry(QRect(110, 550, 41, 41));
        QFont font;
        font.setPointSize(6);
        MoveLeftButton->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("imgs/left-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        MoveLeftButton->setIcon(icon2);
        MoveLeftButton->setIconSize(QSize(24, 24));
        StopButton = new QPushButton(centralwidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(60, 550, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("imgs/stop-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon3);
        StopButton->setIconSize(QSize(24, 24));
        StopButton->setCheckable(false);
        timeSlider = new QSlider(centralwidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setGeometry(QRect(10, 510, 771, 31));
        timeSlider->setMinimumSize(QSize(0, 0));
        timeSlider->setMaximumSize(QSize(779, 480));
        timeSlider->setMouseTracking(true);
        timeSlider->setMaximum(98);
        timeSlider->setSingleStep(0);
        timeSlider->setPageStep(0);
        timeSlider->setOrientation(Qt::Horizontal);
        Display->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Display);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Display->setStatusBar(statusBar);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "MainWindow", nullptr));
        PlayButton->setText(QString());
        MoveRightButton->setText(QString());
        MoveLeftButton->setText(QString());
        StopButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H

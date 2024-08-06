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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QCustomPlot *customPlot;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *allSignalsList;
    QFrame *frame_4;
    QPushButton *removeSignalsButton;
    QPushButton *addSignalsButton;
    QListWidget *selectedSignalsList;
    QPushButton *submitSignalsButton;
    QSlider *timeSlider;
    QFrame *frame;
    QPushButton *MoveLeftButton;
    QPushButton *MoveRightButton;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QPushButton *ZoomButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu123;
    QMenu *menu123_2;
    QMenu *menu322;

    void setupUi(QMainWindow *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QString::fromUtf8("Display"));
        Display->resize(800, 625);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy);
        Display->setMinimumSize(QSize(800, 600));
        Display->setMaximumSize(QSize(16777215, 16777215));
        Display->setStyleSheet(QString::fromUtf8(""));
        Display->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(Display);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1600000, 1600000));
        centralwidget->setSizeIncrement(QSize(0, 0));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(780, 490));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        customPlot = new QCustomPlot(frame_2);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);
        customPlot->setMinimumSize(QSize(550, 490));

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(162, 490));
        frame_3->setMaximumSize(QSize(160, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        allSignalsList = new QListWidget(frame_3);
        allSignalsList->setObjectName(QString::fromUtf8("allSignalsList"));
        allSignalsList->setMinimumSize(QSize(160, 192));
        allSignalsList->setMaximumSize(QSize(160, 16777215));
        allSignalsList->setFocusPolicy(Qt::ClickFocus);
        allSignalsList->setAlternatingRowColors(true);
        allSignalsList->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(allSignalsList);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(160, 40));
        frame_4->setMaximumSize(QSize(160, 40));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        removeSignalsButton = new QPushButton(frame_4);
        removeSignalsButton->setObjectName(QString::fromUtf8("removeSignalsButton"));
        removeSignalsButton->setGeometry(QRect(80, 0, 80, 40));
        removeSignalsButton->setMinimumSize(QSize(80, 40));
        addSignalsButton = new QPushButton(frame_4);
        addSignalsButton->setObjectName(QString::fromUtf8("addSignalsButton"));
        addSignalsButton->setGeometry(QRect(0, 0, 80, 40));
        addSignalsButton->setMinimumSize(QSize(80, 40));

        verticalLayout_2->addWidget(frame_4);

        selectedSignalsList = new QListWidget(frame_3);
        selectedSignalsList->setObjectName(QString::fromUtf8("selectedSignalsList"));
        selectedSignalsList->setMinimumSize(QSize(160, 192));
        selectedSignalsList->setMaximumSize(QSize(160, 16777215));
        selectedSignalsList->setTabKeyNavigation(false);
        selectedSignalsList->setProperty("showDropIndicator", QVariant(false));
        selectedSignalsList->setDragEnabled(false);
        selectedSignalsList->setDragDropOverwriteMode(false);
        selectedSignalsList->setDragDropMode(QAbstractItemView::NoDragDrop);
        selectedSignalsList->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(selectedSignalsList);

        submitSignalsButton = new QPushButton(frame_3);
        submitSignalsButton->setObjectName(QString::fromUtf8("submitSignalsButton"));
        submitSignalsButton->setMinimumSize(QSize(160, 40));
        submitSignalsButton->setMaximumSize(QSize(160, 16777215));

        verticalLayout_2->addWidget(submitSignalsButton);


        gridLayout->addWidget(frame_3, 0, 1, 1, 1);

        frame_3->raise();
        customPlot->raise();

        verticalLayout->addWidget(frame_2);

        timeSlider = new QSlider(centralwidget);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setMinimumSize(QSize(770, 40));
        timeSlider->setMaximumSize(QSize(16777215, 40));
        timeSlider->setMouseTracking(true);
        timeSlider->setMaximum(98);
        timeSlider->setSingleStep(0);
        timeSlider->setPageStep(0);
        timeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(timeSlider);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(240, 40));
        frame->setMaximumSize(QSize(240, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MoveLeftButton = new QPushButton(frame);
        MoveLeftButton->setObjectName(QString::fromUtf8("MoveLeftButton"));
        MoveLeftButton->setGeometry(QRect(100, 0, 40, 40));
        MoveLeftButton->setMinimumSize(QSize(40, 40));
        MoveLeftButton->setMaximumSize(QSize(40, 40));
        QFont font;
        font.setPointSize(6);
        MoveLeftButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("imgs/left-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        MoveLeftButton->setIcon(icon);
        MoveLeftButton->setIconSize(QSize(24, 24));
        MoveRightButton = new QPushButton(frame);
        MoveRightButton->setObjectName(QString::fromUtf8("MoveRightButton"));
        MoveRightButton->setGeometry(QRect(150, 0, 40, 40));
        MoveRightButton->setMinimumSize(QSize(40, 40));
        MoveRightButton->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("imgs/right-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        MoveRightButton->setIcon(icon1);
        MoveRightButton->setIconSize(QSize(24, 24));
        PlayButton = new QPushButton(frame);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setGeometry(QRect(0, 0, 40, 40));
        PlayButton->setMinimumSize(QSize(40, 40));
        PlayButton->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("imgs/play-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon2);
        PlayButton->setIconSize(QSize(24, 24));
        PlayButton->setCheckable(false);
        StopButton = new QPushButton(frame);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(50, 0, 40, 40));
        StopButton->setMinimumSize(QSize(40, 40));
        StopButton->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("imgs/stop-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        StopButton->setIcon(icon3);
        StopButton->setIconSize(QSize(24, 24));
        StopButton->setCheckable(false);
        ZoomButton = new QPushButton(frame);
        ZoomButton->setObjectName(QString::fromUtf8("ZoomButton"));
        ZoomButton->setGeometry(QRect(200, 0, 40, 40));
        ZoomButton->setMinimumSize(QSize(40, 40));
        ZoomButton->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("imgs/zoom-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        ZoomButton->setIcon(icon4);
        ZoomButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(frame);

        Display->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Display);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        Display->setStatusBar(statusBar);
        menuBar = new QMenuBar(Display);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menu123 = new QMenu(menuBar);
        menu123->setObjectName(QString::fromUtf8("menu123"));
        menu123_2 = new QMenu(menuBar);
        menu123_2->setObjectName(QString::fromUtf8("menu123_2"));
        menu322 = new QMenu(menuBar);
        menu322->setObjectName(QString::fromUtf8("menu322"));
        Display->setMenuBar(menuBar);

        menuBar->addAction(menu123->menuAction());
        menuBar->addAction(menu123_2->menuAction());
        menuBar->addAction(menu322->menuAction());
        menu322->addSeparator();
        menu322->addSeparator();

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "MainWindow", nullptr));
        removeSignalsButton->setText(QCoreApplication::translate("Display", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        addSignalsButton->setText(QCoreApplication::translate("Display", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        submitSignalsButton->setText(QCoreApplication::translate("Display", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\201\320\270\320\263\320\275\320\260\320\273\321\213", nullptr));
        MoveLeftButton->setText(QString());
        MoveRightButton->setText(QString());
        PlayButton->setText(QString());
        StopButton->setText(QString());
        ZoomButton->setText(QString());
        menu123->setTitle(QCoreApplication::translate("Display", "123", nullptr));
        menu123_2->setTitle(QCoreApplication::translate("Display", "123", nullptr));
        menu322->setTitle(QCoreApplication::translate("Display", "322", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H

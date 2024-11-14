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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QFrame *plotSignals;
    QGridLayout *gridLayout;
    QFrame *signalsContol;
    QVBoxLayout *verticalLayout_2;
    QListWidget *allSignalsList;
    QFrame *frame_4;
    QPushButton *removeSignalsButton;
    QPushButton *addSignalsButton;
    QListWidget *selectedSignalsList;
    QPushButton *submitSignalsButton;
    QFrame *plotsFrame;
    QGridLayout *gridLayout_2;
    QCustomPlot *customPlot;
    QSlider *timeSlider;
    QFrame *controls;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QPushButton *MoveLeftButton;
    QPushButton *MoveRightButton;
    QPushButton *PlayButton;
    QPushButton *StopButton;
    QPushButton *ZoomButton;
    QPushButton *SpectrumButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QStatusBar *statusBar;

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
        plotSignals = new QFrame(centralwidget);
        plotSignals->setObjectName(QString::fromUtf8("plotSignals"));
        plotSignals->setMinimumSize(QSize(780, 490));
        plotSignals->setFrameShape(QFrame::StyledPanel);
        plotSignals->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(plotSignals);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        signalsContol = new QFrame(plotSignals);
        signalsContol->setObjectName(QString::fromUtf8("signalsContol"));
        signalsContol->setMinimumSize(QSize(162, 490));
        signalsContol->setMaximumSize(QSize(160, 16777215));
        signalsContol->setFrameShape(QFrame::StyledPanel);
        signalsContol->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(signalsContol);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        allSignalsList = new QListWidget(signalsContol);
        allSignalsList->setObjectName(QString::fromUtf8("allSignalsList"));
        allSignalsList->setMinimumSize(QSize(160, 192));
        allSignalsList->setMaximumSize(QSize(160, 16777215));
        allSignalsList->setFocusPolicy(Qt::ClickFocus);
        allSignalsList->setAlternatingRowColors(true);
        allSignalsList->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(allSignalsList);

        frame_4 = new QFrame(signalsContol);
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
        QFont font;
        font.setPointSize(8);
        addSignalsButton->setFont(font);

        verticalLayout_2->addWidget(frame_4);

        selectedSignalsList = new QListWidget(signalsContol);
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

        submitSignalsButton = new QPushButton(signalsContol);
        submitSignalsButton->setObjectName(QString::fromUtf8("submitSignalsButton"));
        submitSignalsButton->setMinimumSize(QSize(160, 40));
        submitSignalsButton->setMaximumSize(QSize(160, 16777215));

        verticalLayout_2->addWidget(submitSignalsButton);


        gridLayout->addWidget(signalsContol, 0, 1, 1, 1);

        plotsFrame = new QFrame(plotSignals);
        plotsFrame->setObjectName(QString::fromUtf8("plotsFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plotsFrame->sizePolicy().hasHeightForWidth());
        plotsFrame->setSizePolicy(sizePolicy1);
        plotsFrame->setMinimumSize(QSize(590, 490));
        plotsFrame->setFrameShape(QFrame::StyledPanel);
        plotsFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(plotsFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        customPlot = new QCustomPlot(plotsFrame);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);
        customPlot->setMinimumSize(QSize(550, 245));

        gridLayout_2->addWidget(customPlot, 0, 0, 1, 1);


        gridLayout->addWidget(plotsFrame, 0, 0, 1, 1);


        verticalLayout->addWidget(plotSignals);

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

        controls = new QFrame(centralwidget);
        controls->setObjectName(QString::fromUtf8("controls"));
        controls->setMinimumSize(QSize(300, 40));
        controls->setMaximumSize(QSize(16777215, 40));
        controls->setFrameShape(QFrame::StyledPanel);
        controls->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(controls);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(controls);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(290, 40));
        frame->setMaximumSize(QSize(290, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MoveLeftButton = new QPushButton(frame);
        MoveLeftButton->setObjectName(QString::fromUtf8("MoveLeftButton"));
        MoveLeftButton->setGeometry(QRect(100, 0, 40, 40));
        MoveLeftButton->setMinimumSize(QSize(40, 40));
        MoveLeftButton->setMaximumSize(QSize(40, 40));
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
        SpectrumButton = new QPushButton(frame);
        SpectrumButton->setObjectName(QString::fromUtf8("SpectrumButton"));
        SpectrumButton->setGeometry(QRect(250, 0, 40, 40));
        SpectrumButton->setMinimumSize(QSize(40, 40));
        SpectrumButton->setMaximumSize(QSize(40, 40));
        SpectrumButton->setIcon(icon4);
        SpectrumButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(frame);

        horizontalSpacer = new QSpacerItem(497, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(controls);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("imgs/information-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(controls);

        Display->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(Display);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        Display->setStatusBar(statusBar);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\255\320\255\320\223", nullptr));
        removeSignalsButton->setText(QCoreApplication::translate("Display", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        addSignalsButton->setText(QCoreApplication::translate("Display", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        submitSignalsButton->setText(QCoreApplication::translate("Display", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\201\320\270\320\263\320\275\320\260\320\273\321\213", nullptr));
#if QT_CONFIG(tooltip)
        MoveLeftButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>1 \321\201\320\265\320\272. \320\275\320\260\320\267\320\260\320\264</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        MoveLeftButton->setText(QString());
#if QT_CONFIG(tooltip)
        MoveRightButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>1 \321\201\320\265\320\272. \320\262\320\277\320\265\321\200\320\265\320\264</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        MoveRightButton->setText(QString());
#if QT_CONFIG(tooltip)
        PlayButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        PlayButton->setWhatsThis(QCoreApplication::translate("Display", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        PlayButton->setText(QString());
#if QT_CONFIG(tooltip)
        StopButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>\320\241\321\202\320\276\320\277</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        StopButton->setText(QString());
#if QT_CONFIG(tooltip)
        ZoomButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ZoomButton->setText(QString());
#if QT_CONFIG(tooltip)
        SpectrumButton->setToolTip(QCoreApplication::translate("Display", "<html><head/><body><p>\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\320\274\320\265\321\200\321\213</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SpectrumButton->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H

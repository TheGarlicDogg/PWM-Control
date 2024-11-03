#ifndef DISPLAY_H
#define DISPLAY_H
#include "qcustomplot.h"
#include "edflib.h"
#include <algorithm>
#include <QMainWindow>

class QPushButton;

namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT
public:
    explicit Display(QWidget *parent = nullptr);
    explicit Display(QString filename, QWidget *parent = nullptr);


    virtual void resizeEvent(QResizeEvent *event) override;
    ~Display();

private slots:
    void on_PlayButton_clicked();
    void on_StopButton_clicked();
    void on_MoveLeftButton_clicked();
    void PlaybackStep();
    void on_MoveRightButton_clicked();
    void mouseWheelMain(QWheelEvent * event);
    void mouseWheelCompare(QWheelEvent * event);

    void on_timeSlider_sliderMoved(int position);

    void on_addSignalsButton_clicked();

    void on_removeSignalsButton_clicked();

    void on_submitSignalsButton_clicked();

    void on_ZoomButton_clicked();
    void on_pushButton_clicked();
    void replotMainPlotSlot();
    void replotComparePlotSlot();

private:
    QString filename, compfilename;
    bool isComparePlotActive = false;
    edflib_hdr_t hdr, hdr2;
    QTimer* playBackTimer = new QTimer(this);
    void setupDisplayData(QCustomPlot *customPlot);
    void displaySignals();
    Ui::Display *ui;
    QMap<int, QString> channelToLabel;
    QMap<int, QColor> colors;
    QPushButton* addPlotButton;
    QCustomPlot* comparePlot;
    void mouseWheel(QWheelEvent * event, QCustomPlot* plot);
    void updateButtonPosition();
    void addPlot();
    void setupColors();
};

#endif // DISPLAY_H

#ifndef DISPLAY_H
#define DISPLAY_H
#include "qcustomplot.h"
#include "edflib.h"
#include <algorithm>
#include <QMainWindow>

namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);

    void displayData();

    ~Display();

private slots:
    void on_PlayButton_clicked();
    void on_StopButton_clicked();
    void on_MoveLeftButton_clicked();
    void PlaybackStep();
    void on_MoveRightButton_clicked();

    void mouseWheel(QWheelEvent * event);

    void on_timeSlider_sliderMoved(int position);

    void on_addSignalsButton_clicked();

    void on_removeSignalsButton_clicked();

    void on_submitSignalsButton_clicked();

    void on_ZoomButton_clicked();

private:
    edflib_hdr_t hdr;
    double shift;
    int duration;
    QTimer* playBackTimer = new QTimer(this);
    void setupDisplayData(QCustomPlot *customPlot);
    Ui::Display *ui;
    QMap<int, QString> channelToLabel;
    QMap<int, QColor> colors;
};

#endif // DISPLAY_H

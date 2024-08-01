#ifndef DISPLAY_H
#define DISPLAY_H
#include "qcustomplot.h"
#include <QMainWindow>

#include "edflib.h"

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

private:
    int duration;
    QTimer* playBackTimer = new QTimer(this);
    void setupDisplayData(QCustomPlot *customPlot);
    Ui::Display *ui;
};

#endif // DISPLAY_H

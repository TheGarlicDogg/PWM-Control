#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{

    ui->setupUi(this);
    setupDisplayData(ui->customPlot);
    setWindowTitle("Отображение ЭЭГ");
    statusBar()->clearMessage();
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);
    connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel(QWheelEvent*)));
    ui->customPlot->setInteractions(QCP::iRangeZoom);
    ui->customPlot->replot();
    ui->statusBar->hide();
}

Display::~Display()
{
    delete ui;
}

void Display::setupDisplayData(QCustomPlot *customPlot)
{
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  displayData();
}

void Display::displayData()
{
    int i,
        hdl,
        channel,
        n,
        samples_in_channel;
    double* buf;
    edflib_hdr_t hdr;
    channel = 1;
    if (edfopen_file_readonly("EdfFiles/Subj 2 Test After.edf", &hdr, EDFLIB_READ_ALL_ANNOTATIONS))
    {
        switch (hdr.filetype)
        {
        case EDFLIB_MALLOC_ERROR: qDebug() << "\nmalloc error\n\n";
            break;
        case EDFLIB_NO_SUCH_FILE_OR_DIRECTORY: qDebug() << "\ncannot open file, no such file or directory\n\n";
            break;
        case EDFLIB_FILE_CONTAINS_FORMAT_ERRORS: qDebug() << "\nthe file is not EDF(+) or BDF(+) compliant\n"
            "(it contains format errors)\n\n";
            break;
        case EDFLIB_MAXFILES_REACHED: qDebug() << "\nto many files opened\n\n";
            break;
        case EDFLIB_FILE_READ_ERROR: qDebug() << "\na read error occurred\n\n";
            break;
        case EDFLIB_FILE_ALREADY_OPENED: qDebug() << "\nfile has already been opened\n\n";
            break;
        default: qDebug() << "\nunknown error\n\n";
            break;
        }

        return;
    }
    hdl = hdr.handle;

    samples_in_channel = hdr.signalparam[channel].smp_in_file;
    if (channel > (hdr.edfsignals))
    {
        printf("\nerror: file has %i signals and you selected signal %i\n\n", hdr.edfsignals, channel);
        edfclose_file(hdl);
        return;
    }

    channel--;
    ui->customPlot->yAxis->setRange(hdr.signalparam[channel].phys_min-10, hdr.signalparam[channel].phys_max+10);
    ui->customPlot->replot();


    edflib_annotation_t annot;


    for (i = 0; i < hdr.annotations_in_file; i++)
    {
        if (edf_get_annotation(hdl, i, &annot))
        {
            printf("\nerror: edf_get_annotations()\n");
            edfclose_file(hdl);
            return;
        }
        else
        {
#ifdef WIN32
            printf("annotation: onset is %I64d    duration is %s    description is %s\n",
                annot.onset / EDFLIB_TIME_DIMENSION,
                annot.duration,
                annot.annotation);
#else
            printf("annotation: onset is %lli.%07lli sec    duration is %s    description is \"%s\"\n",
                annot.onset / EDFLIB_TIME_DIMENSION,
                annot.onset % EDFLIB_TIME_DIMENSION,
                annot.duration,
                annot.annotation);
#endif
        }
    }

    buf = (double*)malloc(sizeof(double[samples_in_channel]));
    if (buf == NULL)
    {
        printf("\nmalloc error\n");
        edfclose_file(hdl);
        return;
    }

    int x = 0; /* start reading x seconds from start of file */

    edfseek(hdl, channel, (long long)((((double)x) / ((double)hdr.file_duration / (double)EDFLIB_TIME_DIMENSION)) * ((double)hdr.signalparam[channel].smp_in_file)), EDFSEEK_SET);

    n = edfread_physical_samples(hdl, channel, samples_in_channel, buf);

    if (n == (-1))
    {
        printf("\nerror: edf_read_physical_samples()\n");
        edfclose_file(hdl);
        free(buf);
        return;
    }

    printf("\nread %i samples, started at %i seconds from start of file:\n\n", n, x);
     // time elapsed since start, in seconds
    ui->customPlot->addGraph();
    ui->customPlot->replot();
    double key = 0;
    double shift = 1/(((double)hdr.signalparam[channel].smp_in_datarecord / (double)hdr.datarecord_duration) * EDFLIB_TIME_DIMENSION);
    for (i = 0; i < n; i++)
    {
        key += shift;
        ui->customPlot->graph()->addData(key, buf[i]);
        //qDebug() << buf[i];
    }
    //ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
    connect(playBackTimer, SIGNAL(timeout()), this, SLOT(PlaybackStep()));
    duration = hdr.file_duration/10000000;
    ui->timeSlider->setRange(0,duration*1000-8000);
    edfclose_file(hdl);
    free(buf);
}
void Display::on_PlayButton_clicked()
{
    playBackTimer->start(16);
    PlaybackStep();

}
void Display::on_StopButton_clicked()
{
    playBackTimer->stop();

}
void Display::PlaybackStep(){
    ui->customPlot->xAxis->moveRange(0.016);
    ui->customPlot->replot();
    ui->timeSlider->setValue(ui->timeSlider->value()+16);
}
void Display::on_MoveLeftButton_clicked()
{
    ui->customPlot->xAxis->moveRange(-1);
    ui->customPlot->replot();
    ui->timeSlider->setValue(ui->timeSlider->value()-1000);
}

void Display::on_MoveRightButton_clicked()
{
    ui->customPlot->xAxis->moveRange(1);
    ui->customPlot->replot();
    ui->timeSlider->setValue(ui->timeSlider->value()+1000);
}
void Display::mouseWheel(QWheelEvent * event)
{
    if( QApplication::keyboardModifiers() == Qt::ControlModifier ) {
        ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);
    }else{
        ui->customPlot->axisRect()->setRangeZoom(nullptr);
        if(event->angleDelta().y()>0){
            ui->customPlot->xAxis->moveRange(-1);
            ui->customPlot->replot();
            ui->timeSlider->setValue(ui->timeSlider->value()-1000);
        }
        else{
            ui->customPlot->xAxis->moveRange(1);
            ui->customPlot->replot();
            ui->timeSlider->setValue(ui->timeSlider->value()+1000);
        }
    }
}


void Display::on_timeSlider_sliderMoved(int position)
{
   ui->customPlot->xAxis->setRange(float(position)/1000, 8, Qt::AlignLeft);
   ui->customPlot->replot();
}

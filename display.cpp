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
    delete playBackTimer;
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
    int hdl,

        samples_in_channel;

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

    samples_in_channel = hdr.signalparam[0].smp_in_file;

    for(int i = 0 ;i<hdr.edfsignals; i++){
        ui->allSignalsList->addItem(hdr.signalparam[i].label);
        channelToLabel.insert(i,hdr.signalparam[i].label);
    }

    shift = 1/(((double)hdr.signalparam[0].smp_in_file / (double)hdr.file_duration) * EDFLIB_TIME_DIMENSION);

    connect(playBackTimer, SIGNAL(timeout()), this, SLOT(PlaybackStep()));
    duration = hdr.file_duration/10000000;
    ui->timeSlider->setRange(0,duration*1000-8000);
    ui->customPlot->setBackground(QColor(64, 64, 64));
    ui->customPlot->xAxis->setTickLabelColor(QColor(255,255,255));
    ui->customPlot->yAxis->setTickLabelColor(QColor(255,255,255));
    ui->customPlot->xAxis->setLabelColor(QColor(255,255,255));
    ui->customPlot->yAxis->setLabelColor(QColor(255,255,255));
    ui->customPlot->replot();
    edfclose_file(0);
    colors.insert(0, QColor(255,255,0));
    colors.insert(1, QColor(0,255,0));
    colors.insert(2, QColor(255,0,0));
    colors.insert(3, QColor(0,255,255));
    colors.insert(4, QColor(255,0,255));
    colors.insert(5, QColor(204,204,255));

}
void Display::on_PlayButton_clicked()
{
    playBackTimer->start(8);
    PlaybackStep();

}
void Display::on_StopButton_clicked()
{
    playBackTimer->stop();

}
void Display::PlaybackStep(){
    ui->customPlot->xAxis->moveRange(0.008);
    ui->customPlot->replot();
    ui->timeSlider->setValue(ui->timeSlider->value()+8);
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
    }else if(QApplication::keyboardModifiers() == Qt::ShiftModifier){
        ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    } else{
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

void Display::on_addSignalsButton_clicked()
{
  QList<int> selectedRows;
  for(int i = 0; i < ui->allSignalsList->selectedItems().size(); i++){
    selectedRows.append(ui->allSignalsList->row(ui->allSignalsList->selectedItems()[i]));
  }
  for(int i = 0; i < ui->selectedSignalsList->count(); i++){
    selectedRows.append(channelToLabel.key(ui->selectedSignalsList->item(i)->text()));
  }
  std::sort(selectedRows.begin(), selectedRows.end());
  selectedRows.erase(std::unique(selectedRows.begin(), selectedRows.end()), selectedRows.end());
  ui->selectedSignalsList->clear();
  for(int i = 0; i < selectedRows.size(); i++){
    ui->selectedSignalsList->addItem(ui->allSignalsList->item(selectedRows[i])->text());
  }
  ui->allSignalsList->clearSelection();
}

void Display::on_removeSignalsButton_clicked()
{
    int n =  ui->selectedSignalsList->selectedItems().size();
    QList<QListWidgetItem*> itemsToDelete = ui->selectedSignalsList->selectedItems();

    for (int i = 0; i < n; i++){
        ui->selectedSignalsList->takeItem(ui->selectedSignalsList->row(itemsToDelete[i]));

    }
    ui->selectedSignalsList->clearSelection();
}

void Display::on_submitSignalsButton_clicked()
{
    ui->customPlot->clearGraphs();
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

    int samples_in_channel = hdr.signalparam[0].smp_in_file;
    double* buf;
    buf = (double*)malloc(sizeof(double[samples_in_channel]));
    if (buf == NULL)
    {
        printf("\nmalloc error\n");
        edfclose_file(0);
        return;
    }
    int channel;
    int x = 0; /* start reading x seconds from start of file */
    int gap = 70;
    //double physMinRange, physMaxRange;


    QPen pen;
    for(int j = 0; j < ui->selectedSignalsList->count(); j++){

        channel = channelToLabel.key(ui->selectedSignalsList->item(j)->text());
        pen.setColor(colors.value(ui->customPlot->graphCount()%6));
        //pen.setColor(QColor((175+(ui->customPlot->graphCount()%9*70))%256, (10+(ui->customPlot->graphCount()%9*80))%256, (90+(ui->customPlot->graphCount()%9*60))%256));
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setPen(pen);
        edfseek(0, 0, (long long)((((double)x) / ((double)hdr.file_duration / (double)EDFLIB_TIME_DIMENSION)) * ((double)hdr.signalparam[channel].smp_in_file)), EDFSEEK_SET);

        int n = edfread_physical_samples(0, channel, samples_in_channel, buf);

        double key = 0;
        /*if (j == 0){
            physMaxRange = -10000;
            for(int i = 0; i < n; i++){
                if(buf[i]>physMaxRange) physMaxRange = buf[i];
            }
        }
        if (j == ui->selectedSignalsList->count()-1){
            physMinRange = 10000;
            for(int i = 0; i < n; i++){
                if(buf[i]<physMinRange) physMinRange = buf[i];
            }
        }*/
        for (int i = 0; i < n; i++)
        {
            key += shift;
            ui->customPlot->graph()->addData(key, buf[i]+gap*((ui->selectedSignalsList->count()-1)/2-j));
        }
    }
    ui->selectedSignalsList->clearSelection();
    //ui->customPlot->yAxis->setRange(gap*((ui->selectedSignalsList->count()-1)/2-(ui->selectedSignalsList->count()-1))+physMinRange-3, gap*((ui->selectedSignalsList->count()-1)/2)+physMaxRange+3);
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
    free(buf);
    edfclose_file(0);
}

void Display::on_ZoomButton_clicked()
{
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
}

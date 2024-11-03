#include "display.h"
#include "ui_display.h"
#include <QPushButton>
#include <QTimer>

// does not check if compared file has different signals

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
Display::Display(QString fileadr, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::Display)
{
    filename = fileadr;
    setWindowTitle("Отображение ЭЭГ");
    ui->setupUi(this);
    statusBar()->clearMessage();
    ui->statusBar->hide();

    setupColors();
    setupDisplayData(ui->customPlot);
    displaySignals();
    ui->customPlot->setInteractions(QCP::iRangeZoom);
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);

    ui->plotsFrame->layout()->setMargin(0);
    addPlotButton = new QPushButton("+", ui->plotsFrame);
    addPlotButton->setGeometry(0,0,30,30);
    addPlotButton->raise();

    connect(addPlotButton, &QAbstractButton::clicked, this, &Display::addPlot);
    connect(playBackTimer, &QTimer::timeout, this, &Display::PlaybackStep);
    connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheelMain(QWheelEvent*)));
    ui->customPlot->replot();
}
Display::~Display()
{
    delete comparePlot;
    delete addPlotButton;
    delete playBackTimer;
    delete ui;
}

void Display::setupDisplayData(QCustomPlot *customPlot)
{
  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->setBackground(QColor(64, 64, 64));
  customPlot->xAxis->setTickLabelColor(QColor(255,255,255));
  customPlot->yAxis->setTickLabelColor(QColor(255,255,255));
  customPlot->xAxis->setLabelColor(QColor(255,255,255));
  customPlot->yAxis->setLabelColor(QColor(255,255,255));
  customPlot->replot();
}
void Display::displaySignals()
{
    if (edfopen_file_readonly(filename.toStdString().c_str(), &hdr, EDFLIB_READ_ALL_ANNOTATIONS))
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
    ui->timeSlider->setRange(0,hdr.file_duration/10000000*1000-8000);
    for(int i = 0 ;i<hdr.edfsignals; i++){
        ui->allSignalsList->addItem(hdr.signalparam[i].label);
        channelToLabel.insert(i,hdr.signalparam[i].label);
    }

    edfclose_file(0);

}
void Display::setupColors(){
    colors.insert(0, QColor(255,255,0));
    colors.insert(1, QColor(0,255,0));
    colors.insert(2, QColor(255,0,0));
    colors.insert(3, QColor(0,255,255));
    colors.insert(4, QColor(255,0,255));
    colors.insert(5, QColor(204,204,255));
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
    if (edfopen_file_readonly(filename.toStdString().c_str(), &hdr, EDFLIB_READ_ALL_ANNOTATIONS))
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
    int handle = edflib_get_handle(0);
    if(isComparePlotActive){
        comparePlot->clearGraphs();
        if (edfopen_file_readonly(compfilename.toStdString().c_str(), &hdr2, EDFLIB_READ_ALL_ANNOTATIONS))
        {
        switch (hdr2.filetype)
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
    }
    int handle2 = edflib_get_handle(1);
    double shift = 1/(((double)hdr.signalparam[0].smp_in_file / (double)hdr.file_duration) * EDFLIB_TIME_DIMENSION);
    int samples_in_channel = hdr.signalparam[0].smp_in_file;
    double* buf,* buf2;
    buf = (double*)malloc(sizeof(double[samples_in_channel]));
    if (buf == NULL)
    {
        printf("\nmalloc error\n");
        edfclose_file(handle);
        return;
    }
    buf2 = (double*)malloc(sizeof(double[samples_in_channel]));
    if (buf2 == NULL)
    {
        printf("\nmalloc error\n");
        edfclose_file(handle2);
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
        if(isComparePlotActive){
            comparePlot->addGraph();
            comparePlot->graph()->setPen(pen);
            edfseek(0, 0, (long long)((((double)x) / ((double)hdr2.file_duration / (double)EDFLIB_TIME_DIMENSION)) * ((double)hdr2.signalparam[channel].smp_in_file)), EDFSEEK_SET);
        }
        int n, n2;
        n = edfread_physical_samples(handle, channel, samples_in_channel, buf);
        if(isComparePlotActive){
            n2 = edfread_physical_samples(handle2, channel, samples_in_channel, buf2);
            n = std::min(n, n2);
        }
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
            if(isComparePlotActive) comparePlot->graph()->addData(key, buf2[i]+gap*((ui->selectedSignalsList->count()-1)/2-j));
        }
    }
    ui->selectedSignalsList->clearSelection();
    //ui->customPlot->yAxis->setRange(gap*((ui->selectedSignalsList->count()-1)/2-(ui->selectedSignalsList->count()-1))+physMinRange-3, gap*((ui->selectedSignalsList->count()-1)/2)+physMaxRange+3);
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
    if(isComparePlotActive){
        comparePlot->yAxis->rescale();
        comparePlot->replot();
    }
    free(buf);
    free(buf2);
    edfclose_file(handle);
    edfclose_file(handle2);
}

void Display::on_PlayButton_clicked()
{
    playBackTimer->start(8);
    PlaybackStep();

}
void Display::PlaybackStep(){
    ui->customPlot->xAxis->moveRange(0.008);
    ui->customPlot->replot();
    if(isComparePlotActive){
        comparePlot->xAxis->moveRange(0.008);
        comparePlot->replot();
    }
    ui->timeSlider->setValue(ui->timeSlider->value()+8);
}
void Display::on_StopButton_clicked()
{
    playBackTimer->stop();

}
void Display::on_MoveLeftButton_clicked()
{
    ui->customPlot->xAxis->moveRange(-1);
    ui->customPlot->replot();
    if(isComparePlotActive){
        comparePlot->xAxis->moveRange(-1);
        comparePlot->replot();
    }
    ui->timeSlider->setValue(ui->timeSlider->value()-1000);
}

void Display::on_MoveRightButton_clicked()
{
    ui->customPlot->xAxis->moveRange(1);
    ui->customPlot->replot();
    if(isComparePlotActive){
        comparePlot->xAxis->moveRange(1);
        comparePlot->replot();
    }
    ui->timeSlider->setValue(ui->timeSlider->value()+1000);
}

void Display::on_timeSlider_sliderMoved(int position)
{
   ui->customPlot->xAxis->setRange(float(position)/1000, 8, Qt::AlignLeft);
   ui->customPlot->replot();
   if(isComparePlotActive){
       comparePlot->xAxis->setRange(float(position)/1000, 8, Qt::AlignLeft);
       comparePlot->replot();
   }
}

void Display::on_ZoomButton_clicked()
{
    ui->customPlot->yAxis->rescale();
    ui->customPlot->replot();
    if(isComparePlotActive){
        comparePlot->yAxis->rescale();
        comparePlot->replot();
    }
}

void Display::on_pushButton_clicked()
{
    QMessageBox::information(this, "Управление", "Колесо мыши - перемещение по оси X<br>Колесо мыши + Ctrl - приближение/отдаление по горизонтальной оси<br>Колесо мыши + Shift - приближение/отдаление по обеим осям");
}


void Display::updateButtonPosition()
{
    addPlotButton->setGeometry({ui->plotsFrame->geometry().width() - 30,
                                   0,
                                   addPlotButton->geometry().width(),
                                addPlotButton->geometry().height()});
}
void Display::addPlot()
{
    if(isComparePlotActive){
        ui->plotsFrame->layout()->removeWidget(comparePlot);
        comparePlot->hide();
        addPlotButton->setText("+");
        isComparePlotActive = false;
        delete comparePlot;
    }
    else{
        compfilename = QFileDialog::getOpenFileName(this, tr("Выберите файл ЭЭГ"),
                                                        nullptr,
                                                        tr("Файлы ЭЭГ (*.edf *.bdf)"));
        if (compfilename == ""){
            QMessageBox::warning(this, "Ошибка", "Некорректный путь к файлу.");
            return;
        }
        for(int i = 0; i < compfilename.length(); i++){
            if(compfilename[i].unicode()<=1103 && compfilename[i].unicode()>=1040){
                QMessageBox::warning(this, "Ошибка", "В пути содержится кириллица. Измените путь к файлу.");
                return;
            }
        }
        comparePlot = new QCustomPlot();
        comparePlot->setMinimumSize(550, 245);
        setupDisplayData(comparePlot);
        comparePlot->setInteractions(QCP::iRangeZoom);
        comparePlot->axisRect()->setRangeZoom(Qt::Horizontal);
        connect(comparePlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheelCompare(QWheelEvent*)));
        ui->plotsFrame->layout()->addWidget(comparePlot);
        QLayoutItem* item = ui->plotsFrame->layout()->takeAt(0);
        ui->plotsFrame->layout()->addItem(item);
        addPlotButton->raise();
        addPlotButton->setText("x");
        isComparePlotActive = true;
        if(ui->customPlot->graphCount()!=0){
            on_submitSignalsButton_clicked();
            replotComparePlotSlot();
        }

    }



}
void Display::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    // We update the button positions for each resize event of the main window
    updateButtonPosition();
}
void Display::mouseWheelMain(QWheelEvent * event){
    mouseWheel(event, ui->customPlot);
    if(isComparePlotActive) QTimer::singleShot(25, this, &Display::replotComparePlotSlot);
}
void Display::mouseWheelCompare(QWheelEvent * event){
    mouseWheel(event, comparePlot);
    QTimer::singleShot(25, this, &Display::replotMainPlotSlot);
}
void Display::mouseWheel(QWheelEvent * event, QCustomPlot* plot)
{
    if( QApplication::keyboardModifiers() == Qt::ControlModifier ) {
        plot->axisRect()->setRangeZoom(Qt::Horizontal);
    }else if(QApplication::keyboardModifiers() == Qt::ShiftModifier){
        plot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    } else{
        ui->customPlot->axisRect()->setRangeZoom(nullptr);
        if(event->angleDelta().y()>0){
            plot->xAxis->moveRange(-1);
            plot->replot();
            ui->timeSlider->setValue(ui->timeSlider->value()-1000);
        }
        else{
            plot->xAxis->moveRange(1);
            plot->replot();
            ui->timeSlider->setValue(ui->timeSlider->value()+1000);
        }
    }
}
void Display::replotMainPlotSlot()
{
    ui->customPlot->xAxis->setRange(comparePlot->xAxis->range());
    ui->customPlot->yAxis->setRange(comparePlot->yAxis->range());
    ui->customPlot->replot();
}
void Display::replotComparePlotSlot()
{
    comparePlot->xAxis->setRange(ui->customPlot->xAxis->range());
    comparePlot->yAxis->setRange(ui->customPlot->yAxis->range());
    comparePlot->replot();
}

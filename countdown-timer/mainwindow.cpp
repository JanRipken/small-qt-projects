#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    timer(new QTimer(this)),
    remainingTime(0)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked() {
    int minutes = ui->spinMin->value();
    int seconds = ui->spinSek->value();
    remainingTime = minutes * 60 + seconds;
    timer->start(1000); // 1-second interval
}

void MainWindow::on_stopButton_clicked() {
    timer->stop();
}

void MainWindow::updateTimer() {
    if (remainingTime > 0) {
        --remainingTime;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        ui->labelTime->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    } else {
        timer->stop();
    }
}

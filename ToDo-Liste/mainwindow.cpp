#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QString task = ui->taskInput->text();
    if (!task.isEmpty()) {
        TaskWidget *taskWidget = new TaskWidget(task, this);
        ui->taskLayout->addWidget(taskWidget);

        connect(taskWidget, &TaskWidget::removeRequested, this, &MainWindow::removeTask);
        connect(taskWidget, &TaskWidget::completeRequested, this, &MainWindow::completeTask);

        ui->taskInput->clear();
    }
}

void MainWindow::removeTask(TaskWidget *widget)
{
    ui->taskLayout->removeWidget(widget);
    delete widget;
}

void MainWindow::completeTask(TaskWidget *widget)
{
    widget->setTaskText(widget->taskText() + " (done)");
}

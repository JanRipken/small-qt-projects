#include "TaskWidget.h"

TaskWidget::TaskWidget(const QString &taskText, QWidget *parent)
    : QWidget(parent), taskLabel(new QLabel(taskText, this)),
    removeButton(new QPushButton("Remove", this)),
    completeButton(new QPushButton("Complete", this))
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(taskLabel);
    layout->addWidget(completeButton);
    layout->addWidget(removeButton);

    setLayout(layout);

    connect(removeButton, &QPushButton::clicked, this, &TaskWidget::onRemoveButtonClicked);
    connect(completeButton, &QPushButton::clicked, this, &TaskWidget::onCompleteButtonClicked);
}

void TaskWidget::setTaskText(const QString &text)
{
    taskLabel->setText(text);
}

QString TaskWidget::taskText() const
{
    return taskLabel->text();
}

void TaskWidget::onRemoveButtonClicked()
{
    emit removeRequested(this);
}

void TaskWidget::onCompleteButtonClicked()
{
    emit completeRequested(this);
}

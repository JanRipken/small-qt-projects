#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWidget(const QString &taskText, QWidget *parent = nullptr);

    void setTaskText(const QString &text);
    QString taskText() const;

signals:
    void removeRequested(TaskWidget *widget);
    void completeRequested(TaskWidget *widget);

private slots:
    void onRemoveButtonClicked();
    void onCompleteButtonClicked();

private:
    QLabel *taskLabel;
    QPushButton *removeButton;
    QPushButton *completeButton;
};

#endif // TASKWIDGET_H

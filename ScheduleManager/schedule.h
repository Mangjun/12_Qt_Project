#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>
#include "cschedule.h"
#include "widgetmanager.h"

class Date;

namespace Ui {
class Schedule;
}

class Schedule : public QWidget
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();
    void updateSchedule(CSchedule schedule);

private:
    Ui::Schedule *ui;
    void gotoDate();

private slots:
    void back();
    void left();
    void right();
    void clickedDeleteBtn();
    void clickedSaveBtn();
};

#endif // SCHEDULE_H

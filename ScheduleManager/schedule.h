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
    void updateSchedule(CSchedule sc);
    void deleteSchedule(CSchedule sc);

private:
    Ui::Schedule *ui;
    CSchedule csInfo;

    void gotoDate();

signals:
    void sendDateInfo(QDate date);

private slots:
    /* 화면 간의 통신 */
    void receiveScheduleInfo(const CSchedule& sc);

    /* 화면 이벤트 처리 */
    void back();
    void clickedDeleteBtn();
    void clickedSaveBtn();
};

#endif // SCHEDULE_H

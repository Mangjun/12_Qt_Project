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

private:
    Ui::Schedule *ui;
    CSchedule csInfo;

    /* 화면 이동 */
    void gotoDate();

    /* 비즈니스 로직 */
    void updateSchedule(CSchedule sc);
    void deleteSchedule(CSchedule sc);

signals:
    /* 다른 위젯에게 정보 보내기 */
    void sendDateInfo(QDate date);

private slots:
    /* 다른 위젯으로부터 정보 받기 */
    void receiveScheduleInfo(const CSchedule& sc);

    /* 이벤트 처리 */
    void back();
    void clickedDeleteBtn();
    void clickedSaveBtn();
};

#endif // SCHEDULE_H

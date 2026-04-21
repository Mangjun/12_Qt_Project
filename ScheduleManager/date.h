#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include <QStringListModel>
#include "widgetmanager.h"
#include "cschedule.h"

namespace Ui {
class Date;
}

class Date : public QWidget
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

private:
    Ui::Date *ui;
    QDate date;                             // 날짜 정보
    QList<CSchedule> currentSchedules;      // 현재 날짜 일정 리스트
    QStringListModel *model;

    void updateUI();

    /* 화면 이동 */
    void gotoCalendar();
    void gotoSchedule();

signals:
    /* 다른 위젯에게 정보 보내기 */
    void sendDateInfo(QDate date);
    void sendScheduleInfo(const CSchedule& sc);

private slots:
    /* 다른 위젯으로부터 정보 받기 */
    void receiveDateInfo(QDate date);

    /* 이벤트 처리 */
    void back();    // 뒤로 가기
    void left();    // 전 날짜 이동
    void right();   // 다음 날짜 이동
    void clickedSchedule(const QModelIndex& index);     // 일정 클릭
    void gotoAddSchedule();     // 일정 추가 다이얼로그 이동
};

#endif // DATE_H

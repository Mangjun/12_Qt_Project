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
    /**
     * @brief gotoDate 날짜 화면으로 이동
     */
    void gotoDate();

    /* 비즈니스 로직 */
    /**
     * @brief updateSchedule 일정 내용 수정
     * @param sc             수정할 일정 정보
     */
    void updateSchedule(const CSchedule& sc);

    /**
     * @brief deleteSchedule 일정 삭제
     * @param sc             삭제할 일정 정보
     */
    void deleteSchedule(const CSchedule& sc);

signals:
    /* 다른 위젯에게 정보 보내기 */
    void sendDateInfo(const QDate& date);

private slots:
    /* 다른 위젯으로부터 정보 받기 */
    void receiveScheduleInfo(const CSchedule& sc);

    /* 이벤트 처리 */
    void back();                // 뒤로 가기 버튼 클릭
    void clickedDeleteBtn();    // 삭제 버튼 클릭
    void clickedSaveBtn();      // 수정 버튼 클릭
};

#endif // SCHEDULE_H

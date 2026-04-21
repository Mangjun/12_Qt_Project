#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QDialog>
#include <QDate>
#include "widgetmanager.h"
#include "cschedule.h"

namespace Ui {
class AddSchedule;
}

class AddSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit AddSchedule(QWidget *parent = nullptr);
    ~AddSchedule();
    /**
     * @brief setDate 날짜 화면에서 날짜 받아오기
     * @param date 보고 있는 날짜
     */
    void setDate(QDate date);

private:
    Ui::AddSchedule *ui;
    QDate date; // 설정할 날짜

    /**
     * @brief addSchedule 캐시에 일정 추가
     * @param schedule 일정 정보
     */
    void addSchedule(const CSchedule& scInfo);

private slots:
    /**
     * @brief clickedAcceptBtn 일정 추가 버튼 클릭 이벤트
     */
    void clickedAcceptBtn();
};

#endif // ADDSCHEDULE_H

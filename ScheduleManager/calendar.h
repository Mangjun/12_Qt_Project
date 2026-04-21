#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QListView>
#include "widgetmanager.h"
#include "date.h"
#include "schedule.h"
#include "cschedule.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calendar;
}
QT_END_NAMESPACE

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar() override;

private:
    Ui::Calendar *ui;
    QList<CSchedule> searchList;    // 검색한 일정 리스트
    QStringListModel *model;        // ListView에 담을 정보

    void updateUI();        // 정보 업데이트

    /* 위젯 이동 */
    void gotoDate();        // 날짜 화면으로 이동
    void gotoSchedule();    // 일정 화면으로 이동

    /* 비즈니스 로직 */
    void searchSchedule(QString title);     // 제목으로 일정 검색

signals:
    /* 다른 위젯에게 정보 보내기 */
    void sendDateInfo(QDate date);
    void sendScheduleInfo(const CSchedule& scInfo);

private slots:
    /* 다른 위젯으로부터 정보 받기 */
    void receiveDateInfo(QDate date);

    /* 이벤트 처리 */
    void clickedSearchBtn();        // 검색 버튼 클릭
    void clickedDate(QDate date);   // 날짜 클릭
    void clickedSchedule(const QModelIndex& index);// 검색한 일정 클릭
};
#endif // CALENDAR_H

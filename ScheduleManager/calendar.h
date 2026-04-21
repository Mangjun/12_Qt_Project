#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include "widgetmanager.h"
#include "date.h"
#include "schedule.h"
#include "cschedule.h"
#include <QListView>

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
    void searchSchedule(QString title);

signals:
    /* 화면 간의 통신 */
    void sendDateInfo(QDate date);
    void sendScheduleInfo(const CSchedule& sc);

private:
    Ui::Calendar *ui;
    void gotoDate();
    void gotoSchedule();

private slots:
    /* 화면 통신 처리 */
    void receiveDateInfo(QDate date);

    void clickedSearchBtn();
    void searchTextChanged();
    void clickedDate(QDate date);
    void clickedSchedule(int index);
};
#endif // CALENDAR_H

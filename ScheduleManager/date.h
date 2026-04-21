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

signals:
    /* 화면 간의 통신 */
    void sendDateInfo(QDate date);
    void sendScheduleInfo(const CSchedule& sc);

private:
    Ui::Date *ui;
    QDate date;
    QList<CSchedule> currentSchedules;
    QStringListModel *model;

    void gotoCalendar();
    void gotoSchedule();
    void updateUI();

private slots:
    /* 화면 간의 통신 */
    void receiveDateInfo(QDate date);

    /* 화면 이벤트 처리 */
    void back();
    void left();
    void right();
    void clickedSchedule(const QModelIndex& index);
    void gotoAddSchedule();
};

#endif // DATE_H

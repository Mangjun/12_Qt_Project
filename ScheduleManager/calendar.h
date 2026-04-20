#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include "widgetmanager.h"
#include "date.h"
#include "schedule.h"

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
    void dateInfo();
    void scheduleInfo(const Schedule& schedule);

private:
    Ui::Calendar *ui;
    void gotoDate();
    void gotoSchedule();

private slots:
    void searchTextChanged();
    void clickedDate();
    void clickedSchedule(int index);
};
#endif // CALENDAR_H

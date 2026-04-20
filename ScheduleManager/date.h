#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include "widgetmanager.h"

namespace Ui {
class Date;
}

class Date : public QWidget
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();
    void deleteSchedule(int index);

private:
    Ui::Date *ui;
    void gotoCalendar();
    void gotoSchedule();

private slots:
    void back();
    void left();
    void right();
    void clickedDate();
    void clickedSchedule(int index);
    void gotoAddSchedule();
};

#endif // DATE_H

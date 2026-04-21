#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QDialog>
#include <QDate>
#include "widgetmanager.h"
#include "cschedule.h"
#include "QDate"

namespace Ui {
class AddSchedule;
}

class AddSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit AddSchedule(QWidget *parent = nullptr);
    ~AddSchedule();
    void setDate(QDate date);

private:
    Ui::AddSchedule *ui;
    QDate date;

    void addSchedule(CSchedule& schedule);

private slots:
    void clickedAcceptBtn();
};

#endif // ADDSCHEDULE_H

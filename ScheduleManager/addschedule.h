#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QDialog>

namespace Ui {
class AddSchedule;
}

class AddSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit AddSchedule(QWidget *parent = nullptr);
    ~AddSchedule();

private:
    Ui::AddSchedule *ui;
};

#endif // ADDSCHEDULE_H

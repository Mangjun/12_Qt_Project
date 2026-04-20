#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>

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

private:
    Ui::Calendar *ui;

private slots:
    void searchTextChanged();
    void clickedDate();
    void clickedSchedule(int index);
};
#endif // CALENDAR_H

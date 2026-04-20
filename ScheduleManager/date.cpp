#include "date.h"
#include "ui_date.h"
#include "calendar.h"
#include "schedule.h"

Date::Date(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Date)
{
    ui->setupUi(this);
}

Date::~Date()
{
    delete ui;
}

/* 비즈니스 로직 */
void Date::deleteSchedule(int index)
{

}

/* 이벤트 처리 */
void Date::back()
{

}

void Date::left()
{


}

void Date::right()
{

}

void Date::clickedDate()
{

}

void Date::clickedSchedule(int index)
{

}

/* 화면 이동 처리 */
void Date::gotoAddSchedule()
{

}

void Date::gotoCalendar()
{
    Calendar* calendar = WidgetManager::instance().getCalendar();
    calendar->show();
    this->hide();
}

void Date::gotoSchedule()
{
    Schedule* schedule = WidgetManager::instance().getSchedule();
    schedule->show();
    this->hide();
}
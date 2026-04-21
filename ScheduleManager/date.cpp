#include "date.h"
#include "ui_date.h"
#include "calendar.h"
#include "schedule.h"
#include "addschedule.h"

Date::Date(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Date)
{
    ui->setupUi(this);
    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->addScheduleButton, SIGNAL(clicked(bool)), this, SLOT(gotoAddSchedule()));
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
    emit sendDateInfo(this->date);
    gotoCalendar();
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

void Date::receiveDateInfo(QDate date)
{
    this->date = date;
    ui->dateDisplayButton->setText(QString("%1년 %2월 %3일").arg(date.year()).arg(date.month()).arg(date.day()));
}

/* 화면 이동 처리 */
void Date::gotoAddSchedule()
{
    AddSchedule addSchedule;
    addSchedule.exec();
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
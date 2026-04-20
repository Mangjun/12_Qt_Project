#include "schedule.h"
#include "ui_schedule.h"
#include "date.h"

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}

/* 비즈니스 로직 */
void Schedule::updateSchedule(CSchedule schedule)
{

}

void Schedule::left()
{

}

void Schedule::right()
{

}

/* 이벤트 처리 */
void Schedule::back()
{
    gotoDate();
}

void Schedule::clickedDeleteBtn()
{

}

void Schedule::clickedSaveBtn()
{

}

void Schedule::gotoDate()
{
    Date* date = WidgetManager::instance().getDate();
    date->show();
    this->hide();
}
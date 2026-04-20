#include "calendar.h"
#include "./ui_calendar.h"

Calendar::Calendar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calendar)
{
    ui->setupUi(this);
}

Calendar::~Calendar()
{
    delete ui;
}

/* 로직 */
void Calendar::searchSchedule(QString title)
{

}

void Calendar::searchTextChanged()
{

}

/* 이벤트 처리 */
void Calendar::clickedDate()
{

}

void Calendar::clickedSchedule(int index)
{

}

/* 화면 이동 처리 */
void Calendar::gotoDate()
{
    Date* date = WidgetManager::instance().getDate();
    date->show();
    this->hide();
}

void Calendar::gotoSchedule()
{
    Schedule* schedule = WidgetManager::instance().getSchedule();
    schedule->show();
    this->hide();
}
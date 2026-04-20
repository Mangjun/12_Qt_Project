#include "date.h"
#include "ui_date.h"

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

void Date::deleteSchedule(int index)
{

}

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

void Date::gotoAddSchedule()
{

}
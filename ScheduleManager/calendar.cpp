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

void Calendar::searchSchedule(QString title)
{

}

void Calendar::searchTextChanged()
{

}

void Calendar::clickedDate()
{

}

void Calendar::clickedSchedule(int index)
{

}
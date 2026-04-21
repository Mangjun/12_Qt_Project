#include "calendar.h"
#include "./ui_calendar.h"

Calendar::Calendar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calendar)
{
    ui->setupUi(this);
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(clickedDate(QDate)));
    connect(ui->searchButton,SIGNAL(clicked(bool)),this,SLOT(clickedSearchBtn()));

}

Calendar::~Calendar()
{
    delete ui;
}

/* 로직 */
void Calendar::searchSchedule(QString title)
{
//리스트 뷰
}

/* 이벤트 처리 */
void Calendar::clickedSearchBtn()
{
    if(ui->searchBar->text().isEmpty())
    {
        ui->searchResults->hide();
        return;
    }
    ui->searchResults->show();
    ui->searchResults->setParent(this);
    ui->searchResults->raise();

    searchSchedule(ui->searchBar->text());
}

void Calendar::searchTextChanged()
{

}

void Calendar::clickedDate(QDate date)
{
    emit dateInfo(date);
    gotoDate();
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
#include "schedule.h"
#include "ui_schedule.h"
#include "date.h"

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(back()));
}

Schedule::~Schedule()
{
    delete ui;
}

/* 비즈니스 로직 */
void Schedule::updateSchedule(CSchedule schedule)
{

}

void Schedule::receiveScheduleInfo(const CSchedule& sc)
{
    QString title = sc.getTitle();
    QDate date = sc.getDate();
    QString detail = sc.getDetail();

    ui->titleEdit->setText(title);
    ui->dateEdit->setDate(date);
    ui->detailEdit->setText(detail);
}

/* 이벤트 처리 */
void Schedule::back()
{
    QDate date = ui->dateEdit->date();
    emit sendDateInfo(date);
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
#include "schedule.h"
#include "ui_schedule.h"
#include "date.h"

Schedule::Schedule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(clickedDeleteBtn()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(clickedSaveBtn()));
}

Schedule::~Schedule()
{
    delete ui;
}

/* 화면 이동 */
void Schedule::gotoDate()
{
    Date* date = WidgetManager::instance().getDate();
    date->show();
    this->hide();
}

/* 비즈니스 로직 */
void Schedule::updateSchedule(const CSchedule& sc)
{
    WidgetManager::instance().updateSchedule(sc);
}

void Schedule::deleteSchedule(const CSchedule& sc)
{
    WidgetManager::instance().deleteSchedule(sc);
}

/* 다른 위젯으로부터 정보 받기 */
void Schedule::receiveScheduleInfo(const CSchedule& sc)
{
    this->csInfo = sc;

    QString title = csInfo.getTitle();
    QDate date = csInfo.getDate();
    QString detail = csInfo.getDetail();

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
    QDate date = ui->dateEdit->date();

    deleteSchedule(this->csInfo);

    emit sendDateInfo(date);
    gotoDate();
}

void Schedule::clickedSaveBtn()
{
    QString title = ui->titleEdit->text();
    QDate date = ui->dateEdit->date();
    QString detail = ui->detailEdit->toPlainText();

    CSchedule newCs(title, date, detail);
    newCs.setId(csInfo.getId());

    updateSchedule(newCs);
}
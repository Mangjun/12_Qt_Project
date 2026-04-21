#include "addschedule.h"
#include "ui_addschedule.h"

AddSchedule::AddSchedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSchedule)
{
    ui->setupUi(this);
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(clickedAcceptBtn()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

AddSchedule::~AddSchedule()
{
    delete ui;
}

void AddSchedule::addSchedule(const CSchedule& schedule)
{
    /* 일정 추가 로직 */
    qDebug() << schedule.getTitle() << " " << schedule.getDate() << " " << schedule.getDetail();
    accept();
}

void AddSchedule::clickedAcceptBtn()
{
    QString title = ui->titleInput->text();
    QDate date = ui->dateInput->date();
    QString details = ui->dateInput->text();

    CSchedule newSchedule(title, date, details);
    addSchedule(newSchedule);
}
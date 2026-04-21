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

void AddSchedule::setDate(QDate date)
{
    this->date = date;
    ui->dateInput->setDate(date);
}

void AddSchedule::addSchedule(CSchedule& schedule)
{
    WidgetManager::instance().insertSchedule(schedule);
    accept();
}

void AddSchedule::clickedAcceptBtn()
{
    QString title = ui->titleInput->text();
    QDate date = ui->dateInput->date();
    QString details = ui->detailsInput->toPlainText();

    CSchedule newSchedule(title, date, details);
    addSchedule(newSchedule);
}
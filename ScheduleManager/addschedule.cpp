#include "addschedule.h"
#include "ui_addschedule.h"
#include "widgetmanager.h"

AddSchedule::AddSchedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSchedule)
{
    ui->setupUi(this);

    /* 이벤트 연결 */
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(clickedAcceptBtn())); // 추가 버튼
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));        // 삭제 버튼
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

void AddSchedule::addSchedule(const CSchedule& sc)
{
    WidgetManager::instance().insertSchedule(sc);
    accept();
}

void AddSchedule::clickedAcceptBtn()
{
    QString title = ui->titleInput->text();
    QDate date = ui->dateInput->date();
    QString details = ui->detailsInput->toPlainText();

    CSchedule newSc(title, date, details);
    addSchedule(newSc);
}
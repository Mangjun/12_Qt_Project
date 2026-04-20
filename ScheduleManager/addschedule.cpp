#include "addschedule.h"
#include "ui_addschedule.h"

AddSchedule::AddSchedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSchedule)
{
    ui->setupUi(this);
}

AddSchedule::~AddSchedule()
{
    delete ui;
}

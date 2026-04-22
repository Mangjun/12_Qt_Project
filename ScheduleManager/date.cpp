#include "date.h"
#include "ui_date.h"
#include "calendar.h"
#include "schedule.h"
#include "addschedule.h"

Date::Date(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Date)
{
    ui->setupUi(this);

    this->model = new QStringListModel(this);

    connect(ui->backButton, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->addScheduleButton, SIGNAL(clicked(bool)), this, SLOT(gotoAddSchedule()));
    connect(ui->prevDayButton, SIGNAL(clicked(bool)), this, SLOT(left()));
    connect(ui->nextDayButton, SIGNAL(clicked(bool)), this, SLOT(right()));
    connect(ui->scheduleListView, SIGNAL(clicked(QModelIndex)), this, SLOT(clickedSchedule(const QModelIndex&)));
}

Date::~Date()
{
    delete ui;
}

void Date::updateUI()
{
    QString dateStr = this->date.toString("yyyy년 MM월 dd일");
    ui->dateDisplayButton->setText(dateStr);

    this->currentSchedules = WidgetManager::instance().getSchedules(this->date);

    QStringList titleList;
    for(const CSchedule& s : this->currentSchedules) {
        titleList << s.getTitle();
    }

    this->model->setStringList(titleList);
    ui->scheduleListView->setModel(this->model);
}

/* 화면 이동 */
void Date::gotoCalendar()
{
    Calendar* calendar = WidgetManager::instance().getCalendar();
    calendar->show();
    this->hide();
}

void Date::gotoSchedule()
{
    Schedule* schedule = WidgetManager::instance().getSchedule();
    schedule->show();
    this->hide();
}

/* 다른 위젯으로부터 정보 받기 */
void Date::receiveDateInfo(const QDate& date)
{
    this->date = date;
    updateUI();
}

/* 이벤트 처리 */
void Date::back()
{
    emit sendDateInfo(this->date);
    gotoCalendar();
}

void Date::left()
{
    this->date = this->date.addDays(-1);
    updateUI();
}

void Date::right()
{
    this->date = this->date.addDays(1);
    updateUI();
}

void Date::clickedSchedule(const QModelIndex& index)
{
    int row = index.row();

    if (row >= 0 && row < currentSchedules.size()) {
        CSchedule selectedSchedule = currentSchedules.at(row);

        emit sendScheduleInfo(selectedSchedule);
        gotoSchedule();
    }
}

void Date::gotoAddSchedule()
{
    AddSchedule addSchedule;
    addSchedule.setDate(date);

    if (addSchedule.exec() == QDialog::Accepted) {
        updateUI();
    }
}


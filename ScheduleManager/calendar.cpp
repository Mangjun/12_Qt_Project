#include "calendar.h"
#include "./ui_calendar.h"

Calendar::Calendar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calendar)
{
    ui->setupUi(this);

    this->model = new QStringListModel(this);

    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this, SLOT(clickedDate(QDate)));
    connect(ui->searchButton,SIGNAL(clicked(bool)),this, SLOT(clickedSearchBtn()));
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::updateUI()
{
    QTextCharFormat format;
    format.setBackground(Qt::lightGray);
    format.setForeground(Qt::red);
    format.setFontWeight(QFont::Bold);

    QList<QDate> list = WidgetManager::instance().getDates();
    for (const auto& date : list)
    {
        ui->calendarWidget->setDateTextFormat(date, format);
    }
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

/* 비즈니스 로직 */
void Calendar::searchSchedule(QString title)
{
    this->searchList = WidgetManager::instance().searchSchedule(title);

    QStringList titleList;
    for(const CSchedule& s : this->searchList) {
        titleList << s.getTitle();
    }

    this->model->setStringList(titleList);
    ui->searchResults->setModel(this->model);
}

/* 다른 위젯으로부터 정보 받기 */
void Calendar::receiveDateInfo(QDate date)
{
    ui->calendarWidget->setSelectedDate(date);
    updateUI();
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

void Calendar::clickedDate(QDate date)
{
    emit sendDateInfo(date);
    gotoDate();
}

void Calendar::clickedSchedule(int index)
{

}




#include "calendar.h"
#include "./ui_calendar.h"

Calendar::Calendar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calendar)
{
    ui->setupUi(this);

    this->model = new QStringListModel(this);

    /* 이벤트 처리 */
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this, SLOT(clickedDate(const QDate&)));                   // 날짜 클릭
    connect(ui->searchButton,SIGNAL(clicked(bool)),this, SLOT(clickedSearchBtn()));                             // 검색 버튼 클릭
    connect(ui->searchResults,SIGNAL(clicked(QModelIndex)),this,SLOT(clickedSchedule(const QModelIndex&)));     // 일정 클릭
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::updateUI()
{
    ui->searchResults->hide();                                         // 검색 창 닫기
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat()); // 달력 초기화 -> 동작 안함

    QTextCharFormat format;
    format.setBackground(Qt::lightGray);
    format.setForeground(Qt::red);
    format.setFontWeight(QFont::Bold);

    QList<QDate> list = WidgetManager::instance().getDates();
    for (const auto& date : list)
    {
        ui->calendarWidget->setDateTextFormat(date, format);
    }

    ui->calendarWidget->update();
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
void Calendar::searchSchedule(const QString& title)
{
    this->searchList = WidgetManager::instance().searchSchedule(title);

    QStringList titleList;
    for(const CSchedule& s : this->searchList) {
        titleList << QString("%1 [%2]").arg(s.getDate().toString("yyyy-MM-dd")).arg(s.getTitle());
    }

    this->model->setStringList(titleList);
    ui->searchResults->setModel(this->model);
}

/* 다른 위젯으로부터 정보 받기 */
void Calendar::receiveDateInfo(const QDate& date)
{
    updateUI();
    ui->calendarWidget->setSelectedDate(date);
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

void Calendar::clickedDate(const QDate& date)
{
    emit sendDateInfo(date);
    gotoDate();
}

void Calendar::clickedSchedule(const QModelIndex& index)
{
    int row = index.row();

    if (row >= 0 && row < searchList.size()) {
        CSchedule selectedSchedule = searchList.at(row);

        emit sendScheduleInfo(selectedSchedule);
        gotoSchedule();
    }
}
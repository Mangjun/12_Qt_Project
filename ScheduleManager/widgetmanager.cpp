#include "widgetmanager.h"
#include "calendar.h"
#include "date.h"
#include "schedule.h"
#include "login.h"

int WidgetManager::scheduleNumber = 1;

WidgetManager::WidgetManager()
{
    loginPtr = new Login();
    calendarPtr = new Calendar();
    datePtr = new Date();
    schedulePtr = new Schedule();

    /* 화면 통신 처리 */
    connect(loginPtr, SIGNAL(loginSuccess(QDate)), calendarPtr, SLOT(receiveDateInfo(QDate)));

    connect(calendarPtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));
    connect(calendarPtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));

    connect(datePtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));
    connect(datePtr, SIGNAL(sendDateInfo(QDate)), calendarPtr, SLOT(receiveDateInfo(QDate)));

    connect(schedulePtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));
}

/* 화면 반환 */
Calendar* WidgetManager::getCalendar()
{
    return calendarPtr;
}

Date* WidgetManager::getDate()
{
    return datePtr;
}

Schedule* WidgetManager::getSchedule()
{
    return schedulePtr;
}

/* 유저 관리 */
const CUser& WidgetManager::getUserInfo() const
{
    return this->userInfo;
}

void WidgetManager::setUserInfo(const CUser& user)
{
    userInfo = user;
}

/* 일정 관리 */
void WidgetManager::updateCache(const QList<CSchedule>& vcs)
{
    for (const auto& schedule : vcs)
    {
        QDate date = schedule.getDate();

        this->cache[date].append(schedule);
    }
}

QList<QDate> WidgetManager::getDates()
{
    return this->cache.keys();
}

QList<CSchedule> WidgetManager::getSchedules(QDate date)
{
    return this->cache.value(date);
}

/* 일정 비즈니스 로직 */
void WidgetManager::insertSchedule(const CSchedule& cs)
{
    QDate date = cs.getDate();

    CSchedule newCs = cs;
    newCs.setId(scheduleNumber++);

    this->cache[date].append(newCs);
}

void WidgetManager::updateSchedule(CSchedule cs)
{
    QDate date = cs.getDate();
    QList<CSchedule>& list = this->cache[date];

    for (auto& oldSc : list)
    {
        if (oldSc.getId() == cs.getId())
        {
            oldSc = cs;
            break;
        }
    }
}

void WidgetManager::deleteSchedule(CSchedule cs)
{
    QDate date = cs.getDate();
    QList<CSchedule>& list = this->cache[date];

    int i = 0;
    for (auto& oldSc : list)
    {
        if (oldSc.getId() == cs.getId())
        {
            list.removeAt(i);
            break;
        }
    }

    if (list.isEmpty()) {
        this->cache.remove(date);
    }
}

QList<CSchedule> WidgetManager::searchSchedule(QString title)
{
    QList<CSchedule> temp;

    for (const auto& date : cache.keys())
    {
        for (const auto& sc : cache.value(date))
        {
            if (sc.getTitle().contains(title)) {
                temp.append(sc);
            }
        }
    }

    return temp;
}
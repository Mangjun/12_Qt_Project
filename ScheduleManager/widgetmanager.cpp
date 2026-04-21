#include "widgetmanager.h"
#include "calendar.h"
#include "date.h"
#include "schedule.h"

int WidgetManager::scheduleNumber = 1;

WidgetManager::WidgetManager()
{
    calendarPtr = new Calendar();
    datePtr = new Date();
    schedulePtr = new Schedule();

    /* 화면 통신 처리 */
    connect(calendarPtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));
    connect(calendarPtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));

    connect(datePtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));
    connect(datePtr, SIGNAL(sendDateInfo(QDate)), calendarPtr, SLOT(receiveDateInfo(QDate)));

    connect(schedulePtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));
}

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

const CUser& WidgetManager::getUserInfo() const
{
    return this->userInfo;
}

void WidgetManager::setUserInfo(const CUser& user)
{
    userInfo = user;
}

void WidgetManager::updateCache(QList<CSchedule> vcs)
{
    for (const auto& schedule : vcs)
    {
        QDate date = schedule.getDate();

        this->cache[date].append(schedule);
    }
}

QList<CSchedule> WidgetManager::getSchedules(QDate date)
{
    return this->cache.value(date);
}

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
    QList<CSchedule> list = this->cache[date];

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
    QList<CSchedule> list = this->cache[date];

    for (auto& oldSc : list)
    {

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
#include "widgetmanager.h"
#include "calendar.h"
#include "date.h"
#include "schedule.h"

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
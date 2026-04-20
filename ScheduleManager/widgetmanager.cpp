#include "widgetmanager.h"
#include "calendar.h"
#include "date.h"
#include "schedule.h"

WidgetManager::WidgetManager()
{
    calendarPtr = new Calendar();
    datePtr = new Date();
    schedulePtr = new Schedule();
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
#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QObject>
#include "cuser.h"

class Calendar;
class Date;
class Schedule;

class WidgetManager : public QObject
{
    Q_OBJECT
private:
    /**
     * @brief WidgetManager 싱글톤
     */
    WidgetManager();

    Calendar* calendarPtr;
    Date* datePtr;
    Schedule* schedulePtr;
    CUser userInfo;

public:
    /**
     * @brief 싱글톤 객체 반환
     * @return WidgetManager 인스턴스
     */
    static WidgetManager& instance()
    {
        static WidgetManager inst;
        return inst;
    }

    Calendar* getCalendar();
    Date* getDate();
    Schedule* getSchedule();
    const CUser& getUserInfo() const;
    void setUserInfo(const CUser& user);
};

#endif // WIDGETMANAGER_H

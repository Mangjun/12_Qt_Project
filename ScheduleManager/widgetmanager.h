#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QObject>
#include <QList>

#include "cuser.h"
#include "cschedule.h"

class Login;
class Calendar;
class Date;
class Schedule;

class WidgetManager : public QObject
{
    Q_OBJECT
private:
    WidgetManager();

    Login* loginPtr;                        // 로그인 화면
    Calendar* calendarPtr;                  // 캘린더 화면
    Date* datePtr;                          // 날짜 화면
    Schedule* schedulePtr;                  // 일정 화면
    CUser userInfo;                         // 유저 정보
    QMap<QDate, QList<CSchedule>> cache;    // 일정 정보

    static int scheduleNumber;              // 일정 식별자

public:
    static WidgetManager& instance()
    {
        static WidgetManager inst;
        return inst;
    }

    /* 화면 반환 */
    Calendar* getCalendar();
    Date* getDate();
    Schedule* getSchedule();

    /* 회원 관리 */
    const CUser& getUserInfo() const;
    void setUserInfo(const CUser& user);

    /* 일정 관리 */
    void updateCache(const QList<CSchedule>& vcs);
    QList<QDate> getDates();
    QList<CSchedule> getSchedules(QDate date);

    /* 일정 비즈니스 로직 */
    void insertSchedule(const CSchedule& cs);
    void updateSchedule(CSchedule cs);
    void deleteSchedule(CSchedule cs);
    QList<CSchedule> searchSchedule(QString title);
};

#endif // WIDGETMANAGER_H

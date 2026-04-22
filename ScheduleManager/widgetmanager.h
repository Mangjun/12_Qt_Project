#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QCoreApplication>
#include <QObject>
#include <QMap>
#include <QDate>

#include "cuser.h"
#include "cschedule.h"

class Login;
class Calendar;
class Date;
class Schedule;
class DataManager;

class WidgetManager : public QObject
{
    Q_OBJECT
private:
    WidgetManager();
    ~WidgetManager();

    Login* loginPtr;
    Calendar* calendarPtr;
    Date* datePtr;
    Schedule* schedulePtr;

    CUser userInfo;                         // 현재 로그인한 유저
    QMap<QDate, QList<CSchedule>> cache;    // UI용 고속 캐시

    DataManager* dataManager;               // 데이터 저장소 인터페이스

public:
    static WidgetManager& instance() {
        static WidgetManager inst;
        return inst;
    }

    static QString getBasePath() {
        return QCoreApplication::applicationDirPath() + "/data";
    }

    /* 화면 반환 */
    Calendar* getCalendar() const;
    Date* getDate() const;
    Schedule* getSchedule() const;

    /* 유저 및 인증 로직 */
    bool login(const CUser& user);
    bool signUp(const CUser& user);
    const CUser& getUserInfo() const;
    void setUserInfo(const CUser& user);

    /* 일정 관리 및 캐시 동기화 */
    void loadSchedules();
    QList<QDate> getDates();
    QList<CSchedule> getSchedules(const QDate& date);

    /* 일정 비즈니스 로직 */
    void insertSchedule(const CSchedule& sc);
    void updateSchedule(const QDate& oldDate, const CSchedule& sc);
    void deleteSchedule(const int scheduleId);
    QList<CSchedule> searchSchedule(const QString& title);
};

#endif // WIDGETMANAGER_H

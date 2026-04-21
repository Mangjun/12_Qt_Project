#include "widgetmanager.h"
#include "calendar.h"
#include "date.h"
#include "schedule.h"
#include "login.h"
#include "datamanager.h"
#include "jsondatamanager.h"
// #include "memorydatamanager.h"

WidgetManager::WidgetManager()
{
    dataManager = new JsonDataManager();

    loginPtr = new Login();
    calendarPtr = new Calendar();
    datePtr = new Date();
    schedulePtr = new Schedule();

    /* 화면 통신 처리 */
    connect(loginPtr, SIGNAL(loginSuccess(QDate)), calendarPtr, SLOT(receiveDateInfo(QDate)));                                      // 로그인 -> 캘린더
    connect(calendarPtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));                                       // 캘린더 -> 날짜
    connect(calendarPtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));     // 캘린더 -> 일정
    connect(datePtr, SIGNAL(sendScheduleInfo(const CSchedule&)), schedulePtr, SLOT(receiveScheduleInfo(const CSchedule&)));         // 날짜 -> 일정
    connect(datePtr, SIGNAL(sendDateInfo(QDate)), calendarPtr, SLOT(receiveDateInfo(QDate)));                                       // 날짜 -> 캘린더
    connect(schedulePtr, SIGNAL(sendDateInfo(QDate)), datePtr, SLOT(receiveDateInfo(QDate)));                                       // 일정 -> 날짜
}

WidgetManager::~WidgetManager() {
    delete dataManager;
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

/* 유저 관리 및 인증 */
const CUser& WidgetManager::getUserInfo() const
{
    return this->userInfo;
}

void WidgetManager::setUserInfo(const CUser& user)
{
    userInfo = user;
}

bool WidgetManager::login(const CUser& user)
{
    CUser authenticatedUser;
    if (dataManager->login(user, authenticatedUser))
    {
        this->userInfo = authenticatedUser;
        loadSchedules();
        return true;
    }
    return false;
}

bool WidgetManager::signUp(const CUser& user)
{
    return dataManager->signUp(user);
}

/* 일정 관리 */
void WidgetManager::loadSchedules()
{
    this->cache.clear();

    dataManager->loadSchedules(userInfo.getId(), this->cache);
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
void WidgetManager::insertSchedule(const CSchedule& sc)
{
    int newId = dataManager->insertSchedule(userInfo.getId(), sc);

    if (newId != -1)
    {
        CSchedule newSc = sc;
        newSc.setId(newId);
        this->cache[newSc.getDate()].append(newSc);
    }
}

void WidgetManager::updateSchedule(const CSchedule& sc)
{
    if (dataManager->updateSchedule(userInfo.getId(), sc))
    {
        QList<CSchedule>& list = this->cache[sc.getDate()];
        for (auto& item : list)
        {
            if (item.getId() == sc.getId()) {
                item = sc;
                break;
            }
        }
    }
}

void WidgetManager::deleteSchedule(int scheduleId)
{
    if (dataManager->deleteSchedule(userInfo.getId(), scheduleId))
    {
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            QList<CSchedule>& list = it.value();
            for (int i = 0; i < list.size(); i++)
            {
                if (list[i].getId() == scheduleId)
                {
                    list.removeAt(i);
                    // 비어있으면 없애기 -> 캘린더 화면 처리
                    if (list.isEmpty())
                    {
                        cache.erase(it);
                    }
                    return;
                }
            }
        }
    }
}

QList<CSchedule> WidgetManager::searchSchedule(QString title)
{
    QList<CSchedule> temp;
    for (const auto& list : cache.values())
    {
        for (const auto& sc : list)
        {
            if (sc.getTitle().contains(title, Qt::CaseInsensitive))
            {
                temp.append(sc);
            }
        }
    }
    return temp;
}
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
void WidgetManager::loadSchedulesFromDisk()
{
    this->cache.clear();
    this->scheduleNumber = 1;

    QString userPath = getBasePath() + "/" + QString::number(userInfo.getId());
    QString filePath = userPath + "/meta_schedule.json";

    QFile file(filePath);

    if (!file.exists()) {
        return;
    }

    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();

        QJsonObject root = QJsonDocument::fromJson(data).object();

        this->scheduleNumber = root["totalScheduleCount"].toInt() + 1;

        QJsonArray scheduleArray = root["schedules"].toArray();
        for (const QJsonValue& val : scheduleArray) {
            QJsonObject scObj = val.toObject();

            CSchedule sc;
            sc.fromJson(scObj);

            this->cache[sc.getDate()].append(sc);
        }
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
    int userId = userInfo.getId();
    QString userPath = getBasePath() + "/" + QString::number(userId);
    QString filePath = userPath + "/meta_schedule.json";

    QDir dir;
    if (!dir.exists(userPath)) {
        dir.mkpath(userPath);
    }

    QFile file(filePath);
    QJsonObject root;
    QJsonArray scheduleArray;
    int lastId = 0;

    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        root = QJsonDocument::fromJson(file.readAll()).object();
        scheduleArray = root["schedules"].toArray();
        lastId = root["totalScheduleCount"].toInt();
        file.close();
    }

    CSchedule newCs = cs;
    int currentId = lastId + 1;
    newCs.setId(currentId);

    this->scheduleNumber = currentId + 1;

    this->cache[date].append(newCs);

    scheduleArray.append(newCs.toJson());
    root["totalScheduleCount"] = currentId;
    root["schedules"] = scheduleArray;

    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
    }
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
    if (this->cache.contains(date)) {
        QList<CSchedule>& list = this->cache[date];
        for (int i = 0; i < list.size(); ++i) {
            if (list[i].getId() == cs.getId()) {
                list.removeAt(i);
                break;
            }
        }

        if (list.isEmpty()) {
            this->cache.remove(date);
        }
    }

    QString userPath = getBasePath() + "/" + QString::number(userInfo.getId());
    QString filePath = userPath + "/meta_schedule.json";
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
        QJsonObject root = QJsonDocument::fromJson(file.readAll()).object();
        file.close();

        QJsonArray oldArray = root["schedules"].toArray();
        QJsonArray newArray;

        for (const QJsonValue& val : oldArray) {
            if (val.toObject()["id"].toInt() != cs.getId()) {
                newArray.append(val);
            }
        }

        root["schedules"] = newArray;

        if (file.open(QIODevice::WriteOnly)) {
            file.write(QJsonDocument(root).toJson());
            file.close();
        }
    }
}

QList<CSchedule> WidgetManager::searchSchedule(QString title)
{
    QList<CSchedule> temp;

    for (const auto& date : cache.keys())
    {
        for (const auto& sc : cache.value(date))
        {
            if (sc.getTitle().contains(title, Qt::CaseInsensitive)) {
                temp.append(sc);
            }
        }
    }

    return temp;
}
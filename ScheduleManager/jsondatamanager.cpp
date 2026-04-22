#include "jsondatamanager.h"
#include "widgetmanager.h"

JsonDataManager::JsonDataManager() {}

QString JsonDataManager::getBasePath() {
    return WidgetManager::getBasePath();
}

bool JsonDataManager::login(const CUser& user, CUser& foundUser)
{
    QFile file(getBasePath() + "/meta_user.json");
    if (!file.open(QIODevice::ReadOnly)) return false;

    QJsonObject root = QJsonDocument::fromJson(file.readAll()).object();
    QJsonArray userArray = root["users"].toArray();
    file.close();

    for (const QJsonValue& val : userArray)
    {
        QJsonObject obj = val.toObject();
        if (obj["userId"].toString() == user.getUserId() &&
            obj["userPw"].toString() == user.getUserPw())
        {
            foundUser.fromJson(obj);
            return true;
        }
    }
    return false;
}

bool JsonDataManager::signUp(const CUser& user) {
    QString path = getBasePath();
    QDir().mkpath(path);
    QFile file(path + "/meta_user.json");

    QJsonObject root;
    QJsonArray userArray;
    int totalCount = 0;

    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        root = QJsonDocument::fromJson(file.readAll()).object();
        userArray = root["users"].toArray();
        totalCount = root["totalUserCount"].toInt();
        file.close();
    }

    for (const QJsonValue& val : userArray) {
        if (val.toObject()["userId"].toString() == user.getUserId()) return false; // id 중복 체크
    }

    CUser newUser = user;
    newUser.setId(++totalCount);
    userArray.append(newUser.toJson());

    root["totalUserCount"] = totalCount;
    root["users"] = userArray;

    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
        return true;
    }
    return false;
}

void JsonDataManager::loadSchedules(const int userId, QMap<QDate, QList<CSchedule>>& cache) {
    cache.clear();
    QFile file(getBasePath() + "/" + QString::number(userId) + "/meta_schedule.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonObject root = QJsonDocument::fromJson(file.readAll()).object();
    QJsonArray scheduleArray = root["schedules"].toArray();
    file.close();

    for (const QJsonValue& val : scheduleArray) {
        CSchedule sc;
        sc.fromJson(val.toObject());
        cache[sc.getDate()].append(sc);
    }
}

int JsonDataManager::insertSchedule(const int userId, const CSchedule& sc) {
    QString userDir = getBasePath() + "/" + QString::number(userId);
    QDir().mkpath(userDir);
    QFile file(userDir + "/meta_schedule.json");

    QJsonObject root;
    QJsonArray scheduleArray;
    int totalCount = 0;

    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        root = QJsonDocument::fromJson(file.readAll()).object();
        scheduleArray = root["schedules"].toArray();
        totalCount = root["totalScheduleCount"].toInt();
        file.close();
    }

    CSchedule newSc = sc;
    newSc.setId(++totalCount);
    scheduleArray.append(newSc.toJson());

    root["totalScheduleCount"] = totalCount;
    root["schedules"] = scheduleArray;

    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
        return newSc.getId();
    }
    return -1;
}

bool JsonDataManager::deleteSchedule(const int userId, const int scheduleId) {
    QString filePath = getBasePath() + "/" + QString::number(userId) + "/meta_schedule.json";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QJsonObject root = QJsonDocument::fromJson(file.readAll()).object();
    QJsonArray oldArray = root["schedules"].toArray();
    QJsonArray newArray;
    file.close();

    bool found = false;
    for (const QJsonValue& val : oldArray) {
        if (val.toObject()["id"].toInt() == scheduleId) {
            found = true;
            continue;
        }
        newArray.append(val);
    }

    if (!found) return false;

    root["schedules"] = newArray;
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
        return true;
    }
    return false;
}

bool JsonDataManager::updateSchedule(const int userId, const CSchedule& sc) {
    QString filePath = getBasePath() + "/" + QString::number(userId) + "/meta_schedule.json";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QJsonObject root = QJsonDocument::fromJson(file.readAll()).object();
    QJsonArray scheduleArray = root["schedules"].toArray();
    file.close();

    QJsonArray newArray;
    bool found = false;
    for (const QJsonValue& val : scheduleArray) {
        QJsonObject obj = val.toObject();
        if (obj["id"].toInt() == sc.getId()) {
            newArray.append(sc.toJson());
            found = true;
        } else {
            newArray.append(obj);
        }
    }

    if (!found) return false;

    root["schedules"] = newArray;
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
        return true;
    }
    return false;
}
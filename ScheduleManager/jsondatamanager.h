#ifndef JSONDATAMANAGER_H
#define JSONDATAMANAGER_H

#include "datamanager.h"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

/**
 * @brief The JsonDataManager class 로컬에 Json으로 저장하는 데이터 관리자
 */
class JsonDataManager : public DataManager {
public:
    JsonDataManager();

    bool login(const CUser& user, CUser& foundUser) override;
    bool signUp(const CUser& user) override;

    void loadSchedules(const int userId, QMap<QDate, QList<CSchedule>>& cache) override;
    int insertSchedule(const int userId, const CSchedule& sc) override;
    bool deleteSchedule(const int userId, const int scheduleId) override;
    bool updateSchedule(const int userId, const CSchedule& sc) override;

private:
    QString getBasePath();      // 저장할 폴더 위치
};

#endif // JSONDATAMANAGER_H

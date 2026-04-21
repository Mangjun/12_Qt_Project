#ifndef MEMORYDATAMANAGER_H
#define MEMORYDATAMANAGER_H

#include "datamanager.h"

/**
 * @brief The MemoryDataManager class 메모리를 사용하는 데이터 관리자
 */
class MemoryDataManager : public DataManager
{
public:
    MemoryDataManager();

    bool login(const CUser& user, CUser& foundUser) override;
    bool signUp(const CUser& user) override;

    void loadSchedules(int userId, QMap<QDate, QList<CSchedule>>& cache) override;
    int insertSchedule(int userId, const CSchedule& sc) override;
    bool deleteSchedule(int userId, int scheduleId) override;
    bool updateSchedule(int userId, const CSchedule& sc) override;

private:
    static QList<CUser> users;
    static QList<CSchedule> allSchedules;
    static int userCount;
    static int scheduleCount;
};

#endif // MEMORYDATAMANAGER_H

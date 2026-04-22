#include "memorydatamanager.h"

QList<CUser> MemoryDataManager::users = {};
QList<CSchedule> MemoryDataManager::allSchedules = {};
int MemoryDataManager::userCount = 1;
int MemoryDataManager::scheduleCount = 1;

MemoryDataManager::MemoryDataManager() {}

bool MemoryDataManager::login(const CUser& user, CUser& foundUser)
{
    for (const auto& u : users)
    {
        if (u.getUserId() == user.getUserId() && u.getUserPw() == user.getUserPw())
        {
            foundUser = u;
            return true;
        }
    }
    return false;
}

bool MemoryDataManager::signUp(const CUser& user)
{
    for (const auto& u : users)
    {
        if (u.getUserId() == user.getUserId()) return false; // id 중복 체크
    }

    CUser newUser = user;
    newUser.setId(userCount++);
    users.append(newUser);
    return true;
}

void MemoryDataManager::loadSchedules(const int userId, QMap<QDate, QList<CSchedule>>& cache)
{
    cache.clear();

    for (const auto& sc : allSchedules)
    {
        cache[sc.getDate()].append(sc);
    }
}

int MemoryDataManager::insertSchedule(const int userId, const CSchedule& sc)
{
    CSchedule newSc = sc;
    newSc.setId(scheduleCount++);
    allSchedules.append(newSc);
    return newSc.getId();
}

bool MemoryDataManager::deleteSchedule(const int userId, const int scheduleId)
{
    for (int i = 0; i < allSchedules.size(); i++)
    {
        if (allSchedules[i].getId() == scheduleId)
        {
            allSchedules.removeAt(i);
            return true;
        }
    }
    return false;
}

bool MemoryDataManager::updateSchedule(const int userId, const CSchedule& sc)
{
    for (int i = 0; i < allSchedules.size(); i++)
    {
        if (allSchedules[i].getId() == sc.getId())
        {
            allSchedules[i] = sc;
            return true;
        }
    }
    return false;
}
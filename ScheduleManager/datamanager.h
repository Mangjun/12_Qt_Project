#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QList>
#include <QMap>
#include <QDate>
#include "cuser.h"
#include "cschedule.h"

/**
 * @brief The DataManager class 데이터 관리자
 */
class DataManager
{
public:
    virtual ~DataManager() = default;

    /* 유저 관련 기능 */
    /**
     * @brief login     로그인
     * @param user      입력받은 유저 정보
     * @param foundUser 로그인한 유저 정보
     * @return          로그인 성공 여부
     */
    virtual bool login(const CUser& user, CUser& foundUser) = 0;

    /**
     * @brief signUp    회원 가입
     * @param user      유저 정보
     * @return          회원 가입 성공 여부
     */
    virtual bool signUp(const CUser& user) = 0;

    /* 일정 관련 기능 */
    /**
     * @brief loadSchedules 일정 캐시로 로드
     * @param userId        유저 식별자
     * @param cache         캐시
     */
    virtual void loadSchedules(int userId, QMap<QDate, QList<CSchedule>>& cache) = 0;

    /**
     * @brief insertSchedule 일정 추가
     * @param userId         유저 식별자
     * @param sc             일정 정보
     * @return               일정 식별자
     */
    virtual int insertSchedule(int userId, const CSchedule& sc) = 0;

    /**
     * @brief deleteSchedule 일정 삭제
     * @param userId         유저 식별자
     * @param scheduleId     일정 식별자
     * @return               삭제 성공 여부
     */
    virtual bool deleteSchedule(int userId, int scheduleId) = 0;

    /**
     * @brief updateSchedule 일정 수정
     * @param userId         유저 식별자
     * @param sc             일정 수정 내용
     * @return               수정 성공 여부
     */
    virtual bool updateSchedule(int userId, const CSchedule& sc) = 0;
};

#endif // DATAMANAGER_H

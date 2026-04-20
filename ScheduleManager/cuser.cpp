#include "cuser.h"

CUser::CUser()
{

}

CUser::CUser(QString userId, QString userPw) : id(0), userId(userId), userPw(userPw)
{

}

void CUser::setId(const int id)
{
    if (id < 0) return;
    this->id = id;
}

int CUser::getId() const
{
    return this->id;
}

void CUser::setUserId(const QString userId)
{
    if(userId == nullptr) return;
    this->userId = userId;
}

QString CUser::getUserId() const
{
    return this->userId;
}

void CUser::setUserPw(const QString userPw)
{
    if(userPw == nullptr) return;
    this->userPw = userPw;
}

QString CUser::getUserPw() const
{
    return this->userPw;
}
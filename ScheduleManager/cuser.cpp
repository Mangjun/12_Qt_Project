#include "cuser.h"

CUser::CUser()
{

}

CUser::CUser(const QString& userId, const QString& userPw) : id(0), userId(userId), userPw(userPw)
{

}

/* JSON */
QJsonObject CUser::toJson() const
{
    QJsonObject json;
    json["id"] = id;
    json["userId"] = userId;
    json["userPw"] = userPw;
    return json;
}

void CUser::fromJson(const QJsonObject& json)
{
    id = json["id"].toInt();
    userId = json["userId"].toString();
    userPw = json["userPw"].toString();
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

void CUser::setUserId(const QString& userId)
{
    if(userId == nullptr) return;
    this->userId = userId;
}

const QString CUser::getUserId() const
{
    return this->userId;
}

void CUser::setUserPw(const QString& userPw)
{
    if(userPw == nullptr) return;
    this->userPw = userPw;
}

const QString CUser::getUserPw() const
{
    return this->userPw;
}
#include "cuser.h"

CUser::CUser()
{

}

CUser::CUser(QString id, QString pw) : id(id), pw(pw)
{

}

void CUser::setId(const QString id)
{
    if(id != nullptr)
    {
        this->id = id;
    }
}

QString CUser::getId() const
{
    return this->id;
}

void CUser::setPw(const QString pw)
{
    if(pw != nullptr)
    {
        this->pw = pw;
    }
}

QString CUser::getPw() const
{
    return this->pw;
}
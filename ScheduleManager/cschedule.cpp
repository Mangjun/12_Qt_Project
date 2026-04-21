#include "cschedule.h"

CSchedule::CSchedule() {}
CSchedule::CSchedule(QString title, QDate date, QString detail) : id(0), userId(0), title(title), date(date), detail(detail)
{

}

void CSchedule::setId(const int id)
{
    if (id < 0) return;
    this->id = id;
}

int CSchedule::getId() const
{
    return this->id;
}

void CSchedule::setUserId(const int userId)
{
    if (id < 0) return;
    this->userId = userId;
}

int CSchedule::getUserId() const
{
    return this->userId;
}

void CSchedule::setTitle(const QString title)
{
    if (title == nullptr) return;
    this->title = title;
}

QString CSchedule::getTitle() const
{
    return this->title;
}

void CSchedule::setDate(const QDate date)
{
    this->date = date;
}

QDate CSchedule::getDate() const
{
    return this->date;
}

void CSchedule::setDetail(const QString detail)
{
    if (detail == nullptr) return;
    this->detail = detail;
}

QString CSchedule::getDetail() const
{
    return this->detail;
}
#include "cschedule.h"

void CSchedule::setTitle(const QString title)
{
    if (title == nullptr)
    {
        this->title = "";
    }
    else
    {
        this->title = title;
    }
}

QString CSchedule::getTitle() const
{
    return this->title;
}

void CSchedule::setDate(const QDateTime date)
{
    this->date = date;
}

QDateTime CSchedule::getDate() const
{
    return this->date;
}

void CSchedule::setDetail(const QString detail)
{
    if (detail == nullptr)
    {
        this->detail = "";
    }
    else
    {
        this->detail = detail;
    }
}

QString CSchedule::getDetail() const
{
    return this->detail;
}
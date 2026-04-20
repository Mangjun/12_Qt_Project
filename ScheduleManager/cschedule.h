#ifndef CSCHEDULE_H
#define CSCHEDULE_H

#include <QString>
#include <QDateTime>

class CSchedule
{
private:
    QString title;
    QDateTime date;
    QString detail;
public:
    void setTitle(const QString title);
    QString getTitle() const;

    void setDate(const QDateTime date);
    QDateTime getDate() const;

    void setDetail(const QString detail);
    QString getDetail() const;
};

#endif // CSCHEDULE_H

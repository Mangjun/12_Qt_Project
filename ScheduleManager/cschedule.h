#ifndef CSCHEDULE_H
#define CSCHEDULE_H

#include <QString>
#include <QDateTime>

class CSchedule
{
private:
    int id;
    int userId;

    QString title;
    QDateTime date;
    QString detail;
public:
    CSchedule();
    CSchedule(QString title, QDateTime date, QString detail);

    void setId(const int id);
    int getId() const;

    void setUserId(const int userId);
    int getUserId() const;

    void setTitle(const QString title);
    QString getTitle() const;

    void setDate(const QDateTime date);
    QDateTime getDate() const;

    void setDetail(const QString detail);
    QString getDetail() const;
};

#endif // CSCHEDULE_H

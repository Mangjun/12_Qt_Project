#ifndef CSCHEDULE_H
#define CSCHEDULE_H

#include <QString>
#include <QDate>

class CSchedule
{
private:
    int id;
    QString title;
    QDate date;
    QString detail;
public:
    CSchedule();
    CSchedule(QString title, QDate date, QString detail);

    void setId(const int id);
    int getId() const;

    void setTitle(const QString title);
    QString getTitle() const;

    void setDate(const QDate date);
    QDate getDate() const;

    void setDetail(const QString detail);
    QString getDetail() const;
};

#endif // CSCHEDULE_H

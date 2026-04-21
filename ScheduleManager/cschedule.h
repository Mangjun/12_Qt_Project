#ifndef CSCHEDULE_H
#define CSCHEDULE_H

#include <QString>
#include <QDate>
#include <QJsonObject>
#include <QJsonDocument>

class CSchedule
{
private:
    int id;             // 식별자
    QString title;      // 제목
    QDate date;         // 날짜
    QString detail;     // 세부 사항
public:
    CSchedule();
    CSchedule(QString title, QDate date, QString detail);

    /* JSON */
    QJsonObject toJson() const;
    void fromJson(const QJsonObject& json);

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

#ifndef CUSER_H
#define CUSER_H

#include <QString>
#include <QJsonObject>
class CUser
{
private:
    int id;
    QString userId;
    QString userPw;
public:
    CUser();
    CUser(QString userId, QString userPw);

    /* JSON */
    QJsonObject toJson() const;
    void fromJson(const QJsonObject& json);

    void setId(const int id);
    int getId() const;

    void setUserId(const QString userId);
    QString getUserId() const;

    void setUserPw(const QString userPw);
    QString getUserPw() const;
};

#endif // CUSER_H

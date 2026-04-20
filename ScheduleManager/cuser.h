#ifndef CUSER_H
#define CUSER_H

#include <QString>

class CUser
{
private:
    QString id;
    QString pw;
public:
    CUser();
    CUser(QString id, QString pw);

    void setId(const QString id);
    QString getId() const;

    void setPw(const QString pw);
    QString getPw() const;
};

#endif // CUSER_H

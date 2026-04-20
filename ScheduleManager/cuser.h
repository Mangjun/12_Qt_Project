#ifndef CUSER_H
#define CUSER_H

#include <QString>

class CUser
{
private:
    QString id;
    QString pw;
public:
    QString setId(const QString id);
    QString getId() const;

    QString setPw(const QString pw);
    QString getPw() const;
};

#endif // CUSER_H

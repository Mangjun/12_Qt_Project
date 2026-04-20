#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "cuser.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void userLogin(CUser user);

private:
    Ui::Login *ui;

private slots:
    void clickedLoginBtn();
    void gotoSignUp();
};

#endif // LOGIN_H

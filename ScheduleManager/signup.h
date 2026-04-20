#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "cuser.h"

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();
    void signUp(CUser user);

private:
    Ui::Signup *ui;

private slots:
    void clickedAcceptBtn();
};

#endif // SIGNUP_H

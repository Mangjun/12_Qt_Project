#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "cuser.h"
#include "widgetmanager.h"

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private:
    Ui::Signup *ui;

    /* 비즈니스 로직 */
    void signUp(const CUser& user);

private slots:
    /* 이벤트 처리 */
    void clickedAcceptBtn();
    void clickedRejectBtn();
};

#endif // SIGNUP_H

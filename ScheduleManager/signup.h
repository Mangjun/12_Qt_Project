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
    /**
     * @brief 회원가입 로직
     * @param user 사용자에게 입력받은 회원 정보
     */
    void signUp(const CUser& user);

private:
    Ui::Signup *ui;

private slots:
    /**
     * @brief 회원가입 버튼 클릭 이벤트
     */
    void clickedAcceptBtn();
};

#endif // SIGNUP_H

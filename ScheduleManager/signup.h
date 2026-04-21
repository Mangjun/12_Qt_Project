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

private:
    Ui::Signup *ui;

    /* 비즈니스 로직 */
    /**
     * @brief signUp 회원 가입
     * @param user   입력받은 유저 정보
     */
    void signUp(const CUser& user);

private slots:
    /* 이벤트 처리 */
    void clickedAcceptBtn();    // 회원 가입 버튼 클릭
    void clickedRejectBtn();    // 취소 버튼 클릭
};

#endif // SIGNUP_H

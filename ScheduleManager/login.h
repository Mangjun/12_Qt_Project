#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "cuser.h"
#include "widgetmanager.h"
#include "signup.h"
#include "calendar.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    /**
     * @brief userLogin 로그인 로직
     * @param user 사용자가 설정한 로그인 정보
     */
    void userLogin(CUser user);

private:
    Ui::Login *ui;
    /**
     * @brief gotoCalendar 캘린더 화면으로 이동
     */
    void gotoCalendar();

signals:
    void loginSuccess(QDate date);

private slots:
    /**
     * @brief clickedLoginBtn 로그인 버튼 이벤트
     */
    void clickedLoginBtn();
    /**
     * @brief gotoSignUp 회원가입 기능 이벤트
     */
    void gotoSignUp();
};

#endif // LOGIN_H

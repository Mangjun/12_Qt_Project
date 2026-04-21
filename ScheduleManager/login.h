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

private:
    Ui::Login *ui;
    /* 화면 이동 */
    void gotoCalendar();

    /* 비즈니스 로직 */
    void userLogin(CUser user);

signals:
    /* 다른 위젯에게 정보 보내기 */
    void loginSuccess(QDate date);

private slots:
    /* 이벤트 처리 */
    void clickedLoginBtn(); // 로그인 버튼 클릭
    void gotoSignUp();      // 회원 가입 다이얼로그 켜기
};

#endif // LOGIN_H

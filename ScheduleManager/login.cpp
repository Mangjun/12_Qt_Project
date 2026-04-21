#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(clickedLoginBtn()));
    connect(ui->signupButton, SIGNAL(clicked(bool)), this, SLOT(gotoSignUp()));
}

Login::~Login()
{
    delete ui;
}

/* 화면 이동 */
void Login::gotoCalendar()
{
    Calendar* cal = WidgetManager::instance().getCalendar();
    cal->show();
    this->close();
}

/* 비즈니스 로직 */
void Login::userLogin(CUser user)
{
    bool isLogin = false;

    CUser userInfo = WidgetManager::instance().getUserInfo();
    QString id = userInfo.getUserId();
    QString pw = userInfo.getUserPw();

    if (!user.getUserId().isEmpty() && user.getUserId() == id)
    {
        if (!user.getUserPw().isEmpty() && user.getUserPw() == pw)
        {
            isLogin = true;
        }
    }

    if (isLogin)
    {
        emit loginSuccess(QDate::currentDate());
        gotoCalendar();
    }
    else
    {
        ui->idInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
    }
}

/* 이벤트 처리 */
void Login::clickedLoginBtn()
{
    QString id = ui->idInput->text();
    QString pw = ui->pwInput->text();

    CUser user(id, pw);
    userLogin(user);
}

void Login::gotoSignUp()
{
    Signup signup;
    signup.exec();
}
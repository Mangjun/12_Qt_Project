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

void Login::userLogin(CUser user)
{
    bool isLogin = false;

    qDebug() << QString("id: %1, pw: %2").arg(user.getId()).arg(user.getPw());

    if (isLogin) {
        emit loginSuccess();
    }
}

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
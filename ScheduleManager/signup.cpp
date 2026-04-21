#include "signup.h"
#include "ui_signup.h"
#include "widgetmanager.h"

Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
    connect(ui->signupButton, SIGNAL(clicked(bool)), this, SLOT(clickedAcceptBtn()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(clickedRejectBtn()));
}

Signup::~Signup()
{
    delete ui;
}

/* 비즈니스 로직 */
void Signup::signUp(const CUser& user)
{
    if (WidgetManager::instance().signUp(user))
    {
        accept();
    }
    else
    {
        ui->idInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
        ui->idInput->setFocus();
    }
}

/* 이벤트 처리 */
void Signup::clickedAcceptBtn()
{
    QString id = ui->idInput->text();
    QString pw = ui->pwInput->text();
    QString pwCheck = ui->pwConfirmInput->text();

    if (pw == pwCheck)
    {
        CUser user(id, pw);
        signUp(user);
    }
    else
    {
        ui->pwConfirmInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
        ui->pwConfirmInput->setFocus();
    }
}

void Signup::clickedRejectBtn()
{
    reject();
}
#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
    connect(ui->signupButton, SIGNAL(clicked(bool)), this, SLOT(clickedAcceptBtn()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::signUp(const CUser& user)
{
    qDebug() << QString("id: %1, pw: %2").arg(user.getId()).arg(user.getPw());
}

void Signup::clickedAcceptBtn()
{
    QString id = ui->idInput->text();
    QString pw = ui->pwInput->text();
    QString pwCheck = ui->pwConfirmInput->text();

    if (pw == pwCheck)
    {
        CUser user(id, pw);
        signUp(user);
        accept();
    }
    else
    {
        ui->pwConfirmInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
    }
}
#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::signUp(CUser user)
{

}

void Signup::clickedAcceptBtn()
{

}
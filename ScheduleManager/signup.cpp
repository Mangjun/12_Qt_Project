#include "signup.h"
#include "ui_signup.h"

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
    QString filePath = WidgetManager::getBasePath() + "/meta_user.json";
    QFile file(filePath);
    QJsonObject root;
    QJsonArray userArray;
    int totalCount = 0;

    if (file.exists()) {
        if (file.open(QIODevice::ReadOnly)) {
            root = QJsonDocument::fromJson(file.readAll()).object();
            userArray = root["users"].toArray();
            totalCount = root["totalUserCount"].toInt();
            file.close();
        }

        for (const QJsonValue& val : userArray) {
            if (val.toObject()["userId"].toString() == user.getUserId()) {
                ui->idInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
                ui->idInput->setFocus();
                return;
            }
        }
    } else {
        QDir().mkpath(WidgetManager::getBasePath());
    }

    CUser newUser = user;
    int newId = totalCount + 1;
    newUser.setId(newId);

    userArray.append(newUser.toJson());
    root["totalUserCount"] = newId;
    root["users"] = userArray;

    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();

        accept();
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
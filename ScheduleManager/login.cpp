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
    CUser foundUser;

    QFile file(WidgetManager::getBasePath() + "/meta_user.json");

    if (!file.exists() || user.getUserId().isEmpty() || user.getUserPw().isEmpty()) {
        ui->idInput->setStyleSheet("border: 1.5px solid #FF3B30; background-color: #FFF2F2");
        return;
    }

    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (!doc.isNull() && doc.isObject()) {
            QJsonObject root = doc.object();
            QJsonArray userArray = root["users"].toArray();

            for (const QJsonValue& val : userArray) {
                QJsonObject obj = val.toObject();
                if (obj["userId"].toString() == user.getUserId() &&
                    obj["userPw"].toString() == user.getUserPw()) {

                    foundUser.fromJson(obj);
                    isLogin = true;
                    break;
                }
            }
        }
    }

    // 3. 결과 처리
    if (isLogin)
    {
        WidgetManager::instance().setUserInfo(foundUser);       // 유저 정보 등록
        WidgetManager::instance().loadSchedulesFromDisk();      // 유저 일정 리스트 로드

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
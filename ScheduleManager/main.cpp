#include "login.h"

#include "widgetmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetManager::instance(); // 인스턴스 생성 보장

    Login w;
    w.show();
    return QCoreApplication::exec();
}

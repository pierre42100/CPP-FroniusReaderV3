#include <QApplication>
#include <QCoreApplication>

#include "config.h"
#include "mainwidget.h"

int main(int argc, char **argv){

    QApplication app(argc, argv);

    QCoreApplication::setApplicationName(APP_NAME);
    QCoreApplication::setOrganizationName(APP_ORGANISATION);
    QCoreApplication::setOrganizationDomain(APP_ORGANISATION_DOMAIN);


    MainWidget mainWidget;
    mainWidget.show();

    return app.exec();

}

#include <QtCore/QCoreApplication>
#include "WebServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	new WebServer;
    return a.exec();
}

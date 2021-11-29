#pragma once

#include <QObject>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QTimer>
//#include "Reader.h"

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class Reader;
class WebServer : public QObject {

	Q_OBJECT

public:
	WebServer(QObject *parent = Q_NULLPTR);
	~WebServer();

private:
	QWebSocketServer *webServer;
	Reader *reader;

public slots:
	void onWebServerNewConnection();
	void onWebClientDisconnected();
	void onWebClientCommunication(QString entryMessage);


};

#include "WebServer.h"

WebServer::WebServer(QObject *parent) : QObject(parent) {

	// Webserver
	webServer = new QWebSocketServer(QStringLiteral("WebServer"), QWebSocketServer::NonSecureMode, this);

	QObject::connect(webServer, &QWebSocketServer::newConnection, this, &WebServer::onWebServerNewConnection);

	webServer->listen(QHostAddress::AnyIPv4, 168);

}

void WebServer::onWebServerNewConnection() {

	qDebug() << "Un client WEB s'est connecte";

	QWebSocket * webClient = webServer->nextPendingConnection();
	QTcpSocket::connect(webClient, &QWebSocket::textMessageReceived, this, &WebServer::onWebClientCommunication);
	QTcpSocket::connect(webClient, &QWebSocket::disconnected, this, &WebServer::onWebClientDisconnected);


}

void WebServer::onWebClientCommunication(QString entryMessage) {

	QWebSocket * obj = qobject_cast<QWebSocket*>(sender());
	QString data = entryMessage;

	qDebug() << data;

}

void WebServer::onWebClientDisconnected() {

	qDebug() << "Deconexion Client";
}

WebServer::~WebServer() {
	qDebug() << "Destruction Serveur";
}
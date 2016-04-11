#include "Server.hpp"
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

#include "RemoteClient.hpp"

Server::Server(QObject *parent) :
    QObject(parent),
    m_server(new QTcpServer(this))
{
}

void Server::startServer(quint16 port)
{
    bool started = m_server->listen(QHostAddress::Any, port);

    connect(m_server, SIGNAL(newConnection()), this, SLOT(onClientConnected()));

    if (started) {
        emit serverStarted(m_server->serverPort());
        qDebug() << Q_FUNC_INFO << "Server started on port :" << m_server->serverPort();
    }
}

void Server::sendMessage(QString message)
{
    for (RemoteClient *client : m_clients) {
        client->sendMessage(message);
    }
}

void Server::onClientConnected()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();

    RemoteClient *client = new RemoteClient(clientSocket, this);

    m_clients << client;

    connect(client, SIGNAL(messageReceived(QString,QString)),
            this, SIGNAL(messageReceived(QString,QString)));
}

void Server::onReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());

    emit messageReceived(client->peerAddress().toString(), client->readAll());
}

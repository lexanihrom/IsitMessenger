#include "Server.hpp"

#include <QTcpServer>
#include <QTcpSocket>

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
        emit serverStarted(port);
    }
}

void Server::sendMessage(QString message)
{
    for (QTcpSocket *client : m_clients) {
        client->write(message.toUtf8());
    }
}

void Server::onClientConnected()
{
    QTcpSocket *client = m_server->nextPendingConnection();

    m_clients << client;

    connect(client, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Server::onReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());

    emit messageReceived(client->peerAddress().toString(), client->readAll());
}

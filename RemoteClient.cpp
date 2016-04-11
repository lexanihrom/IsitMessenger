#include "RemoteClient.hpp"

#include <QTcpSocket>

RemoteClient::RemoteClient(QTcpSocket *socket, QObject *parent) :
    QObject(parent),
    m_socket(socket)
{
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
}

void RemoteClient::sendMessage(QString message)
{
    m_socket->write(message.toUtf8());
}

void RemoteClient::onReadyRead()
{
    emit messageReceived(m_socket->readAll());
}

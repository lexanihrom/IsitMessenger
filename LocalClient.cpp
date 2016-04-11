#include "LocalClient.hpp"

#include <QTcpSocket>

LocalClient::LocalClient(QObject *parent) :
    QObject(parent),
    m_socket(new QTcpSocket(this))
{
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
}

void LocalClient::connectToServer(QString address, quint16 port)
{
    m_socket->connectToHost(address, port);
}

void LocalClient::sendMessage(QString message)
{
    m_socket->write(message.toUtf8());
}

void LocalClient::onReadyRead()
{
    emit messageReceived("123", m_socket->readAll());
}

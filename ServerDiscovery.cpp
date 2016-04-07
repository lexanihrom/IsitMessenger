#include "ServerDiscovery.hpp"

#include <QUdpSocket>
#include <QNetworkInterface>

static const quint16 s_udpPort = 29031;
static const QByteArray s_header = "IsitMessenger";

ServerDiscovery::ServerDiscovery(QObject *parent) :
    QObject(parent)
{
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(QHostAddress::Any, s_udpPort, QAbstractSocket::ShareAddress|QAbstractSocket::ReuseAddressHint);
    connect(m_udpSocket, SIGNAL(readyRead()),
            this, SLOT(onUdpMessageReceived()));

}

void ServerDiscovery::addServer(quint16 port)
{
     m_port = port;
}

void ServerDiscovery::onUdpMessageReceived()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(m_udpSocket->pendingDatagramSize());
        QHostAddress address;
        m_udpSocket->readDatagram(buffer.data(), buffer.size(), &address);
        if (buffer == s_header+":?"){
            announceServer();
        } else {
            QList<QByteArray> lBuff = buffer.split(':');
            quint16 port = lBuff[1].toUInt();
            emit serverFound(address.toString(),port);
        }
    }
}

void ServerDiscovery::announceServer()
{
    for (QNetworkInterface iface : QNetworkInterface::allInterfaces()){
        for (QNetworkAddressEntry entry : iface.addressEntries()) {
            QString datagram = s_header + ":" + QString::number(m_port);
            m_udpSocket->writeDatagram(datagram.toLatin1(), entry.broadcast(), s_udpPort);
        }
    }
}

void ServerDiscovery::discoveryServer()
{
    for (QNetworkInterface iface : QNetworkInterface::allInterfaces()){
        for (QNetworkAddressEntry entry : iface.addressEntries()) {
            QString datagram = s_header + ":?";
            m_udpSocket->writeDatagram(datagram.toLatin1(), entry.broadcast(), s_udpPort);
        }
    }
}

#ifndef SERVERDISCOVERY_HPP
#define SERVERDISCOVERY_HPP

#include <QObject>

class QUdpSocket;

class ServerDiscovery : public QObject
{
    Q_OBJECT
public:
    explicit ServerDiscovery(QObject *parent = 0);

signals:
    void serverFound(QString ip, quint16 port);

public slots:
    void addServer(quint16 port);

private slots:
    void onUdpMessageReceived();

    void announceServer();
    void discoveryServer();

private:
    QUdpSocket *m_udpSocket;
    quint16 m_port;

};

#endif // SERVERDISCOVERY_HPP

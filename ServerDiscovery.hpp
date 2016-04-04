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

public slots:
    void addServer(quint port);

private:
    QUdpSocket *m_udpSocket;
};

#endif // SERVERDISCOVERY_HPP

#ifndef LOCALCLIENT_HPP
#define LOCALCLIENT_HPP

#include <QObject>

class QTcpServer;
class QTcpSocket;

class LocalClient : public QObject
{
    Q_OBJECT
public:
    explicit LocalClient(QObject *parent = 0);

signals:
    void connected();
    void messageReceived(QString client, QString message);

public slots:
    void connectToServer();
    void sendMessage(QString message);
};

#endif // LOCALCLIENT_HPP

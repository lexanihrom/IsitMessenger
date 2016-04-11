#ifndef REMOTECLIENT_HPP
#define REMOTECLIENT_HPP

#include <QObject>

class QTcpSocket;

class RemoteClient : public QObject
{
    Q_OBJECT
public:
    explicit RemoteClient(QTcpSocket *socket, QObject *parent = 0);
    QString nickName();

signals:
    void messageReceived(QString message);

public slots:
    void sendMessage(QString message);

protected slots:
    void onReadyRead();

protected:
    QTcpSocket *m_socket;
};

#endif // REMOTECLIENT_HPP

#ifndef LOCALCLIENT_HPP
#define LOCALCLIENT_HPP

#include <QObject>

class QTcpSocket;

class LocalClient : public QObject
{
    Q_OBJECT
public:
    explicit LocalClient(QObject *parent = 0);

signals:
    void connected();
    void messageReceived(QString message);

public slots:
    void connectToServer(QString address, quint16 port);
    void sendMessage(QString message);
    void setNickname(QString nickname);

protected slots:
    void onReadyRead();

protected:
    QTcpSocket *m_socket;
    QString m_pendingNickname;
    QString m_nickname;
};

#endif // LOCALCLIENT_HPP

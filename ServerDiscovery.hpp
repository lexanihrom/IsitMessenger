#ifndef SERVERDISCOVERY_HPP
#define SERVERDISCOVERY_HPP

#include <QObject>

class Serverdiscovery : public QObject
{
    Q_OBJECT
public:
    explicit Serverdiscovery(QObject *parent = 0);

signals:

public slots:
};

#endif // SERVERDISCOVERY_HPP

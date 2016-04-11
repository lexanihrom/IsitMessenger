#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class ServerDiscovery;
class Server;
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     void connectToServer();

public slots:
    void addContact(QString name);
    void addMessage(QString name, QString text);
    void addServer(QString address, quint16 port);
    void addServerToDiscovery(quint16 port);

private slots:
    void createServer();

    void on_serverListConnectButton_clicked();

    void on_serverListList_itemDoubleClicked(QListWidgetItem *item);

    void on_serverListList_itemClicked(QListWidgetItem *item);

    void on_serverListRefreshButton_clicked();

private:
    Ui::MainWindow *ui;
    ServerDiscovery *m_serverDiscovery;
    Server *m_server;
};

#endif // MAINWINDOW_HPP

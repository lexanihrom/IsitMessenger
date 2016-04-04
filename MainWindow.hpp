#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addContact(QString name);
    void addMessage(QString name, QString text);

private slots:
    void createServer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP

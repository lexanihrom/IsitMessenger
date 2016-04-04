#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addContact(QString name)
{
    ui->contacts->addItem(name);
}

void MainWindow::addMessage(QString name, QString text)
{
    ui->messages->append(name+":"+text+"\n");
}

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->createServer, SIGNAL(clicked(bool)),
            this, SLOT(createServer()));
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

void MainWindow::createServer()
{

}

#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "Server.hpp"
#include "ServerDiscovery.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->createServer, SIGNAL(clicked(bool)),
            this, SLOT(createServer()));
    m_serverDiscovery = new ServerDiscovery();
    m_server = new Server();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addContact(QString name)
{
    for(int i=0;i<ui->contacts->count();i++){
        QListWidgetItem *item = ui->contacts->item(i);
        if(item->text() == name){
            return;
        }
    }
    ui->contacts->addItem(name);
}

void MainWindow::addMessage(QString name, QString text)
{
    ui->messages->append(name+":"+text+"\n");
}

void MainWindow::createServer()
{

}


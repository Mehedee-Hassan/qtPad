#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <iostream>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


}

void MainWindow::setUpThisUI(){
    ui->setupUi(this);
    changeLabelText();
    createTray();

   // hide();
    tray->showMessage("Hi","I'm here",QSystemTrayIcon::Information,30);


    this->setFixedWidth(470);
    this->setFixedHeight(400);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}

void MainWindow::createTray(){

    //create tray
    tray= new QSystemTrayIcon(this);

    //setup tray icon
    QPixmap icon(":/back3.png");
    trayIcon= QIcon(icon);
    tray->setIcon(trayIcon);
    tray->setToolTip("MousePad");

    //setup restore
    restoreAction = new QAction(QIcon(":/back3.png"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));

    closeAction = new QAction(QIcon(":/external/cross.png"), "Exit", this);
    connect(closeAction, SIGNAL(triggered()), this, SLOT(ExitApplication()));

//    aboutAction = new QAction(QIcon(":/back3.png"), "About", this);
//    connect(aboutAction, SIGNAL(triggered()), this, SLOT(ShowAbout()));


    //


    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason )),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason )));



     //create system tray menu
    trayIconMenu = new QMenu(this);

//    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(closeAction);
    tray->setContextMenu(trayIconMenu);


    tray->setVisible(true);



}

void MainWindow::ExitApplication(){

    QCoreApplication::quit();
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){


    switch (reason) {
        case QSystemTrayIcon::Trigger:

           // this->updateUI();

        case QSystemTrayIcon::DoubleClick:


            this->show();
            this->showNormal();
            break;


        case QSystemTrayIcon::MiddleClick:

            break;
        default:
            ;
        }
}



void MainWindow::changeEvent(QEvent* event){


    switch(event->type()){

        case QEvent::WindowStateChange:{

            if(this->windowState() && (Qt::WindowMinimized)){

                hide();

                tray->showMessage("Hi","I'm here",QSystemTrayIcon::Information,30);

                event->ignore();

            }
            else if(this->windowState() && (Qt::WindowMaximized)){


                //event->ignore();
            }

            break;

        }
    default:
        break;


    }

    QMainWindow::changeEvent(event);
}



void MainWindow::changeLabelText(){

    QString text = "<html><span style='font-size:10pt;maring-top:0px;font-weight:bold;color:#b0970c'>";

            text+= "Pc Name : ";
            text+= this->hostname;
            text+= "<br><br>";

            if(this->mainIp != ""){
                text    += "Your Ip : ";
                text    += this->mainIp;
                text    +="<br>";
            }
            else
            text += "<span sytle='color:red'><br>Sorry network not found.<br>*Please check your local <br> network(wifi) connection <br>And restart this application<br></span>";

            if(this->othersLocalIp != ""){
            text+= "<br>Other local Ip list : <br>";

                text+= this->othersLocalIp;
                text+= "<br>";

            }



            text+= "<br><br>*If your device unables to find your pc<br>Add each ip at a time in your android<br> mousepad app and try to connect";
            text += "</span></html>";

//    ui->DetailsLabel->style('font-size:10pt;maring-top:0px;font-weight:bold;color:#129ce2');

            ui->DetailsLabel->setStyleSheet("QLabel {background:#f4fde3;padding:5px;font-size:10pt;maring-top:0px;font-weight:bold;}");
            ui->DetailsLabel->setText(text);
            ui->graphicsView->setStyleSheet("QGraphicsView {background-color:#f4fde3;background-image: url(:/external/back4.png);}");



}




void MainWindow::closeEvent (QCloseEvent *event)
{

    hide();

    tray->showMessage("Hi","I'm here",QSystemTrayIcon::Information,30);

    event->ignore();

    /*if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }*/
}




void MainWindow::ShowAbout(){
    QMessageBox msgBox;
    msgBox.setText("MousePad is an open source software\nEnjoy! \n\nmehedee.hassan@outlook.com");
   msgBox.open();

}


void MainWindow::updateUI(){


//    QString mainIp = this->myserver->findMainIp();
//    QString othersLocalIp = this->myserver->getAllLocalIp();
//    QString hostname = this->myserver->getLocalHoseName();


//    setIpInformation( mainIp , othersLocalIp, hostname);

//    changeLabelText();


}



void MainWindow::setIpInformation(QString mainIp ,QString othersLocalIp,QString hostname){
    this->mainIp = mainIp;
    this->othersLocalIp = othersLocalIp;
    this->hostname = hostname;



    changeLabelText();
}



void MainWindow::setIpInformation(QString mainIp ,QString othersLocalIp,QString hostname,MyServer *server){
    this->mainIp = mainIp;
    this->othersLocalIp = othersLocalIp;
    this->hostname = hostname;

    this->myserver = server;

    changeLabelText();
}

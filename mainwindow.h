#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include "myserver.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;

    explicit MainWindow(QWidget *parent = 0);

    void setIpInformation(QString mainIp ,QString othersLocalIp,QString hostname);

    void setUpThisUI();



    void changeLabelText();

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void ExitApplication();
    void ShowAbout();

private:
    QSystemTrayIcon *tray;
    QMenu *trayIconMenu;
    QAction *restoreAction;
    QAction *closeAction,*aboutAction;
    QIcon trayIcon;
    QString mainIp;
    QString othersLocalIp,hostname;

    void createTray();
    void changeEvent(QEvent* event);

    void closeEvent (QCloseEvent *event);




    };


#endif // MAINWINDOW_H

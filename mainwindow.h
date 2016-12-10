#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void ExitApplication();
    void ShowAbout();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *tray;
    QMenu *trayIconMenu;
    QAction *restoreAction;
    QAction *closeAction,*aboutAction;
    QIcon trayIcon;
    void createTray();
    void changeEvent(QEvent* event);
    void changeLabelText();
    void closeEvent (QCloseEvent *event);

};


#endif // MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *DetailsLabel;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(465, 403);
        QIcon icon;
        icon.addFile(QStringLiteral(":/back3.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DetailsLabel = new QLabel(centralWidget);
        DetailsLabel->setObjectName(QStringLiteral("DetailsLabel"));
        DetailsLabel->setGeometry(QRect(180, 0, 291, 411));
        DetailsLabel->setAutoFillBackground(false);
        DetailsLabel->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 8pt \"Nirmala UI\";\n"
"padding:5px;"));
        DetailsLabel->setFrameShadow(QFrame::Sunken);
        DetailsLabel->setLineWidth(0);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(-130, 0, 311, 461));
        graphicsView->setStyleSheet(QLatin1String("background-image: url(:/external/back4.png);\n"
"font: 8pt \"Segoe Print\";\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
""));
        graphicsView->setFrameShape(QFrame::Panel);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MousePad", 0));
        DetailsLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Ip list</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

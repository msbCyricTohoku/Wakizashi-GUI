/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_data;
    QAction *actionTweaks;
    QAction *actionGen_txt;
    QAction *actionQuit;
    QAction *actionabout;
    QAction *actionSave_data_binary;
    QAction *actionConvert_binary_to_txt;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QProgressBar *progressBar;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuEdit_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1050, 625);
        actionLoad_data = new QAction(MainWindow);
        actionLoad_data->setObjectName(QString::fromUtf8("actionLoad_data"));
        actionTweaks = new QAction(MainWindow);
        actionTweaks->setObjectName(QString::fromUtf8("actionTweaks"));
        actionGen_txt = new QAction(MainWindow);
        actionGen_txt->setObjectName(QString::fromUtf8("actionGen_txt"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName(QString::fromUtf8("actionabout"));
        actionSave_data_binary = new QAction(MainWindow);
        actionSave_data_binary->setObjectName(QString::fromUtf8("actionSave_data_binary"));
        actionConvert_binary_to_txt = new QAction(MainWindow);
        actionConvert_binary_to_txt->setObjectName(QString::fromUtf8("actionConvert_binary_to_txt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font;
        font.setPointSize(11);
        tableWidget->setFont(font);
        tableWidget->setAcceptDrops(true);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, -1, 0);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);

        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_2->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_4->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1050, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit_2 = new QMenu(menubar);
        menuEdit_2->setObjectName(QString::fromUtf8("menuEdit_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit_2->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionLoad_data);
        menuFile->addAction(actionTweaks);
        menuFile->addAction(actionGen_txt);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionabout);
        menuEdit_2->addAction(actionSave_data_binary);
        menuEdit_2->addAction(actionConvert_binary_to_txt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Wakizashi", nullptr));
        actionLoad_data->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad_data->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTweaks->setText(QCoreApplication::translate("MainWindow", "Tweaks", nullptr));
#if QT_CONFIG(shortcut)
        actionTweaks->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGen_txt->setText(QCoreApplication::translate("MainWindow", "Gen txt", nullptr));
#if QT_CONFIG(shortcut)
        actionGen_txt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionabout->setText(QCoreApplication::translate("MainWindow", "info", nullptr));
#if QT_CONFIG(shortcut)
        actionabout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_data_binary->setText(QCoreApplication::translate("MainWindow", "Save data (binary)", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_data_binary->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConvert_binary_to_txt->setText(QCoreApplication::translate("MainWindow", "Convert binary to txt", nullptr));
#if QT_CONFIG(shortcut)
        actionConvert_binary_to_txt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "Program outputs:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Progress:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Tweaks", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Filter data", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Save data (binary)", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Convert binary to txt", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Imputation + matching", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Analysis control", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuEdit_2->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

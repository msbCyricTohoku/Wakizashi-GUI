/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QRect>
#include <QTextBlock>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPlainTextEdit>
#include <QFont>
#include <QTextFormat>
#include <QTextCursor>
#include <QMessageBox>
#include "tweaks.h"
#include "analysis.h"
#include "analysiscontrol.h"

class QSqlTableModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidget_cellActivated(int row, int column);


    void on_pushButton_2_clicked();

    void paste();



    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_3_clicked();

    void on_actionabout_triggered();

    void on_actionLoad_data_triggered();

    void on_actionTweaks_triggered();

    void on_actionGen_txt_triggered();

    void on_actionQuit_triggered();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_actionSave_data_binary_triggered();

    void on_actionConvert_binary_to_txt_triggered();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *mModel;
     tweaks *tweak;
    analysis *analysisD;
     analysiscontrol *analysisC;

    void TableWidgetDisplay();
};
#endif // MAINWINDOW_H

/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QDialog>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLayout>
#include <QMessageBox>
#include <QFont>
#include <QWidget>
#include <QRadioButton>
#include <QFile>
#include <QPixmap>
#include <QTextStream>
#include <QProcess>
#include <QDebug>
#include <QtDebug>

class analysis : public QDialog
{
    Q_OBJECT

public:
    explicit analysis(QWidget *parent = nullptr);
    ~analysis();

private slots:
    void on_analyze_clicked();

private:
    void initializeWidgets();
    void initializeLayout();

    QLabel *instructionLabel;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QRadioButton *radioButton5;
    QRadioButton *radioButton6;
    QRadioButton *radioButton7;
    QButtonGroup *radioButtonGroup;
    QPushButton *analyzeButton;

    QLabel *label1;
    QLabel *label2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;

    QVBoxLayout *mainLayout;
    QVBoxLayout *optionsLayout;
    QHBoxLayout *inputLayout1;
    QHBoxLayout *inputLayout2;
};

#endif // ANALYSIS_H

/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#ifndef ANALYSISCONTROL_H
#define ANALYSISCONTROL_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class analysiscontrol : public QDialog
{
    Q_OBJECT

public:
    explicit analysiscontrol(QWidget *parent = nullptr);
    ~analysiscontrol();

private slots:
    void on_submit_clicked();

private:
    void initializeWidgets();
    void initializeLayout();

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QPushButton *submitButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout1;
    QHBoxLayout *inputLayout2;
    QHBoxLayout *inputLayout3;
    QHBoxLayout *inputLayout4;
};

#endif // ANALYSISCONTROL_H

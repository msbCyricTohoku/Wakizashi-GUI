/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#ifndef TWEAKS_H
#define TWEAKS_H
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
#include <sstream>
#include <QTextStream>
#include <QProcess>
#include <QDebug>
#include <QtDebug>


class tweaks: public QDialog
{
    Q_OBJECT
public:
    //tweaks();
    tweaks(QWidget *parent = nullptr);
    ~tweaks();

public slots:
    void on_paramset_clicked();

private:
    void initializeWidgets2();
    void initializeLayout2();

    QLabel *op1Label;
    QLabel *op2Label;
    QLabel *op3Label;
  //  QLabel *op4Label;
  //  QLabel *op5Label;

    QLineEdit *ompLineEdit;
    QLineEdit *icntlLineEdit;
    QLineEdit *maxcasLineEdit;
  //  QLineEdit *maxbchLineEdit;
  //  QLineEdit *fileLineEdit;

    QPushButton *paramButton;

    QVBoxLayout *parameterHorizontalLayout;
    QVBoxLayout *optionsLayout;
    QVBoxLayout *verticalLayout;
};

#endif // TWEAKS_H

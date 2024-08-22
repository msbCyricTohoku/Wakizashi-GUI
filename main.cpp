/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    QCoreApplication::setApplicationName("Wakizashi");
    w.setWindowIcon(QIcon("resources/icon.ico"));
    w.show();
    return a.exec();
}

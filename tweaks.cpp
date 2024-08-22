/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#include "tweaks.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QTimer>

tweaks::tweaks(QWidget *parent)
    : QDialog(parent)
{

    initializeWidgets2();

    setFocusProxy(ompLineEdit);

    initializeLayout2();

    setWindowTitle(tr("Tweak data"));
    resize(800, 200);

    connect(paramButton, SIGNAL(clicked()), this, SLOT(on_paramset_clicked()));

}

tweaks::~tweaks()
{
    delete op1Label;
    delete op2Label;
    delete op3Label;
  //  delete op4Label;
  //  delete op5Label;

    delete ompLineEdit;
    delete icntlLineEdit;
    delete maxcasLineEdit;
   // delete maxbchLineEdit;
  //  delete fileLineEdit;
    delete paramButton;
    delete parameterHorizontalLayout;
    delete optionsLayout;
    delete verticalLayout;

}

void tweaks::on_paramset_clicked()
{

    QString op1 = ompLineEdit->text();

     QStringList featuredrops = op1.split(";");

    for(int i =0; i < featuredrops.count(); i++){
        // featuredrops[i].remove(" ");
     }

    QString op2 = icntlLineEdit->text();

    QStringList featureconvert = op2.split(";");

    for(int i =0; i < featureconvert.count(); i++){
         featureconvert[i].remove(" ");
    }

    QString op3 = maxcasLineEdit->text();

    int totalcounts = featuredrops.count()+featureconvert.count()+1;

    const QString qPath("param.tmp");
    QFile qfile(qPath);
    if (qfile.open(QIODevice::WriteOnly)) {
        QTextStream out17(&qfile);
        out17 << QString::number(totalcounts)+"\n";

        for (int i=0; i < featuredrops.count(); i++){out17 << featuredrops.at(i)+"\n";}

        for (int i=0; i < featureconvert.count(); i++){out17 << featureconvert.at(i)+"\n";}

        out17 << op3;

        qfile.close();

    }


    this->close();
}

void tweaks::initializeWidgets2()
{
    QFont f( "Arial", 12, QFont::Normal);

    op1Label = new QLabel(tr("Columns to remove:    "));

    op2Label = new QLabel(tr("Values to convert:    "));
    op2Label->setFont(f);

    op3Label = new QLabel(tr("Missing data key:    "));
    op3Label->setFont(f);



    paramButton = new QPushButton(tr("Add filters"));
    paramButton->setFont(f);


    ompLineEdit = new QLineEdit();
    icntlLineEdit = new QLineEdit();
    maxcasLineEdit = new QLineEdit();


    ompLineEdit->setText("Baseline Date;Date of Birth (yyyy-mm-dd);Today Date;Date of Registered Death;Death Cause (Main Cause)");
    icntlLineEdit->setText("F > 0;M > 1");
    maxcasLineEdit->setText("NaN");


    ompLineEdit->setMinimumWidth(50);
    icntlLineEdit->setMinimumWidth(50);
    maxcasLineEdit->setMinimumWidth(50);

    ompLineEdit->setFont(f);
    icntlLineEdit->setFont(f);
    maxcasLineEdit->setFont(f);

}

void tweaks::initializeLayout2()
{

    parameterHorizontalLayout = new QVBoxLayout();
    optionsLayout = new QVBoxLayout();
    verticalLayout = new QVBoxLayout();


    verticalLayout->addLayout(parameterHorizontalLayout);
    verticalLayout->addLayout(optionsLayout);


    parameterHorizontalLayout->addWidget(op1Label);
    parameterHorizontalLayout->addWidget(ompLineEdit);

    parameterHorizontalLayout->addWidget(op2Label);
    parameterHorizontalLayout->addWidget(icntlLineEdit);


    parameterHorizontalLayout->addWidget(op3Label);
    parameterHorizontalLayout->addWidget(maxcasLineEdit);

    optionsLayout->addWidget(paramButton);


    setLayout(verticalLayout);
}

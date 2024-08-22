/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#include "analysiscontrol.h"
#include <QFile>
#include <QTextStream>

analysiscontrol::analysiscontrol(QWidget *parent)
    : QDialog(parent)
{
    initializeWidgets();
    initializeLayout();
    setWindowTitle(tr("Analysis Control"));
    resize(800, 300);


    connect(submitButton, SIGNAL(clicked()), this, SLOT(on_submit_clicked()));
}

analysiscontrol::~analysiscontrol()
{
    delete label1;
    delete label2;
    delete lineEdit1;
    delete lineEdit2;
    delete label3;
    delete label4;
    delete lineEdit3;
    delete lineEdit4;
    delete submitButton;
    delete mainLayout;
    delete inputLayout1;
    delete inputLayout2;
    delete inputLayout3;
    delete inputLayout4;
}

void analysiscontrol::on_submit_clicked()
{
    QString input1 = lineEdit1->text();
    QString input2 = lineEdit2->text();
    QString input3 = lineEdit3->text();
    QString input4 = lineEdit4->text();

    const QString filePath("analysis_control_result.tmp");
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << input1.remove(",").replace(" ", "-").replace("/", "-") << "\n";
        out << input2.remove(",").replace(" ", "-").replace("/", "-") << "\n";
        out << input3.remove(",").replace(" ", "-").replace("/", "-") << "\n";
        out << input4.remove(",").replace(" ", "-").replace("/", "-") << "\n";
        file.close();
    }

    this->close();
}

void analysiscontrol::initializeWidgets()
{
    QFont font("Arial", 12, QFont::Normal);

    label1 = new QLabel(tr("Enter treatment variable:"));
    label2 = new QLabel(tr("Enter covariate(s):"));
    label1->setFont(font);
    label2->setFont(font);

    lineEdit1 = new QLineEdit();
    lineEdit2 = new QLineEdit();
    lineEdit1->setFont(font);
    lineEdit2->setFont(font);

    lineEdit1->setText("PCSK9 inhibitor v.s. Eztimibe");
    lineEdit2->setText("Male gender;Cancer;Fasting glucose, mmol/L");

    label3 = new QLabel(tr("Enter Time Column for multivariate Cox regression:"));
    label4 = new QLabel(tr("Enter Event Column for multivariate Cox regression:"));
    label3->setFont(font);
    label4->setFont(font);

    lineEdit3 = new QLineEdit();
    lineEdit4 = new QLineEdit();
    lineEdit3->setFont(font);
    lineEdit4->setFont(font);

    lineEdit3->setText("Time-to-MACE-years");
    lineEdit4->setText("MACE;All-cause mortality");

    submitButton = new QPushButton(tr("Submit"));
    submitButton->setFont(font);
}

void analysiscontrol::initializeLayout()
{
    mainLayout = new QVBoxLayout();
    inputLayout1 = new QHBoxLayout();
    inputLayout2 = new QHBoxLayout();
    inputLayout3 = new QHBoxLayout();
    inputLayout4 = new QHBoxLayout();

    inputLayout1->addWidget(label1);
    inputLayout1->addWidget(lineEdit1);

    inputLayout2->addWidget(label2);
    inputLayout2->addWidget(lineEdit2);

    inputLayout3->addWidget(label3);
    inputLayout3->addWidget(lineEdit3);

    inputLayout4->addWidget(label4);
    inputLayout4->addWidget(lineEdit4);

    mainLayout->addLayout(inputLayout1);
    mainLayout->addLayout(inputLayout2);
    mainLayout->addLayout(inputLayout3);
    mainLayout->addLayout(inputLayout4);
    mainLayout->addWidget(submitButton);

    setLayout(mainLayout);
}

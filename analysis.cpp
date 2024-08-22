/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#include "analysis.h"

analysis::analysis(QWidget *parent)
    : QDialog(parent)
{
    initializeWidgets();
    initializeLayout();
    setWindowTitle(tr("Imputation and propensity score matching"));

    radioButton1->setChecked(true);

    connect(analyzeButton, SIGNAL(clicked()), this, SLOT(on_analyze_clicked()));
}

analysis::~analysis()
{
    delete instructionLabel;
    delete radioButton1;
    delete radioButton2;
    delete radioButton3;
    delete radioButton4;
    delete radioButton5;
    delete radioButton6;
    delete radioButton7;
    delete radioButtonGroup;
    delete analyzeButton;
    delete label1;
    delete label2;
    delete lineEdit1;
    delete lineEdit2;
    delete mainLayout;
    delete optionsLayout;
    delete inputLayout1;
    delete inputLayout2;
}

void analysis::on_analyze_clicked()
{
    int selectedId = radioButtonGroup->checkedId();

    QString selectedOption;
    switch (selectedId) {
    case 1:
        selectedOption = "method1";
        break;
    case 2:
        selectedOption = "method2";
        break;
    case 3:
        selectedOption = "method3";
        break;
    case 4:
        selectedOption = "method4";
        break;
    case 5:
        selectedOption = "method5";
        break;
    case 6:
        selectedOption = "method6";
        break;
    case 7:
        selectedOption = "method7";
        break;
    default:
        selectedOption = "empty";
        break;
    }

    QString input1 = lineEdit1->text();
    QString input2 = lineEdit2->text();

    const QString filePath("analysis_result.tmp");
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << selectedOption << "\n";
        out << input1.split(":").last() << "\n";
        out << input2 << "\n";
        file.close();
    }

    this->close();
}

void analysis::initializeWidgets()
{
    QFont font("Arial", 12, QFont::Normal);

    instructionLabel = new QLabel(tr("Please select one of the automated imputation methods:"));
    instructionLabel->setFont(font);

    radioButton1 = new QRadioButton(tr("Mean Imputation"));
    radioButton2 = new QRadioButton(tr("Mode Imputation"));
    radioButton3 = new QRadioButton(tr("k-nearest neighbors (KNN) Imputation"));
    radioButton4 = new QRadioButton(tr("Multivariate Chained Equations (MCE) Imputation"));
    radioButton5 = new QRadioButton(tr("Linear Interpolation Imputation"));
    radioButton6 = new QRadioButton(tr("HistGradientBoostingRegressor Imputation"));
    radioButton7 = new QRadioButton(tr("Multiple Imputation"));

    radioButton1->setFont(font);
    radioButton2->setFont(font);
    radioButton3->setFont(font);
    radioButton4->setFont(font);
    radioButton5->setFont(font);
    radioButton6->setFont(font);
    radioButton7->setFont(font);

    radioButtonGroup = new QButtonGroup(this);
    radioButtonGroup->addButton(radioButton1, 1);
    radioButtonGroup->addButton(radioButton2, 2);
    radioButtonGroup->addButton(radioButton3, 3);
    radioButtonGroup->addButton(radioButton4, 4);
    radioButtonGroup->addButton(radioButton5, 5);
    radioButtonGroup->addButton(radioButton6, 6);
    radioButtonGroup->addButton(radioButton7, 7);

    analyzeButton = new QPushButton(tr("Submit"));
    analyzeButton->setFont(font);

    label1 = new QLabel(tr("Propensity score matching ratio:"));
    label2 = new QLabel(tr("Caliper:"));
    label1->setFont(font);
    label2->setFont(font);



    lineEdit1 = new QLineEdit();
    lineEdit2 = new QLineEdit();
    lineEdit1->setFont(font);
    lineEdit2->setFont(font);

    lineEdit1->setText("1:3");
    lineEdit2->setText("0.1");
}

void analysis::initializeLayout()
{
    mainLayout = new QVBoxLayout();
    optionsLayout = new QVBoxLayout();
    inputLayout1 = new QHBoxLayout();
    inputLayout2 = new QHBoxLayout();

    mainLayout->addWidget(instructionLabel);
    mainLayout->addWidget(radioButton1);
    mainLayout->addWidget(radioButton2);
    mainLayout->addWidget(radioButton3);
    mainLayout->addWidget(radioButton4);
    mainLayout->addWidget(radioButton5);
    mainLayout->addWidget(radioButton6);
    mainLayout->addWidget(radioButton7);

    inputLayout1->addWidget(label1);
    inputLayout1->addWidget(lineEdit1);

    inputLayout2->addWidget(label2);
    inputLayout2->addWidget(lineEdit2);

    mainLayout->addLayout(inputLayout1);
    mainLayout->addLayout(inputLayout2);
    optionsLayout->addWidget(analyzeButton);

    mainLayout->addLayout(optionsLayout);
    setLayout(mainLayout);


}

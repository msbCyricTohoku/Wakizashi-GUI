/*
    * Wakizashi
        * An automated propensity score matching, data imputation and multivariate Cox regression package

        * Developed by: Gary Tse, Abigail Beck (Choi Chi Hong), Rosia Li, Quinncy Lee and Mehrdad S. Beni -- 2024
        * Jockey Club Institute of Healthcare, Hong Kong Metropolitan University (HKMU)

        * All rights reserved.
        * DO NOT DISTRIBUTE WITHOUT PERMISSION.
*/
#include <Python.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QShortcut>
#include <QSqlTableModel>
#include <QClipboard>
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>       /* time */
#include <ctype.h>
#include <ctime>
#include <stdio.h>
#include <QMessageBox>
#include <QPixmap>
#include <sstream>
#include <QtPrintSupport/QPrinter>      // printing
#include <QtPrintSupport/QPrintDialog>  // printing
#include <QFileDialog>                  // file open/save dialogs
#include <QFile>                        // file descriptors, IO
#include <QTextStream>                  // file IO
#include <QStandardPaths>               // default open directory
#include <QDateTime>                    // current time
#include <QApplication>                 // quit
#include <unistd.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tweak = new tweaks();

    tweak->setParent(this, Qt::Tool | Qt::MSWindowsFixedSizeDialogHint);

    analysisD = new analysis();
    analysisD->setParent(this, Qt::Tool | Qt::MSWindowsFixedSizeDialogHint);

    analysisC = new analysiscontrol();
    analysisC->setParent(this, Qt::Tool | Qt::MSWindowsFixedSizeDialogHint);


    mModel = new QSqlTableModel(this);
    mModel->setTable("test_table");
    mModel->select();

    int systemRet = system("rm *.tmp");
    if(systemRet == -1){}
   // ui->tableWidget->setModel(mModel);
   // ui->lineEdit->setText("no");
    //QFont font = ui->tableWidget->horizontalHeader()->font();
   // QFont font = ui->tableWidget->horizontalHeader()->font();
   // font.setPointSize( 16 );
   // ui->tableWidget->setFont(font);
   // int systemRet2 = system("python3 main.py");
   // if(systemRet2 == -1){}

}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList splitCSVLine(QString &line)
{
    QStringList fields;
    QString value;
    bool insideQuotes = false;

    for (int i = 0; i < line.size(); ++i) {
        QChar current = line[i];

        // If inside quotes, append anything (including commas) to the current value
        if (insideQuotes) {
            if (current == '\"') {
                insideQuotes = false;
            } else {
                value += current;
            }
        } else {
            // If outside quotes, split on commas
            if (current == ',') {
                fields << value;
                value.clear();
            } else if (current == '\"') {
                insideQuotes = true;
            } else {
                value += current;
            }
        }
    }

    // Append the last field
    if (!value.isEmpty()) {
        fields << value;
    }

    return fields;
}


void MainWindow::TableWidgetDisplay(){
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(400);
    table->setColumnCount(400);

    this->setCentralWidget(table);
}


void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->insertPlainText("****************\n");
     ui->tableWidget->clear();
     ui->tableWidget->setRowCount(0);
     ui->tableWidget->setColumnCount(0);

     //   QString dummy;
     QString filepath = QFileDialog::getOpenFileName(this, "Choose file", "/home/");
     if (filepath.isEmpty())
         return;
     //OpenFile(filepath);
     const QString qPath15("openedfile.tmp");
     QFile qFile15(qPath15);
     if (qFile15.open(QIODevice::WriteOnly)) {
         QTextStream out15(&qFile15);
         out15 << filepath;
         qFile15.close();
     }

     ui->textBrowser->insertPlainText(filepath+" is now opened"+"\n");
     //  on_pushButton_9_clicked(filepath);

     QStringList fields1;
     QStringList fields;
     QString linehead;

     int datarowcount=0;
     int datacolumncount=0;
     //call the statistical analyzer here
     const QString inputdata("openedfile.tmp");
     QFile inputfile(inputdata);


     if (inputfile.open(QIODevice::ReadOnly)) {
     }
     QString content = inputfile.readAll();
     inputfile.close();

     ui->textBrowser->insertPlainText("analyzer: "+content+"\n");


     const QString inputdatax(content);
     QFile input(inputdatax);
     if(input.open(QIODevice::ReadOnly)){
         QTextStream inp(&input);
         linehead = inp.readLine();

         while(!inp.atEnd()) {

            datarowcount++;
            QString line = inp.readLine();
            QStringList columns = line.split(",");
            fields.append(columns.join(","));
            fields1 = columns;
            datacolumncount = fields1.count();
         }
     }
     input.close();
     input.close();


     // QStringList strList = linehead.split(QRegExp("[\n]"),QString::SkipEmptyParts);

     //QStringList listsource = strList.at(i).split(" ");

    // qDebug() << splitCSVLine(linehead);

     QStringList cleanedhead = splitCSVLine(linehead);


     ui->textBrowser->insertPlainText("number of rows: "+QString::number(datarowcount)+"\n");
     ui->textBrowser->insertPlainText("number of columns: "+QString::number(datacolumncount)+"\n");

     // TableWidgetDisplay();
     int row = datarowcount;
     int col = datacolumncount;



     on_tableWidget_cellActivated(row+1, col);

     QShortcut *shortcut_paste = new QShortcut(QKeySequence::Paste, ui->tableWidget);
     connect(shortcut_paste, &QShortcut::activated, this, &MainWindow::paste);


     // Set the number of rows in the table widget
     ui->tableWidget->setRowCount(fields.size()+1);

     // Iterate over each row in fields
     for (int i = 0; i < fields.size(); ++i) {
         //ui->tableWidget->setHorizontalHeaderLabels(cleanedhead);

         // Split the row into columns
         QStringList columns = fields[i].split(",");

         // Set the number of columns in the table widget
         ui->tableWidget->setColumnCount(columns.size());

         // Iterate over each column
         for (int j = 0; j < columns.size(); ++j) {
             // Create a new item with the column text
             QTableWidgetItem *item = new QTableWidgetItem(columns[j]);
            QTableWidgetItem *item2 = new QTableWidgetItem(cleanedhead[j]);
                ui->tableWidget->setItem(0,j,item2);
             // Add the item to the table widget
             ui->tableWidget->setItem(i+1, j, item);
         }
     }
}

void MainWindow::paste()
{
    QModelIndex start = ui->tableWidget->selectionModel()->selectedIndexes().first();
    QString text = QApplication::clipboard()->text();
    int i=0, j=0;
    for(const QString & row_string:  text.split("\n", Qt::SkipEmptyParts)){
        j=0;
        for(const QString & col:  row_string.split("\t", Qt::SkipEmptyParts)){
            QModelIndex ix = mModel->index(start.row() + i , start.column()+ j);
            if(ix.isValid()){
                ui->tableWidget->model()->setData(ix, col);
                mModel->submit();
            }
            j++;
        }
        i++;
    }
}

bool containLetter(QChar letter, QString myString)
{

    if(myString.contains(letter)){return true;}
    else{return false;}

}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->insertPlainText("****************\n");

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    QString op[5];
    QString filters;



    const QString qPath151("param.tmp");
    QFile qFile151(qPath151);
    if (qFile151.open(QIODevice::ReadOnly)) {
        QTextStream out151(&qFile151);
        filters = out151.readLine();
        qFile151.close();
    }

    int nfilter = filters.toInt();

    QString commands[nfilter];

    QString missing;

    const QString qPath151x("param.tmp");
    QFile qFile151x(qPath151x);
    if (qFile151x.open(QIODevice::ReadOnly)) {
        QTextStream out151x(&qFile151x);
        filters = out151x.readLine();

        for (int i=0; i <nfilter-1; i++){

            commands[i] = out151x.readLine();

            //  qDebug() << commands[i];

        }

        missing = out151x.readLine();

       // qDebug() << "missing" << missing;

        qFile151.close();
    }

   // qDebug() << missing;

    int dropcount = 0;
    int convertcount =0;
    bool convert = false;
    for(int i=0; i < nfilter-1; i++){
        convert = containLetter('>',commands[i]);
        if(convert == true){convertcount++;}

    }

    dropcount = (nfilter-1) - convertcount;

    QVector<QString> conversion(convertcount);
    QStringList convertlist;
    QVector<QString> toconv(convertcount);
    QVector<QString> convto(convertcount);

    for (int i =0; i < convertcount; i++){
         conversion[i] = commands[i+dropcount];

         convertlist = conversion[i].split(">");

        toconv[i] = convertlist[0];

        convto[i] = convertlist[1];
    }

    ui->progressBar->setValue(0);
    QStringList fields1;
    QStringList fields;
    QString linehead;

    int datarowcount=0;
    int datacolumncount=0;

    const QString inputdata("openedfile.tmp");
    QFile inputfile(inputdata);

    if (inputfile.open(QIODevice::ReadOnly)) {
    }
    QString content = inputfile.readAll();
    inputfile.close();

    ui->textBrowser->insertPlainText("\n");
    ui->textBrowser->insertPlainText("filepath : "+content+"\n");


       QStringList cleanedhead;
    const QString inputdatax(content);
    QFile input(inputdatax);
    if(input.open(QIODevice::ReadOnly)){
        QTextStream inp(&input);
        linehead = inp.readLine();

        cleanedhead = splitCSVLine(linehead);

        int indices[dropcount];
        //QVector<int> indices(dropcount);
        int index=0;
        for(int i=0; i < dropcount; i++){
            index = cleanedhead.indexOf(commands[i]);
            indices[i] = index;
            cleanedhead.removeAll(commands[i]);
         //  qDebug() << commands[i];
        }

        int indices2[dropcount];
        //QVector<int> indices2(dropcount);
        for(int i=0; i <dropcount; i++){
            if(indices[i] != -1){
                indices2[i] = indices[i];

            }
        }


        while(!inp.atEnd()) {

            datarowcount++;
            QString line = inp.readLine();
            QStringList columns = line.split(",");
            for (int i=0; i < dropcount; i++){
            if (columns.size() > indices2[i]) {
                columns.removeAt(indices2[i]);
            }
            }
            fields.append(columns.join(","));
            fields1 = columns;
            datacolumncount = fields1.count();
        }
    }
    input.close();

    ui->textBrowser->insertPlainText("number of rows: "+QString::number(datarowcount)+"\n");
    ui->textBrowser->insertPlainText("number of columns: "+QString::number(datacolumncount-dropcount)+"\n");

    QShortcut *shortcut_paste = new QShortcut(QKeySequence::Paste, ui->tableWidget);
    connect(shortcut_paste, &QShortcut::activated, this, &MainWindow::paste);


    const QString qPath2("header.txt");
    QFile qFile2(qPath2);
    if (qFile2.open(QIODevice::WriteOnly)) {
        QTextStream out2(&qFile2);

        for(int i=0; i < datacolumncount; i++){
            cleanedhead[i].remove(",");
            cleanedhead[i].replace(" ", "-");
            cleanedhead[i].replace("/", "-");
            out2 << cleanedhead.at(i) << Qt::endl;
        }
    }
    qFile2.close();


    const QString qPath23("arraysize.txt");
    QFile qFile23(qPath23);
    if (qFile23.open(QIODevice::WriteOnly)) {
        QTextStream out23(&qFile23);

        out23 << "rows " << datarowcount << Qt::endl;
            out23 << "columns " << datacolumncount << Qt::endl;

    }
    qFile23.close();



    ui->textBrowser->insertPlainText("Applying filter... \n");

    // Set the number of rows in the table widget
    ui->tableWidget->setRowCount(fields.size());
  //  ui->progressBar->setRange(0, datarowcount*(datacolumncount-dropcount));
    //int k=0;
    // Iterate over each row in fields
    for (int i = 0; i < fields.size(); ++i) {
         ui->tableWidget->setHorizontalHeaderLabels(cleanedhead);
         // Split the row into columns
         QStringList columns = fields[i].split(",");

         // Set the number of columns in the table widget
         ui->tableWidget->setColumnCount(columns.size());

         // Iterate over each column
         for (int j = 0; j < columns.size(); ++j) {

            for(int k=0; k < convertcount; k++){
            columns[j].replace(toconv[k],convto[k]);
            }


            if(columns.at(j).isEmpty()){
            columns.replace(j,missing);
            }
             // Create a new item with the column text
             QTableWidgetItem *item = new QTableWidgetItem(columns[j]);

            //qDebug() << columns[j];


             // Add the item to the table widget
             ui->tableWidget->setItem(i, j, item);
          //   ui->progressBar->setValue(k);

          //   k++;
         }
    }

    ui->textBrowser->insertPlainText("Filter applied! \n");


    // unsigned int microsec = 1000;
    const QString qPath("commands.tmp");
    QFile qFile(qPath);
    if (qFile.open(QIODevice::WriteOnly)) {
         QTextStream out(&qFile);
         out << QString::number(datarowcount)+"\n";
         out << QString::number(datacolumncount)+"\n";
         out << QString::number(dropcount);
         qFile.close();
    }

}


void MainWindow::on_pushButton_4_clicked()
{
     QApplication::quit();
}


void MainWindow::on_pushButton_5_clicked()
{
     tweak->show();
     tweak->activateWindow();
     tweak->raise();
     tweak->setFocus();
}


void MainWindow::on_pushButton_3_clicked()
{
     QMessageBox msgAbout;
     msgAbout.setInformativeText("-- Wakizashi --\n\nAn automated \npropensity score matching, data imputation and multivariate Cox regression package.\n\nHKMU\nMehrdad S. Beni\nGary Tse\n2024");
     QPixmap pixAbout;
     pixAbout.load("resources/wakizashi.png");
     msgAbout.setIconPixmap(pixAbout);
     msgAbout.setStandardButtons(QMessageBox::Close);
     msgAbout.setDefaultButton(QMessageBox::Close);
     msgAbout.exec();

}


void MainWindow::on_actionabout_triggered()
{
     ui->pushButton_3->click();
}


void MainWindow::on_actionLoad_data_triggered()
{
     ui->pushButton_2->click();
}


void MainWindow::on_actionTweaks_triggered()
{
     ui->pushButton_5->click();
}




void MainWindow::on_actionGen_txt_triggered()
{
     ui->pushButton->click();
}



void MainWindow::on_actionQuit_triggered()
{
     ui->pushButton_4->click();
}


void MainWindow::on_pushButton_6_clicked()
{

     QString filepath = QFileDialog::getSaveFileName(this, tr("Save File"), "./" , tr("Binary Files (*.bin)"));
     if (filepath.isEmpty())
         return;
     if (QFileInfo(filepath).suffix().isEmpty())
         filepath.append(".bin");



     QString filenameWithoutExtension = QFileInfo(filepath).completeBaseName();


     const QString qPatht("userfilename.tmp");
     QFile qFilet(qPatht);
     if (qFilet.open(QIODevice::WriteOnly)) {
         QTextStream outt(&qFilet);
         outt << filenameWithoutExtension;
         qFilet.close();
     }

     qDebug() << filenameWithoutExtension << Qt::endl;

     ui->textBrowser->insertPlainText("****************\n");

      ui->progressBar->setValue(0);

     QStringList list;
     for(int row = 0; row < ui->tableWidget->rowCount(); ++row) {
         for(int col = 0; col < ui->tableWidget->columnCount(); ++col) {
             QTableWidgetItem* item = ui->tableWidget->item(row, col);
             if(item) {
            list << item->text();
             }
         }
     }

     QString datarowcountx;
     QString datacolumncountx;
     QString dropcountx;
     const QString qPath151("commands.tmp");
     QFile qFile151(qPath151);
     if (qFile151.open(QIODevice::ReadOnly)) {
         QTextStream out151(&qFile151);
         datarowcountx = out151.readLine();
         datacolumncountx = out151.readLine();
         dropcountx = out151.readLine();
         qFile151.close();
     }

     int datarowcount = datarowcountx.toInt();
     int datacolumncount = datacolumncountx.toInt();
     int dropcount = dropcountx.toInt();

    ui->textBrowser->insertPlainText("Data saving... \n");

    /*
    ui->progressBar->setRange(0, datarowcount*(datacolumncount-dropcount));

     const QString qPath(filepath);
     QFile qFile(qPath);
     if (qFile.open(QIODevice::WriteOnly)) {
         QTextStream out(&qFile);
         int k=0;
         for (int i = 0; i < list.size(); ++i) {
             QStringList columns = list[i].split(",");
             for (int j = 0; j < columns.size(); ++j) {

            out << columns[j] << Qt::endl;

            ui->progressBar->setValue(k);

            k++;

             }
         }

         qFile.close();
     }
*/

    ui->progressBar->setRange(0, datarowcount*(datacolumncount-dropcount));
     const QString qPath1(filepath);
     QFile qFile1(qPath1);
     if (qFile1.open(QIODevice::WriteOnly)) {
         QDataStream outbin(&qFile1);
         outbin.setVersion(QDataStream::Qt_5_10);
         int k=0;
         for (int i = 0; i < list.size(); ++i) {
             QStringList columns = list[i].split(",");
             for (int j = 0; j < columns.size(); ++j) {


            outbin << columns[j];

            ui->progressBar->setValue(k);

            k++;

             }
         }

         qFile1.close();
     }

     /*
     QString moveheader ="mv header.txt "+filepath;
     int systemRet2 = system(moveheader.toUtf8().constData());
     if(systemRet2 == -1){}

     QString movearraysize ="mv arraysize.txt "+filepath;
     int systemRet3 = system(moveheader.toUtf8().constData());
     if(systemRet3 == -1){}
   */
     ui->textBrowser->insertPlainText("Data saved! \n");

}

QString removeFilename(const QString &filePath) {
     QFileInfo fileInfo(filePath);
     return fileInfo.dir().absolutePath();
}



void MainWindow::on_pushButton_7_clicked()
{
     ui->textBrowser->insertPlainText("****************\n");

     QString filepath = QFileDialog::getOpenFileName(this, "Choose file", "./",tr("Binary Files (*.bin)"));
     if (filepath.isEmpty())
         return;

      QString filename = filepath.section("/",-1,-1);

      QString filepathabs = removeFilename(filepath);


      //ui->textBrowser->insertPlainText(filename.remove(".bin")+"\n");
      ui->textBrowser->insertPlainText(filename+" will be converted."+"\n");

     QFile file(filepath);
     if (!file.open(QIODevice::ReadOnly)) {
         // handle error
     }

     QDataStream in(&file);
     in.setVersion(QDataStream::Qt_5_10);

     QVector<QString> largeArray;
     QString element;

     while (!in.atEnd()) {
         in >> element;
         largeArray.push_back(element);

     }


     QFile qFile(filepathabs+"/"+filename.remove(".bin")+".txt");
     if (qFile.open(QIODevice::WriteOnly)) {
         QTextStream out(&qFile);
         //int k=0;

            for (const auto &element1 : largeArray) {
                //qDebug() << element1;
             out << element1 << Qt::endl;
            //ui->progressBar->setValue(k);
            //k++;
            }
         qFile.close();
     }

    ui->textBrowser->insertPlainText("Data saved in "+filename.remove(".bin")+".txt"+"\n");

}


void MainWindow::on_actionSave_data_binary_triggered()
{
    ui->pushButton_6->click();
}


void MainWindow::on_actionConvert_binary_to_txt_triggered()
{
    ui->pushButton_7->click();

}


void MainWindow::on_pushButton_8_clicked()
{
    analysisD->show();
    analysisD->activateWindow();
    analysisD->raise();
    analysisD->setFocus();
    ui->textBrowser->insertPlainText("Setting imputation method and propensity score matching parameters\n");

}


void MainWindow::on_pushButton_9_clicked()
{

    analysisC->show();
    analysisC->activateWindow();
    analysisC->raise();
    analysisC->setFocus();
    ui->textBrowser->insertPlainText("Setting statistical analysis control parameters\n");

}


void MainWindow::on_pushButton_10_clicked()
{
    QProcess *process = new QProcess(this);
    connect(process, &QProcess::started, []() {
        qDebug() << "Started!";
    });
    connect(process, &QProcess::readyRead, [this, process]() {
        QTextStream outputStream(process->readAllStandardOutput());
        ui->textBrowser->append(outputStream.readAll());
    });
    connect(process, &QProcess::readyReadStandardOutput, [this, process]() {
        QTextStream outputStream(process->readAllStandardOutput());
        ui->textBrowser->append(outputStream.readAll());
    });
    connect(process, &QProcess::readyReadStandardError, [this, process]() {
        QTextStream errorStream(process->readAllStandardError());
        ui->textBrowser->append(errorStream.readAll());
    });
    connect(process, qOverload<int, QProcess::ExitStatus>(&QProcess::finished), [this,
                                                                                 process](int exitCode,
                                                                                          QProcess::ExitStatus exitStatus) {
        ui->textBrowser->append(QString::number(exitCode) + " " + QString::number(exitStatus));
        process->deleteLater();
    });

    //   process->start("runphits.sh", QStringList()  << "/K cd %USERPROFILE%");

    process->start("bash", QStringList() << "./runstat.sh");




    ui->textBrowser->insertPlainText("Statistical analysis run done.\n");


    ui->textBrowser->insertPlainText("Check saved results under user_results directory.\n");

}


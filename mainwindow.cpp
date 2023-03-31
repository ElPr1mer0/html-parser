#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_butParseHtmlReport_clicked(){

    if(ui->editCoverageType->text().isEmpty()||ui->editEngineerName->text().isEmpty()){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure?", "Some fields are not filled! Do you want continue? ",
                                             QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::No) return;
    }

    REPORT report;
    report.readHtmlFile(this,ui->editEngineerName->text(),ui->editCoverageType->text());
}

void MainWindow::on_actionParseHtmlReport_triggered(){
    on_butParseHtmlReport_clicked();
}


void MainWindow::on_actionExit_triggered(){
    this->close();
}


void MainWindow::on_actionContextHelp_triggered(){
    QMessageBox::information(this, "Help","For correct program working you should:\n"
                                    "   1. In field 'Engineer name:' write your name;\n"
                                    "   2. In field 'Coverage type:' write type of coverage which you use;\n"
                                    "   3. Press button 'Parse html report';\n"
                                    "   4. After parsing you will see the dialog message, where you should choose create or rewrite excel file;\n"
                                    "   5. You just open the excel file and cheecking result;\n"
                                    "   6. Good luck! ");
}


void MainWindow::on_actionDeveloper_triggered(){
    QMessageBox::information(this, "Developer","This program was created by Ilya Kudlach!\n "
                                        "For all questions contact by ilya.kudlach@yandex.ru.");
}


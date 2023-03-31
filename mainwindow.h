#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "report.h"

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
    void on_butParseHtmlReport_clicked();

    void on_actionParseHtmlReport_triggered();

    void on_actionExit_triggered();

    void on_actionContextHelp_triggered();

    void on_actionDeveloper_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

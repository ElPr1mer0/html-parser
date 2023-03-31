/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//#include <QtGui/QAction> //это на 6.2.4 версии
#include <QtWidgets/QAction>//это на 5.15.2
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionParseHtmlReport;
    QAction *actionExit;
    QAction *actionContextHelp;
    QAction *actionDeveloper;
    QWidget *centralwidget;
    QPushButton *butParseHtmlReport;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelEngineerName;
    QLabel *labelCoverageType;
    QVBoxLayout *verticalLayout;
    QLineEdit *editEngineerName;
    QLineEdit *editCoverageType;
    QMenuBar *menubar;
    QMenu *menufile;
    QMenu *menuHelp;
    QMenu *menuContact_info;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(340, 210);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(340, 210));
        MainWindow->setMaximumSize(QSize(340, 210));
        QPalette palette;
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
"\n"
"MainWindow{\n"
"	background-color: rgb(black);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        actionParseHtmlReport = new QAction(MainWindow);
        actionParseHtmlReport->setObjectName(QString::fromUtf8("actionParseHtmlReport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionContextHelp = new QAction(MainWindow);
        actionContextHelp->setObjectName(QString::fromUtf8("actionContextHelp"));
        actionDeveloper = new QAction(MainWindow);
        actionDeveloper->setObjectName(QString::fromUtf8("actionDeveloper"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QMainWindow{background-color: black; }"));
        butParseHtmlReport = new QPushButton(centralwidget);
        butParseHtmlReport->setObjectName(QString::fromUtf8("butParseHtmlReport"));
        butParseHtmlReport->setGeometry(QRect(10, 10, 321, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 321, 97));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelEngineerName = new QLabel(layoutWidget);
        labelEngineerName->setObjectName(QString::fromUtf8("labelEngineerName"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        labelEngineerName->setFont(font);

        verticalLayout_2->addWidget(labelEngineerName);

        labelCoverageType = new QLabel(layoutWidget);
        labelCoverageType->setObjectName(QString::fromUtf8("labelCoverageType"));
        labelCoverageType->setFont(font);

        verticalLayout_2->addWidget(labelCoverageType);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        editEngineerName = new QLineEdit(layoutWidget);
        editEngineerName->setObjectName(QString::fromUtf8("editEngineerName"));
        editEngineerName->setFont(font);
        editEngineerName->setLayoutDirection(Qt::LeftToRight);
        editEngineerName->setAutoFillBackground(false);
        editEngineerName->setFrame(false);
        editEngineerName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(editEngineerName);

        editCoverageType = new QLineEdit(layoutWidget);
        editCoverageType->setObjectName(QString::fromUtf8("editCoverageType"));
        editCoverageType->setFont(font);
        editCoverageType->setLayoutDirection(Qt::LeftToRight);
        editCoverageType->setAutoFillBackground(false);
        editCoverageType->setFrame(false);
        editCoverageType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(editCoverageType);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 340, 24));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuContact_info = new QMenu(menubar);
        menuContact_info->setObjectName(QString::fromUtf8("menuContact_info"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuContact_info->menuAction());
        menufile->addAction(actionParseHtmlReport);
        menufile->addAction(actionExit);
        menuHelp->addAction(actionContextHelp);
        menuContact_info->addAction(actionDeveloper);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Report reader", nullptr));
        actionParseHtmlReport->setText(QCoreApplication::translate("MainWindow", "Parse html report", nullptr));
#if QT_CONFIG(shortcut)
        actionParseHtmlReport->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContextHelp->setText(QCoreApplication::translate("MainWindow", "Context help", nullptr));
#if QT_CONFIG(shortcut)
        actionContextHelp->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDeveloper->setText(QCoreApplication::translate("MainWindow", "Developer", nullptr));
#if QT_CONFIG(shortcut)
        actionDeveloper->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        butParseHtmlReport->setText(QCoreApplication::translate("MainWindow", "Parse html report", nullptr));
        labelEngineerName->setText(QCoreApplication::translate("MainWindow", "Engineer name:", nullptr));
        labelCoverageType->setText(QCoreApplication::translate("MainWindow", "Coverage type:", nullptr));
        editEngineerName->setText(QCoreApplication::translate("MainWindow", "IK", nullptr));
        editCoverageType->setText(QCoreApplication::translate("MainWindow", "MC/DC+S", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuContact_info->setTitle(QCoreApplication::translate("MainWindow", "Contact info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

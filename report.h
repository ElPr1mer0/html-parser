#ifndef REPORT_H
#define REPORT_H

#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMap>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

class REPORT{
public:

    void readHtmlFile(QWidget *,const QString &, const QString &);

private:

    QXlsx::Document xlsx;
    QXlsx::Format format1;

    QString currentDir = QDir::currentPath(); // путь к текущей директории
    QString metrics = "<!-- Metrics -->\n"; // для поиска раздела Метрика
    QString tbody = "tbody"; // проверка на то, что подраздел tbody
    QString colSubprogram = "col_subprogram"; // для поиска этого подраздела
    QString tests = "</div><!-- TableOfContents -->\n"; // раздел где будут перечисленно кол-во тестов
    QString testCase = "#TestCase_"; // так начинается каждый тест, сколько #TestCase_ столько всего тестов в репорте
    QString configData = "<!-- ConfigData -->\n";
    QString testPassed = "tc-item tc-passed";

    QStringList listPathsOfFiles; // лист путей к текущим репортам
    QMap<QString,int> testCasesNames; // для сохранения кол-ва тестов по функции
    QMap<QString,int> testCasesPassed; // для сохранения кол-ва тестов по функции

    int currentRow = 1; // текущая строка

    void setPathOfReportFiles();
    void createXlsxFile();
    void saveXlsxFile(QWidget *);
    void foundCloseTag(int &, int &&, QString &);

    QString searchValueFromCurrentLine(int &, QString &);
};

#endif // REPORT_H

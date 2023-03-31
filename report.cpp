#include "report.h"
#include <QDebug>

//////////////////////////////////////////////////////////////////////
///////////////////////SET_PATH_OF_REPORT_FILES///////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод сохраняет пути к html отчетам                            ///
void REPORT::setPathOfReportFiles(){
    listPathsOfFiles = QFileDialog::getOpenFileNames();
}
//////////////////////////////////////////////////////////////////////
///////////////////////SET_PATH_OF_REPORT_FILES///////////////////////
//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
//////////////////////////CREATE_XLSX_FILE////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод создает основу эксель файла и задает формат ячеек        ///
void REPORT::createXlsxFile(){
    format1.setFontBold(true);
    format1.setFontSize(11);
    format1.setBorderStyle(QXlsx::Format::BorderMedium);

    xlsx.setColumnWidth(1,50);
    xlsx.setColumnWidth(2,11,10);

    xlsx.write("A1", "Function Name",format1);
    xlsx.write("B1", "Engineer",format1);
    xlsx.write("C1", "Number of Passed test cases",format1);
    xlsx.write("D1", "Number of Failed test cases",format1);
    xlsx.write("E1", "Coverage Type",format1);
    xlsx.write("F1", "Overall Statements",format1);
    xlsx.write("G1", "Overall Branches",format1);
    xlsx.write("H1", "Overall Pairs",format1);
    xlsx.write("I1", "Covered Statements",format1);
    xlsx.write("J1", "Covered Branches",format1);
    xlsx.write("K1", "Covered Pairs",format1);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////CREATE_XLSX_FILE////////////////////////////
//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
//////////////////////////SAVE_XLSX_FILE//////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод сохраняет готовый эксель файл в выбранную папку          ///
void REPORT::saveXlsxFile(QWidget *that){
    xlsx.saveAs(QFileDialog::getSaveFileName(that,"Save:",currentDir,"TXT Files (*.xlsx);"));
}
//////////////////////////////////////////////////////////////////////
//////////////////////////SAVE_XLSX_FILE//////////////////////////////
//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
//////////////////////////FOUND_CLOSE_TAG/////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод ищет в строке line n-ое кол-во тегов kol_tag, чтобы их   ///
/// пропустить и начать потом считывать нужные числовые значения   ///
void REPORT::foundCloseTag(int &i , int &&kol_tag, QString &line)
{
    QString buf;
    int closeTag = 0; // для подсчета закрывающих тегов >

    while (closeTag != kol_tag){ // пока не найдем 4 закрывающих html тэга (>)
        buf = line[i];
        if(buf.toHtmlEscaped() == "&gt;"){
            closeTag++;
        }
        i++;
    } // после того, как нашли 4 тэга, выписываем наше число
}
//////////////////////////////////////////////////////////////////////
//////////////////////////FOUND_CLOSE_TAG/////////////////////////////
//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
/////////////////SEARCH_VALUE_FROM_CURRENT_LINE///////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод находит числовые значения в строке line и возвращает и   ///
/// для записи в эксель файл                                       ///
QString REPORT::searchValueFromCurrentLine(int &i, QString &line){
    QString chislo = "";
    QString buf;
    buf+= line[i];

    while(buf.toInt()||buf=="0"){
        chislo +=buf;
        i++;
        buf = line[i];
    }

    return chislo;
};
//////////////////////////////////////////////////////////////////////
/////////////////SEARCH_VALUE_FROM_CURRENT_LINE///////////////////////
//////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
/////////////////////////READ_HTML_FILE///////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Метод выписывает данные из n-ого кол-ва репортов и записывает  ///
/// их в эксель файл. Используя при этом остальные функции для     ///
/// получения конечного результата                                 ///
void REPORT::readHtmlFile(QWidget *that, const QString &engineer, const QString &coverageType ){
    QString line; // строка html файла

    int savePrevRow = currentRow; // нужно для сохранения номера последней строки, записанной в эксель

    setPathOfReportFiles();
    createXlsxFile();

    while(!listPathsOfFiles.empty()){
        QFileInfo fileInfo(listPathsOfFiles.first()); // помещаем наш файл первый файл для нахождения его имени и пути
        QString name =""; // имя функции
        QString nameCheck = ""; //нужно для того, чтобы отслеживать кол-во тестов
        QString colSubprogramCheck = "";
        QString tbodyCheck = "";
        QString testCasesCheck = "";
        QString testPassedCheck = "";
        QString buf; //(храню один символ как строка)

        int i = 0; // счетчик букв в line
        int t = 0; // для сравнения раздел tbody ли это
        int c = 0; // для сравнения раздел col_subprogram ли это
        int ts = 0; // для сравнения раздел tests ли это
        int tp = 0; //для сравнения раздела testsPassed
        int testsCounter = 1;
        int countTestPassed = 1;

        bool wasTestPass = false;

        QFile file(listPathsOfFiles.first()); //здесь просто загружаем книгу, которую нужно переработать для дальнейшего использования

        if(!file.exists()){
            qDebug()<<"Нет файла!"<<"/n";
            return;
        }

        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

            while(!file.atEnd()){
                line = file.readLine(); // считываем строки html файла, пока не найдем раздел Метрика

                if (line == tests){

                    while (line!=configData){
                        line = file.readLine();                       
                        ts = 0;
                        tp = 0;
                        testCasesCheck="";
                        buf = "";

                        for(int i = 0; i<line.length();++i){

                            if(line[i]==testPassed[tp]){
                                testPassedCheck+=line[i];
                                tp++;

                                if(testPassedCheck == testPassed){
                                    countTestPassed++;
                                    wasTestPass = true;
                                    tp = 0;
                                }
                            }
                            else{
                                tp = 0;
                                testPassedCheck = "";
                            }

                            if(line[i]==testCase[ts]){
                                testCasesCheck+=line[i];
                                ts++;

                                if(testCasesCheck == testCase){
                                    i++;//чтобы не попал "_" в имя
                                    nameCheck = name;
                                    name = "";

                                    while(line[i]!='.'){
                                        name+=line[i];
                                        i++;
                                        if(i>line.length()-1) break;
                                    }

                                    if (i>line.length()-1) break; // можем выйти за предел, если не найдем точку в имени тестах

                                    testsCounter++;

                                    for(int j = 0; j<3;j++){
                                        i++; // делаем сразу ++ потому что здесь "." в line[i]
                                        buf+=line[i];
                                    }

                                    if(nameCheck != name){
                                        countTestPassed = 1;
                                        testsCounter=1;

                                        if(!wasTestPass){ // если не было сданного теста, то отнимаем несданный тест
                                            countTestPassed--;
                                        }
                                    }

                                    if( buf =="001"){ // ищем первый тест
                                        testsCounter = 1;
                                        currentRow++;
                                        testCasesNames.insert(name,testsCounter);
                                        testCasesPassed.insert(name,countTestPassed);
                                        wasTestPass = false;
                                        break;
                                    }
                                    else{
                                        auto it = testCasesNames.find(name);
                                        it.value()=testsCounter;
                                        it = testCasesPassed.find(name);
                                        it.value()=countTestPassed;
                                        wasTestPass = false;
                                        break;
                                    }
                                }
                            }
                            else{
                                ts = 0;
                                testCasesCheck = "";
                            }
                        }
                    }
                }

                if (line == metrics){

                    currentRow = savePrevRow; // +1, переход на чистую строку

                    while(!file.atEnd()){ // когда нашли раздел
                        line = file.readLine(); // считываем строку и начинаем искать наш конструктор

                        for(i =0; i<line.length();i++){

                            if(line[i]==tbody[t]){ // ищем подраздел subprogram
                                tbodyCheck+=line[i];
                                t++;

                                if(tbodyCheck == tbody){
                                    t = 0;

                                    while(!file.atEnd()){ // когда нашли раздел
                                        line = file.readLine();
                                        c = 0;
                                        colSubprogramCheck = "";

                                        for(i = 0; i<line.length();i++){

                                            if(line[i]==colSubprogram[c]){
                                                colSubprogramCheck+=line[i];
                                                c++;

                                                if(colSubprogramCheck == colSubprogram){
                                                c = 0;
                                                i+=3; // чтобы сразу перейти на название функций
                                                buf = line[i];
                                                name = "";

                                                    while (buf.toHtmlEscaped()!="&lt;"){  // здесь дописываем название нашей функции после конструктора
                                                        buf = line[i];                    // пока не найдем html тэг (<)
                                                        name += line[i];
                                                        i++;
                                                    }

                                                    name.chop(1); // удаляем последний символ, а то там мусор
                                                    currentRow++;
                                                    xlsx.write(currentRow,2,engineer); // текущая строка, текущий столбик, текст
                                                    xlsx.write(currentRow,5,coverageType);
                                                    xlsx.write(currentRow,1,name);

                                                    if (testCasesNames.contains(name)){ // кол-во тестов
                                                        auto it = testCasesNames.find(name);
                                                        xlsx.write(currentRow,3,it.value());
                                                    }
                                                    else {
                                                        xlsx.write(currentRow,3,"Not found!");
                                                    }

                                                    if (testCasesPassed.contains(name)){ // кол-во прошедших тестов
                                                        auto it = testCasesPassed.find(name);
                                                        xlsx.write(currentRow,4,it.value());
                                                    }
                                                    else {
                                                        xlsx.write(currentRow,4,"Not found!");
                                                    }

                                                    foundCloseTag(i,4,line); // скипаем текст, пока не найдем 4 закрывающих тэга
                                                    xlsx.write(currentRow,9,searchValueFromCurrentLine(i,line).toInt());
                                                    i += 3; // i +3 так как в файле отступ между значениями 3 символа

                                                    xlsx.write(currentRow,6,searchValueFromCurrentLine(i,line).toInt());
                                                    foundCloseTag(i,2,line);

                                                    xlsx.write(currentRow,10,searchValueFromCurrentLine(i,line).toInt());
                                                    i += 3;

                                                    xlsx.write(currentRow,7,searchValueFromCurrentLine(i,line).toInt());
                                                    foundCloseTag(i,2,line);
                                                                                    // эта часть нужна, когда у нас есть значение в разделе pairs
                                                    if (i+10>=line.length()){ // тут определяю есть ли этот раздел и записываю 0, если его нет
                                                        xlsx.write(currentRow,11,0);
                                                        xlsx.write(currentRow,8,0);
                                                        continue;
                                                    }
                                                    else{ // если есть раздел, то выписываю значения также как и сверху
                                                        xlsx.write(currentRow,11,searchValueFromCurrentLine(i,line).toInt());
                                                        i += 3;
                                                        xlsx.write(currentRow,8,searchValueFromCurrentLine(i,line).toInt());
                                                    }
                                                }
                                            }
                                            else{
                                                c = 0;
                                                colSubprogramCheck = "";
                                            }

                                        }
                                    }
                                }

                            }
                            else {
                                t = 0;
                                tbodyCheck = "";
                            }

                        }

                    }
                }
            }
        }
        else{
            qDebug()<<"File can't be open!";
        }
        file.close();
        listPathsOfFiles.pop_front();
        savePrevRow = currentRow;
    }
    saveXlsxFile(that);
}
//////////////////////////////////////////////////////////////////////
/////////////////////////READ_HTML_FILE///////////////////////////////
//////////////////////////////////////////////////////////////////////

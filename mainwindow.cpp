#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<fstream>
#include<iostream>
#include<QString>
#include<sstream>
#include<algorithm>
#include<QChar>
#include<QTextStream>
#include<string>
#include<QMessageBox>
using namespace std;
fstream dataFile("C:/Qt progects/texteditor/file.txt"), newfile;	char name[81];
ostringstream strstream;
string str;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//write LV.
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text | QFile:: WriteOnly);
    QTextStream in(&outFile);
    QString string = in.readAll();
    outFile.close();
    QFile inFile("C:/Qt progects/texteditor/file.txt");
    inFile.open(QFile:: WriteOnly| QFile:: Text);
    QTextStream out(&inFile);
    QString text = ui -> textEdit ->toPlainText();
    if(string == " ")
    {out << text ;}
    else
        out << string << "\n" << text;
    inFile.flush();
    inFile.close();
}
//----------------------------------------------------------------
void MainWindow::on_pushButton_2_clicked()//read
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    ui ->textEdit_2 ->setPlainText(text);
}


//----------------------------------------------------------------
void MainWindow::on_pushButton_3_clicked()//encrypt
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    outFile.close();
    outFile.open(QFile:: WriteOnly | QFile:: Text);
    static QString st;
    for(int i = 0; i < text.size(); i++){
        text[i] = QChar(text[i].unicode() + 1) ;
        st += text[i];
    }
    QTextStream out(&outFile);
    out << st;
    outFile.flush();
    outFile.close();

}
//--------------------------------------------------------------
void MainWindow::on_pushButton_4_clicked()//delete
{
    QFile outfile("C:/Qt progects/texteditor/file.txt");
    outfile.open(QFile:: WriteOnly);
    QTextStream out(&outfile);
    QString str = " ";
    out << str;
}

//----------------------------------------------------------------------
void MainWindow::on_pushButton_6_clicked()//decrypt
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    outFile.close();
    outFile.open(QFile:: WriteOnly | QFile:: Text);
    static QString st;
    for(int i = 0; i < text.size(); i++){
        text[i] = QChar(text[i].unicode() - 1) ;
        st += text[i];
    }
    QTextStream out(&outFile);
    out << st;
    outFile.flush();
    outFile.close();
}
//----------------------------------------------------------------------

void MainWindow::on_pushButton_7_clicked()//mergeFile
{
    QFile mergeFile("C:/Qt progects/texteditor/Sfile.txt");
    mergeFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&mergeFile);
    QString str2 = in.readAll();
    mergeFile.close();
    strstream << dataFile.rdbuf();
    str = strstream.str();
    QString text = QString:: fromStdString(str);
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: WriteOnly | QFile:: Text);
    QTextStream out(&outFile);
    if(text == " ")
        out << str2;
    else
        out << text << "\n" << str2;

}
//----------------------------------------------------------------------



void MainWindow::on_pushButton_8_clicked()//count number of the words in the file
{
    string word;
    int count = 0;
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);
    while (!dataFile.eof())
    {
        dataFile >> word;
        count += 1;

    }
    QString c = QString:: number(count);
    QFile outfile("C:/Qt progects/texteditor/file.txt");
    outfile.open(QFile:: WriteOnly | QFile:: ReadOnly );
    QMessageBox::about(this,"Result",c);
    dataFile.close();
    outfile.close();

}
//----------------------------------------------------------------------------------
void MainWindow::on_pushButton_9_clicked()//all letters are capital upper case
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    outFile.close();
    QFile inFile("C:/Qt progects/texteditor/file.txt");
    inFile.open(QFile:: WriteOnly| QFile:: Text);
    for(int i = 0; i < text.size(); i++){
        text[i] = text[i].toUpper();
    }
    QTextStream out(&inFile);
    out << text;
    inFile.flush();
    inFile.close();
}
//-----------------------------------------------------------------------------------
void MainWindow::on_pushButton_12_clicked()//count the number of char in the file.
{
    char word;
    int count = 0;
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);
    while (!dataFile.eof())

    {
        dataFile >> word;
        count += 1;

    }
    QString c = QString:: number(count - 1);
    QMessageBox::information(this,"number of char",c);
    dataFile.close();
}
//---------------------------------------------------------------------------------------

void MainWindow::on_pushButton_13_clicked()//count number of lines in the file.
{
    string line;
    int count = 0;
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);
    while (getline(dataFile, line))

    {
        count += 1;
    }
    QString c = QString:: number(count);
    QMessageBox:: information(this, "number of lines",c);
    dataFile.close();
}
//-------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_14_clicked()//search for a word in the file
{
    QString text = ui -> textEdit_3 ->toPlainText();
    string word;
    word = text.toStdString();
    dataFile.open("C:/Qt progects/texteditor/file.txt", ios:: in);
    int count=0;
    string word_in_file;
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);
    for (int i = 0;i <  word.length();i++)
     {
         word[i] = tolower(word[i]);
     }

     while(!dataFile.eof())

     {
         dataFile >> word_in_file;
         for (int i = 0;i <  word.length();i++)
         {
             word_in_file[i] = tolower(word_in_file[i]);
         }
         if(word == word_in_file)
             count += 1;
     }
     if(count >= 1){
         QMessageBox::information(this,"the repeated word","word was found :)");
     }
     else
         QMessageBox::information(this,"the repeated word","word wasn't found :(");
     dataFile.flush();
     dataFile.close();

}

//-----------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_15_clicked()//find the number of time the word exist in the file.
{
    QString text = ui -> textEdit_3 ->toPlainText();
    string word;
    word = text.toStdString();
    dataFile.open("C:/Qt progects/texteditor/file.txt", ios:: in);
    int count=0;
    string word_in_file;
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);
    for (int i = 0;i <  word.length();i++)
     {
         word[i] = tolower(word[i]);
     }

     while(!dataFile.eof())

     {
         dataFile >> word_in_file;
         for (int i = 0;i <  word.length();i++)
         {
             word_in_file[i] = tolower(word_in_file[i]);
         }
         if(word == word_in_file)
             count += 1;
     }
     if(count >= 1){
         QString c = QString:: number(count);
         QMessageBox::information(this,"the number of time for a word",c);
     }
     else
         QMessageBox::information(this,"the repeated word","The word checked doesn't exist !");
     dataFile.flush();
     dataFile.close();
}

//-----------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_11_clicked()//convert the only first char to uppercase
{QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    outFile.close();
    QFile inFile("C:/Qt progects/texteditor/file.txt");
    inFile.open(QFile:: WriteOnly| QFile:: Text);
    for(int i = 0; i < text.size(); i++){
        text[i] = text[i].toLower();
    }
    for(int i = 0; i < text.size(); i++){
        if(i == 0)
            text[0] = text[0].toUpper();
        else if(text[i - 1] == ' ' || text[i - 1] == '\n'){
            text[i] = text[i].toUpper();
        }
        else
            text[i] = text[i].toLower();
    }
    QTextStream out(&inFile);
    out << text;
    inFile.flush();
    inFile.close();

}
//-----------------------------------------------------------------------------

void MainWindow::on_pushButton_10_clicked()//convert all text into lower case
{
    QFile outFile("C:/Qt progects/texteditor/file.txt");
    outFile.open(QFile:: ReadOnly |QFile:: Text);
    QTextStream in(&outFile);
    QString text = in.readAll();
    outFile.close();
    QFile inFile("C:/Qt progects/texteditor/file.txt");
    inFile.open(QFile:: WriteOnly| QFile:: Text);
    for(int i = 0; i < text.size(); i++){
        text[i] = text[i].toLower();
    }
    QTextStream out(&inFile);
    out << text;
    inFile.flush();
    inFile.close();
}


void MainWindow::on_pushButton_5_clicked()
{

}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <fstream>
#include <string>
#include <QString>
#include <QMessageBox>
#include <secdialog.h>
#include<thirddialog.h>
#include <fourthdialog.h>
#include <fifthdialog.h>
#include <seventhdialog.h>
#include <eighthdialog.h>
#include <wordscountdialog.h>
#include <savedialog.h>
#include <openfiledialog.h>
#include <swapdialog.h>
#include <showall.h>
#include <iostream>
using namespace std;

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

void MainWindow::on_addline_clicked()
{
    string line = ui->lineEdit_addline->text().toStdString();
    undoCmd lineAdded;
    lineAdded.commandNumber = 1;
       auto ptr = texteditor::m.rbegin();
       int index = ptr -> first;
       index++;
       texteditor::m.insert({index,line});
       lineAdded.lineNumber = index;
       lineAdded.oldLine = line;
       texteditor::undoStack.push(lineAdded);

    ui->lineEdit_addline->setText("");
    if (line == "") ui->statusbar->showMessage(" Empty line is added.." , 1500);
    else ui->statusbar->showMessage(" 1 line is added.." , 1500);
}

void MainWindow::on_InsertLine_clicked()
{
    secDialog s;
    s.setModal(true);
    s.exec();
    //showText();
}


void MainWindow::on_UpdateLine_clicked()
{
    thirdDialog t;
    t.setModal(true);
    t.exec();
}


void MainWindow::on_GetLine_clicked()
{
    fourthDialog f1;
    f1.setModal(true);
    f1.exec();
}


void MainWindow::on_FindAll_clicked()
{
    fifthDialog f2;
    f2.setModal(true);
    f2.exec();
}


void MainWindow::on_FindAndReplaceAll_clicked()
{
    seventhDialog s;
    s.setModal(true);
    s.exec();
}

void MainWindow::on_ShowAll_clicked()
{
    showAll s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_DeleteLine_clicked()
{
    eighthDialog e;
    e.setModal(true);
    e.exec();
}


void MainWindow::on_CountAllWords_clicked()
{
    int counter = 0;
    auto it = texteditor::m.begin();
    it++;
    for(;it !=texteditor::m.end();++it){
        stringstream myLine(it->second);
        string s;
        while(myLine >> s){
                counter++;
        }
    }
    string message = "  The current File contains ";
    message+=to_string(counter); message+= " words.. ";
    QString qstr = QString::fromStdString(message);
    ui->statusbar->showMessage(qstr,1500);
}


void MainWindow::on_wordsCount_clicked()
{
    wordsCountDialog w;
    w.setModal(true);
    w.exec();
}



void MainWindow::on_actionNew_triggered()
{
    texteditor::m.clear();
    ui->statusbar->showMessage("A new file has opened.." , 1500);
}

void MainWindow::on_Undo_clicked()
{
    undoCmd mostRecentCmd = texteditor::undoStack.top();
            texteditor::redoStack.push(mostRecentCmd);
            if(mostRecentCmd.commandNumber == 2){               // undo for find and replace
                for(int i = 0 ;i<mostRecentCmd.lineNumbers.size();++i){
                    texteditor::m.at(mostRecentCmd.lineNumbers[i]) = mostRecentCmd.oldLine;
                }
            }
            else if(mostRecentCmd.commandNumber == 3){          // undo for delete
                texteditor::m.insert({mostRecentCmd.lineNumber,mostRecentCmd.oldLine});
            }
            else if(mostRecentCmd.commandNumber == 1){         // undo for add line
                texteditor::m.erase(mostRecentCmd.lineNumber);
            }
            else if(mostRecentCmd.commandNumber == 5){         // undo for insert - replace
                texteditor::m[mostRecentCmd.lineNumber] = mostRecentCmd.oldLine;
            }
            else if(mostRecentCmd.commandNumber == 6){        // undo for insert line
                texteditor::m.erase(mostRecentCmd.lineNumber);
            }
            else if(mostRecentCmd.commandNumber == 7){        // undo for update
                texteditor::m[mostRecentCmd.lineNumber] = mostRecentCmd.oldLine;
            }
            else if (mostRecentCmd.commandNumber == 8){       // undo for swap
                texteditor::m[mostRecentCmd.lineNumbers[0]]=mostRecentCmd.oldLine;
                texteditor::m[mostRecentCmd.lineNumbers[1]]=mostRecentCmd.newLine;
            }
            else if (mostRecentCmd.commandNumber == 9){      // undo for swap
                texteditor::m[mostRecentCmd.lineNumbers[0]]=mostRecentCmd.oldLine;
                texteditor::m.erase(mostRecentCmd.lineNumbers[1]);
            }
            else if (mostRecentCmd.commandNumber == 10){     // undo for swap
                texteditor::m[mostRecentCmd.lineNumbers[1]]=mostRecentCmd.newLine;
                texteditor::m.erase(mostRecentCmd.lineNumbers[0]);
            }
             texteditor::undoStack.pop();
             ui->statusbar->showMessage("Undo is done successfully..",1500);
}

void MainWindow::on_redo_clicked()
{
    undoCmd mostRecentUndo = texteditor::redoStack.top();
            if(mostRecentUndo.commandNumber == 3){                   // redo for delete
                texteditor::m.erase(mostRecentUndo.lineNumber);
            }
            else if(mostRecentUndo.commandNumber == 1){              // redo for add line
                try{
                    texteditor::m.at(mostRecentUndo.lineNumber);
                }
                catch(out_of_range &e){
                    texteditor::m.insert({mostRecentUndo.lineNumber,mostRecentUndo.oldLine});
                }
            }
            else if(mostRecentUndo.commandNumber == 7){                // redo for update
                texteditor::m[mostRecentUndo.lineNumber]=mostRecentUndo.newLine;
            }
            else if(mostRecentUndo.commandNumber == 2){                // redo for update
                for(int i = 0 ;i<mostRecentUndo.lineNumbers.size();++i){
                    texteditor::m.at(mostRecentUndo.lineNumbers[i]) = mostRecentUndo.newLine;
                }
            }
            else if(mostRecentUndo.commandNumber == 5){                // redo for insert - replace
                texteditor::m[mostRecentUndo.lineNumber]=mostRecentUndo.newLine;
            }
            else if(mostRecentUndo.commandNumber == 6){                // redo for insert
                texteditor::m.insert({mostRecentUndo.lineNumber,mostRecentUndo.newLine});
            }
            else if(mostRecentUndo.commandNumber == 8){                // redo for swap
                texteditor::m[mostRecentUndo.lineNumbers[0]]=mostRecentUndo.newLine;
                texteditor::m[mostRecentUndo.lineNumbers[1]]=mostRecentUndo.oldLine;
            }
            else if(mostRecentUndo.commandNumber == 9){                // redo for swap
                texteditor::m[mostRecentUndo.lineNumbers[1]]=mostRecentUndo.oldLine;
                texteditor::m.erase(mostRecentUndo.lineNumbers[0]);
            }
            else if(mostRecentUndo.commandNumber == 10){                // redo for swap
                texteditor::m[mostRecentUndo.lineNumbers[0]]=mostRecentUndo.newLine;
                texteditor::m.erase(mostRecentUndo.lineNumbers[1]);
            }
            texteditor::redoStack.pop();
            ui->statusbar->showMessage("Redo is done successfully..",1500);
}


void MainWindow::on_OpenExsistedFile_clicked()
{
    openFileDialog o;
    o.setModal(true);
    o.exec();
}


void MainWindow::on_saveToAfile_clicked()
{
    SaveDialog s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_actionabout_triggered()
{
    QMessageBox::information(this,"","Welcome for you in our Lovely Mini text editor where you can insert,update,delete line and much more other Options...Enjoy");
}


void MainWindow::on_actionSave_triggered()
{
    if(texteditor::currentFileName == ""){
        QMessageBox::warning(this,"","To save for the first time click button (save to a file)..");
    }
    else{
        ofstream writefile;
        writefile.open(texteditor::currentFileName , ofstream::out | ofstream::trunc);
        if(texteditor::m.empty())
        {
            writefile.close();
            return;
        }
        else
        {
            auto it = texteditor::m.rbegin();
            for(int i = 1 ;i<=it->first;++i){
                try{
                    texteditor::m.at(i);
                    writefile << texteditor::m[i] << endl;
                }
                catch(const std::out_of_range &e){
                    writefile << endl;
                }
            }
            writefile.close();
        }
        ui->statusbar->showMessage(" Changes saved successfully..");
    }
}


void MainWindow::on_pushButton_clicked()
{
    swapDialog s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(texteditor::currentFileName == ""){
        QMessageBox::warning(this,"","To save for the first time click button (save to a file)..");
    }
    else{
        ofstream writefile;
        writefile.open(texteditor::currentFileName , ofstream::out | ofstream::trunc);
        if(texteditor::m.empty())
        {
            writefile.close();
            return;
        }
        else
        {
            auto it = texteditor::m.rbegin();
            for(int i = 1 ;i<=it->first;++i){
                try{
                    texteditor::m.at(i);
                    writefile << texteditor::m[i] << endl;
                }
                catch(const std::out_of_range &e){
                    writefile << endl;
                }
            }
            writefile.close();
        }
        ui->statusbar->showMessage(" Changes saved successfully..");
    }
}


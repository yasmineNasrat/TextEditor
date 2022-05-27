#include "secdialog.h"
#include "ui_secdialog.h"
#include <texteditor.h>
#include <mainwindow.h>
#include <iostream>
#include <QMessageBox>
using namespace std;

secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_pushButton_insert_clicked()
{
    ui->label_message->setText("");
    int lineNo = ui->lineEdit_lineNo->text().toInt();
    string newline = ui->lineEdit_line->text().toStdString();

    auto it = texteditor::m.rbegin();
    if(lineNo <= 0){
        QMessageBox::warning(this,"","Invalid line No..");
    }
    else{
        undoCmd lineInserted;
        lineInserted.lineNumber=lineNo;
        ui->label_message->setText("");
        try{
            texteditor::m.at(lineNo);
            lineInserted.commandNumber = 5;
            lineInserted.oldLine = texteditor::m[lineNo];
            lineInserted.newLine = newline;
            texteditor::undoStack.push(lineInserted);
            QMessageBox::StandardButton reply = QMessageBox::question(this,"",
                                                                      "there is a line with this number\n Do you want to replace it ?\n" ,
                                                                      QMessageBox::Yes |QMessageBox::No);
            if(reply == QMessageBox::Yes){
                texteditor::m[lineNo] = newline;
                ui->label_message->setText("the line has been replaced successfully..");
                return;
            }
            ui->label_message->setText(" the line has not been replaced ");
            ui->lineEdit_line->setText("");
            ui->lineEdit_lineNo->setText("");
        }
        catch(out_of_range &e){
            lineInserted.commandNumber = 6;
            lineInserted.newLine = newline;
            texteditor::undoStack.push(lineInserted);
            texteditor::m[lineNo]=newline;

            ui->lineEdit_line->setText("");
            ui->lineEdit_lineNo->setText("");
            string message = " 1 line is inserted successfully..";
            QString qstr = QString::fromStdString(message);
            ui->label_message->setText(qstr);
        }
    }
}


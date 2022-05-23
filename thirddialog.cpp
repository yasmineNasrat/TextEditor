#include "thirddialog.h"
#include "ui_thirddialog.h"
#include <texteditor.h>
#include <iostream>
#include <QMessageBox>
using namespace std;

thirdDialog::thirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
}

thirdDialog::~thirdDialog()
{
    delete ui;
}

void thirdDialog::on_pushButton_update_clicked()
{
    ui->label_comment->setText("");

    int lineNo = ui->lineEdit_lineno->text().toInt();
    string line = ui->lineEdit_newline->text().toStdString();

    ui->lineEdit_lineno->setText("");
    ui->lineEdit_newline->setText("");

    auto it = texteditor::m.rbegin();
    if(lineNo <= 0 || lineNo > it->first){
        QMessageBox::warning(this,"","Invalid line no..");
    }
    else{
        undoCmd updated;
        updated.commandNumber = 7;
        updated.lineNumber = lineNo;
        updated.oldLine = texteditor::m[lineNo];
        texteditor::m[lineNo] = line;
        ui->label_comment->setText("line has been updated successfully..");
        updated.newLine = line;
        texteditor::undoStack.push(updated);
    }
}


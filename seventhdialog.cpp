#include "seventhdialog.h"
#include "ui_seventhdialog.h"
#include <texteditor.h>
#include <QString>
seventhDialog::seventhDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seventhDialog)
{
    ui->setupUi(this);
}

seventhDialog::~seventhDialog()
{
    delete ui;
}

void seventhDialog::on_pushButton_Replace_clicked()
{
    string oldline = ui->lineEdit_oldline->text().toStdString();
    string newline = ui->lineEdit_newline->text().toStdString();
    int noOfLinesFound = 0;
    undoCmd allReplaced;

    for(auto it=texteditor::m.begin();it!=texteditor::m.end();++it){
        if(it->second == oldline){
            noOfLinesFound++;
            it->second = newline;
            allReplaced.lineNumbers.push_back(it->first);
        }
    }
    allReplaced.commandNumber = 2;
    allReplaced.oldLine = oldline;
    allReplaced.newLine = newline;
    texteditor::undoStack.push(allReplaced);

    string noOflinesFound = to_string(noOfLinesFound);
    noOflinesFound+= " Line(s) found and Replaced successfully..";
    QString qstr = QString::fromStdString(noOflinesFound);
    ui->label_noOfreplacements->setText(qstr);
}


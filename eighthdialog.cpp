#include "eighthdialog.h"
#include "ui_eighthdialog.h"
#include <texteditor.h>
#include <QMessageBox>
eighthDialog::eighthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eighthDialog)
{
    ui->setupUi(this);
}

eighthDialog::~eighthDialog()
{
    delete ui;
}

void eighthDialog::on_pushButton_clicked()
{
    ui->label_comment->setText("");
    ui->label_oldline->setText("");
    ui->label_header->setText("The Line content was ");

    int lineno = ui->lineEdit_lineno->text().toInt();
    auto it = texteditor::m.rbegin();
    if(lineno <= 0 || lineno > it->first)
    {
         QMessageBox::warning(this,"","Invalid line number..");
         ui->lineEdit_lineno->setText("");
    }
    else{
        try{
            texteditor::m.at(lineno);
            undoCmd deleted;
            deleted.commandNumber = 3 ;
            deleted.lineNumber=lineno;
            deleted.oldLine = texteditor::m[lineno];
            texteditor::undoStack.push(deleted);
            if(texteditor::m[lineno] == "")
            {
                ui->label_header->setText("The line is already Empty.. ");
                texteditor::m.erase(lineno);
                return;
            }
            QString qstr = QString::fromStdString(texteditor::m[lineno]);
            ui->label_oldline->setText(qstr);
            texteditor::m.erase(lineno);
            ui->label_comment->setText(" Successfully Deleted...");
        }
        catch(const std::out_of_range &e){
            ui->label_header->setText("The line is already Empty.. ");
        }
    }
}


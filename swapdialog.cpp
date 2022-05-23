#include "swapdialog.h"
#include "ui_swapdialog.h"
#include <texteditor.h>
#include <QMessageBox>
swapDialog::swapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::swapDialog)
{
    ui->setupUi(this);
}

swapDialog::~swapDialog()
{
    delete ui;
}

void swapDialog::on_pushButton_clicked()
{
    ui->label_message->setText("");
    int line1 = ui->lineEdit_line1->text().toInt();
    int line2 = ui->lineEdit_line2->text().toInt();
    auto ptr = texteditor::m.rbegin();
    if (line1 <= 0 || line2 <= 0 )
        {
            QMessageBox::warning(this,"","Invalid line number..");
            return;
        }
    else if (line1 > ptr->first || line2 > ptr->first){
            QMessageBox::warning(this,"","Invalid line number (Out of range)");
            return;
        }
    else if (!texteditor::m.count(line1) && !texteditor::m.count(line2))
    {
        QMessageBox::information(this,"","The two lines you entered have no text..");
    }
    else{
        undoCmd swapped;
        swapped.lineNumbers.push_back(line1);
        swapped.lineNumbers.push_back(line2);

        if (texteditor::m.count(line1) && texteditor::m.count(line2))
        {
            swapped.oldLine = texteditor::m[line1];
            swapped.newLine = texteditor::m[line2];
            string s;
            s = texteditor::m[line1];
            texteditor::m[line1] = texteditor::m[line2];
            texteditor::m[line2] = s;
            swapped.commandNumber=8;
        }
        else if (texteditor::m.count(line1) && !texteditor::m.count(line2))
        {
            swapped.oldLine = texteditor::m[line1];
            texteditor::m[line2] = texteditor::m[line1];
            texteditor::m.erase(line1);
            swapped.commandNumber=9;
        }
        else if (!texteditor::m.count(line1) && texteditor::m.count(line2))
        {
            swapped.newLine=texteditor::m[line2];
            texteditor::m[line1] = texteditor::m[line2];
            texteditor::m.erase(line2);
            swapped.commandNumber=10;
        }
        texteditor::undoStack.push(swapped);
        string message ="";
        message+=" line ";message+=to_string(line1);message+= " and line " ;message+=to_string(line2)+= " swapped successfully";
        QString qstr = QString::fromStdString(message);
        ui->label_message->setText(qstr);
    }
}


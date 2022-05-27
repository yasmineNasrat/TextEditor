#include "fourthdialog.h"
#include "ui_fourthdialog.h"
#include <texteditor.h>
#include <QMessageBox>
#include <string>
#include <QString>
using namespace std;
fourthDialog::fourthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthDialog)
{
    ui->setupUi(this);
}

fourthDialog::~fourthDialog()
{
    delete ui;
}

void fourthDialog::on_buttonBox_accepted()
{

}


void fourthDialog::on_pushButton_clicked()
{
    ui->label_line_content->setText("");
    ui->label_header->setText("The Line content is..");

    int lineNo = ui->lineEdit_lineno->text().toInt();
    auto it = texteditor::m.rbegin();
    if(lineNo <= 0 || lineNo > it->first)
       {
            QMessageBox::warning(this,"","Invalid line no..");
       }
    else{
        try{
             texteditor:: m.at(lineNo);
             if(texteditor::m[lineNo] == ""){
                 ui->label_header->setText("This line is Empty..");
                 return;
             }
             QString qstr = QString::fromStdString(texteditor::m[lineNo]);
             ui->label_line_content->setText(qstr);
        }
        catch(const std::out_of_range &e){
             ui->label_header->setText("This line is Empty..");
        }

    }
}


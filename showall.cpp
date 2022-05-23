#include "showall.h"
#include "ui_showall.h"
#include <texteditor.h>
showAll::showAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showAll)
{
    ui->setupUi(this);
}

showAll::~showAll()
{
    delete ui;
}

void showAll::on_pushButton_show_clicked()
{
    auto it = texteditor::m.rbegin();
    string text = "";
    for(int i = 1;i <= it->first;++i){
        try{
            texteditor::m.at(i);
            text+=to_string(i);text+=") ";
            text+=texteditor::m[i];text+="\n";
        }
        catch(const std::out_of_range &e){
            text+=to_string(i);text+=")\n";
        }
    }
    if (text == "") ui->label_comment->setText(" the current file is empty..");
    else {
        QString qstr = QString::fromStdString(text);
        ui->text->setText(qstr);
    }

}


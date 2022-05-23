#include "fifthdialog.h"
#include "ui_fifthdialog.h"
#include <string>
#include <vector>
#include <texteditor.h>
#include <QMessageBox>
#include <iostream>
using namespace std;
fifthDialog::fifthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fifthDialog)
{
    ui->setupUi(this);
}

fifthDialog::~fifthDialog()
{
    delete ui;
}

void fifthDialog::on_pushButton_clicked()
{
    string line = ui->lineEdit_line->text().toStdString();
    transform(line.begin(),line.end(),line.begin(),::tolower);
    vector<int> v; string temp = "";
    auto it = texteditor::m.begin();it++;
     for(;it!=texteditor::m.end();++it){
         temp = it->second;
         transform(temp.begin(),temp.end(),temp.begin(),::tolower);
         if(temp == line){
             v.push_back(it->first);
         }
     }
     if(v.empty()){
         QMessageBox :: information(this,"","This line does not exsist in this file..");
         ui->lineEdit_line->setText("");
     }
     else{
         string s = "";
         for(int i = 0;i<v.size();++i){
             s+=to_string(v[i]);
             s+=" , ";
         }
         QString qstr = QString::fromStdString(s);
         ui->lineEdit_linenumbers->setText(qstr);
     }
}


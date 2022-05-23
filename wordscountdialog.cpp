#include "wordscountdialog.h"
#include "ui_wordscountdialog.h"
#include <texteditor.h>
#include <string>
#include <sstream>
using namespace std;
wordsCountDialog::wordsCountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wordsCountDialog)
{
    ui->setupUi(this);
}

wordsCountDialog::~wordsCountDialog()
{
    delete ui;
}

void wordsCountDialog::on_pushButton_clicked()
{
    string word = ui->lineEdit_word->text().toStdString();
    transform(word.begin(),word.end(),word.begin(),::tolower);
    int counter = 0;
    auto it = texteditor::m.begin();it++;
    for(;it !=texteditor::m.end();++it){
        stringstream myLine(it->second);
        string s;
        while(myLine >> s){
          transform(s.begin(),s.end(),s.begin(),::tolower);
            if(s == word)
                counter++;
        }
    }
    string message = "This word is repeated ";
    message+=to_string(counter);message+=" times..";
    QString qstr = QString::fromStdString(message);
    ui->lineEdit_wordNo->setText(qstr);
}


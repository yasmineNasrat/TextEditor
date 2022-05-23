#include "openfiledialog.h"
#include "ui_openfiledialog.h"
#include <texteditor.h>
#include <QMessageBox>
#include <fstream>
using namespace std;
openFileDialog::openFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openFileDialog)
{
    ui->setupUi(this);
}

openFileDialog::~openFileDialog()
{
    delete ui;
}

void openFileDialog::on_pushButton_clicked()
{
    string fileName = ui->lineEdit_filename->text().toStdString();
    fileName+=".txt";
    ifstream readFile(fileName);
    if(readFile.is_open()){
        texteditor::m.clear();
        string line;int lineNo = 1;
        while(getline(readFile,line)){
            if(line != ""){
                texteditor::m.insert({lineNo,line});
            }
            lineNo++;
        }
        readFile.close();
        ui->label_comment->setText(" file opened successfully..");
        texteditor::currentFileName = fileName;
    }
    else{
        QMessageBox::information(this," ","File not found\n Make sure the file name is correct..");
    }
}


#include "savedialog.h"
#include "ui_savedialog.h"
#include <texteditor.h>
#include <fstream>
using namespace std;
SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);
}

SaveDialog::~SaveDialog()
{
    delete ui;
}

void SaveDialog::on_save_button_clicked()
{
    string fileName = ui->lineEdit_filename->text().toStdString();
    fileName+=".txt";
    ofstream writefile(fileName);
    texteditor::currentFileName = fileName;
    if(texteditor::m.empty()){
        writefile.close();
        ui->label_comment->setText(" Empty file is saved successfully..");
    }
    else{
        auto it = texteditor::m.rbegin();
        for(int i = 1;i<=it->first;++i){
            try{
                texteditor::m.at(i);
                writefile << texteditor::m[i] << endl;
            }
            catch(const out_of_range &e){
                writefile << endl;
            }
        }
            writefile.close();
            ui->label_comment->setText(" file saved successfully..");
}

}

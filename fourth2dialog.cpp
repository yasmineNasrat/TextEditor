#include "fourth2dialog.h"
#include "ui_fourth2dialog.h"

fourth2Dialog::fourth2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourth2Dialog)
{
    ui->setupUi(this);
}

fourth2Dialog::~fourth2Dialog()
{
    delete ui;
}

#include "sixthdialog.h"
#include "ui_sixthdialog.h"

sixthDialog::sixthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sixthDialog)
{
    ui->setupUi(this);
}

sixthDialog::~sixthDialog()
{
    delete ui;
}

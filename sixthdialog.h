#ifndef SIXTHDIALOG_H
#define SIXTHDIALOG_H

#include <QDialog>

namespace Ui {
class sixthDialog;
}

class sixthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sixthDialog(QWidget *parent = nullptr);
    ~sixthDialog();

private:
    Ui::sixthDialog *ui;
};

#endif // SIXTHDIALOG_H

#ifndef SWAPDIALOG_H
#define SWAPDIALOG_H

#include <QDialog>

namespace Ui {
class swapDialog;
}

class swapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit swapDialog(QWidget *parent = nullptr);
    ~swapDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::swapDialog *ui;
};

#endif // SWAPDIALOG_H

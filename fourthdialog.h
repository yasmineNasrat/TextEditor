#ifndef FOURTHDIALOG_H
#define FOURTHDIALOG_H

#include <QDialog>

namespace Ui {
class fourthDialog;
}

class fourthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit fourthDialog(QWidget *parent = nullptr);
    ~fourthDialog();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::fourthDialog *ui;
};

#endif // FOURTHDIALOG_H

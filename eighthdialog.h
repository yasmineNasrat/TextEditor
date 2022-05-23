#ifndef EIGHTHDIALOG_H
#define EIGHTHDIALOG_H

#include <QDialog>

namespace Ui {
class eighthDialog;
}

class eighthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit eighthDialog(QWidget *parent = nullptr);
    ~eighthDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::eighthDialog *ui;
};

#endif // EIGHTHDIALOG_H

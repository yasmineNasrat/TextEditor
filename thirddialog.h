#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);
    ~thirdDialog();

private slots:

    void on_pushButton_update_clicked();

private:
    Ui::thirdDialog *ui;
};

#endif // THIRDDIALOG_H

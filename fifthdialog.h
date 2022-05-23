#ifndef FIFTHDIALOG_H
#define FIFTHDIALOG_H

#include <QDialog>

namespace Ui {
class fifthDialog;
}

class fifthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit fifthDialog(QWidget *parent = nullptr);
    ~fifthDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fifthDialog *ui;
};

#endif // FIFTHDIALOG_H

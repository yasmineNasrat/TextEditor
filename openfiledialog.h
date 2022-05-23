#ifndef OPENFILEDIALOG_H
#define OPENFILEDIALOG_H

#include <QDialog>

namespace Ui {
class openFileDialog;
}

class openFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit openFileDialog(QWidget *parent = nullptr);
    ~openFileDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::openFileDialog *ui;
};

#endif // OPENFILEDIALOG_H

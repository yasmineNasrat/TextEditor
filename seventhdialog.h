#ifndef SEVENTHDIALOG_H
#define SEVENTHDIALOG_H

#include <QDialog>

namespace Ui {
class seventhDialog;
}

class seventhDialog : public QDialog
{
    Q_OBJECT

public:
    explicit seventhDialog(QWidget *parent = nullptr);
    ~seventhDialog();

private slots:

    void on_pushButton_Replace_clicked();

private:
    Ui::seventhDialog *ui;
};

#endif // SEVENTHDIALOG_H

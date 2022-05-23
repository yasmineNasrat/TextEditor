#ifndef WORDSCOUNTDIALOG_H
#define WORDSCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class wordsCountDialog;
}

class wordsCountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit wordsCountDialog(QWidget *parent = nullptr);
    ~wordsCountDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::wordsCountDialog *ui;
};

#endif // WORDSCOUNTDIALOG_H

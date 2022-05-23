#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = nullptr);
    ~SaveDialog();

private slots:
    void on_save_button_clicked();

private:
    Ui::SaveDialog *ui;
};

#endif // SAVEDIALOG_H

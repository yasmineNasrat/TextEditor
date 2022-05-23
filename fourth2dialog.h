#ifndef FOURTH2DIALOG_H
#define FOURTH2DIALOG_H

#include <QDialog>

namespace Ui {
class fourth2Dialog;
}

class fourth2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit fourth2Dialog(QWidget *parent = nullptr);
    ~fourth2Dialog();

private:
    Ui::fourth2Dialog *ui;
};

#endif // FOURTH2DIALOG_H

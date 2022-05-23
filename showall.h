#ifndef SHOWALL_H
#define SHOWALL_H

#include <QDialog>

namespace Ui {
class showAll;
}

class showAll : public QDialog
{
    Q_OBJECT

public:
    explicit showAll(QWidget *parent = nullptr);
    ~showAll();

private slots:
    void on_pushButton_show_clicked();

private:
    Ui::showAll *ui;
};

#endif // SHOWALL_H

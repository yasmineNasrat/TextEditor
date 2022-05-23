#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <texteditor.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    texteditor t;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_addline_clicked();

    void on_InsertLine_clicked();

    void on_UpdateLine_clicked();

    void on_GetLine_clicked();

    void on_FindAll_clicked();

    void on_FindAndReplaceAll_clicked();

    void on_ShowAll_clicked();

    void on_DeleteLine_clicked();

    void on_CountAllWords_clicked();

    void on_wordsCount_clicked();

    void on_Undo_clicked();

    void on_actionNew_triggered();

    //void on_pushButton_clicked();

    void on_redo_clicked();

    void on_OpenExsistedFile_clicked();

    void on_saveToAfile_clicked();

    void on_actionabout_triggered();

    void on_actionSave_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
     Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

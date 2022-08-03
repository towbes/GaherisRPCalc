#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rpcalc.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mrNone_toggled(bool checked);

    void on_mrTen_toggled(bool checked);

    void on_mrTwentyfive_toggled(bool checked);

private:
    RPCalc* rpCalc;
    Ui::MainWindow *ui;
    void setBuffBonusLabel();
};
#endif // MAINWINDOW_H

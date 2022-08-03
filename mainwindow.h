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
    void on_bgroupMinorelic_idToggled(int val);
    void on_bgroupRpPotion_idToggled(int val);

private:
    RPCalc* rpCalc;
    Ui::MainWindow *ui;
    void setBuffBonusLabel();
};
#endif // MAINWINDOW_H
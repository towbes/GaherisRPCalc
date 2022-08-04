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
    //Mino-relic and bugganes
    void on_bgroupMinorelic_idToggled(int val);
    //Realm point bonus potion and battlefield potion
    void on_bgroupRpPotion_idToggled(int val);

    //Guild bonus
    void on_checkGuildBonus_toggled(bool checked);

    //Neck
    void on_bgroupNeck_idToggled(int val);
    //Myth
    void on_bgroupMyth_idToggled(int val);
    //Left wrist
    void on_bgroupLeftWrist_idToggled(int val);
    //Right wrist
    void on_bgroupRightWrist_idToggled(int val);


    void on_checkOrions_toggled(bool checked);

    void on_checkTwohand_toggled(bool checked);

    void on_checkZoneBonus_toggled(bool checked);

private:
    RPCalc* rpCalc;
    Ui::MainWindow *ui;
    void setBuffBonusLabel();
    void setItemBonusLabel();
};
#endif // MAINWINDOW_H

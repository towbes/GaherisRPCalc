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
    //Zone bonus
    void on_checkZoneBonus_toggled(bool checked);
    //Neck
    void on_bgroupNeck_idToggled(int val);
    //Myth
    void on_bgroupMyth_idToggled(int val);
    //Left wrist
    void on_bgroupLeftWrist_idToggled(int val);
    //Right wrist
    void on_bgroupRightWrist_idToggled(int val);
    //belt
    void on_checkOrions_toggled(bool checked);
    //twohand
    void on_checkTwohand_toggled(bool checked);



    void on_comboStart_currentIndexChanged(int index);

    void on_comboEnd_currentIndexChanged(int index);

    void on_comboZoneBonus_currentIndexChanged(int index);

    void on_editStarting_textEdited(const QString &arg1);

    void on_editEnding_textEdited(const QString &arg1);

private:
    RPCalc* rpCalc;
    Ui::MainWindow *ui;
    void setBuffBonusLabel();
    void setItemBonusLabel();
    void fillComboBoxes();
    void updateLabels();
};
#endif // MAINWINDOW_H

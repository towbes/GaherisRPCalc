#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create a new calc object
    rpCalc = new RPCalc();
    //Setup the zone bonus combo box
    ui->comboZoneBonus->addItem("50%", 50);
    ui->comboZoneBonus->addItem("100%", 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Mino relic and bugganes don't satck
void MainWindow::on_bgroupMinorelic_idToggled(int val) {
    switch (val) {
    //none (auto numbering starts at -2 and goes down
    case -2:
       rpCalc->setMinoBonus(0);
        break;
    case -3:
        rpCalc->setMinoBonus(10);
        break;
    case -4:
        rpCalc->setMinoBonus(25);
        break;
    case -5:
        rpCalc->setMinoBonus(15);
        break;
    case -6:
        rpCalc->setMinoBonus(25);
        break;
    case -7:
        rpCalc->setMinoBonus(50);
        break;
    case -8:
        rpCalc->setMinoBonus(75);
        break;
    }
    setBuffBonusLabel();
}

//Mino relic and bugganes don't satck
void MainWindow::on_bgroupRpPotion_idToggled(int val) {
    switch (val) {
    //none (auto numbering starts at -2 and goes down
    case -2:
       rpCalc->setRpPotionBonus(0);
        break;
    case -3:
        rpCalc->setRpPotionBonus(10);
        break;
    case -4:
        rpCalc->setRpPotionBonus(25);
        break;
    case -5:
        rpCalc->setRpPotionBonus(50);
        break;
    case -6:
        rpCalc->setRpPotionBonus(25);
        break;
    }
    setBuffBonusLabel();
}

void MainWindow::setBuffBonusLabel() {
    auto printable = QStringLiteral("%1%").arg(rpCalc->getBuffsBonus());
    ui->amtBuffBonus->setText(printable);
}

void MainWindow::on_checkZoneBonus_toggled(bool checked)
{
    if (checked) {
        //Get the data from the comboZoneBonus box, cast it to an int
        rpCalc->setZoneBonus((ui->comboZoneBonus->itemData(ui->comboZoneBonus->currentIndex())).toInt());
    } else {
        rpCalc->setZoneBonus(0);
    }
}

void MainWindow::on_checkGuildBonus_toggled(bool checked)
{
    if (checked) {
        rpCalc->setGuildBonus(5);
    } else {
        rpCalc->setGuildBonus(0);
    }
}

void MainWindow::on_bgroupNeck_idToggled(int val) {
    switch (val) {
    case -2:
        rpCalc->setNeckBonus(0);
        break;
    case -3:
        rpCalc->setNeckBonus(3);
        break;
    case -4:
        rpCalc->setNeckBonus(5);
        break;
    }
    setItemBonusLabel();
}

void MainWindow::on_bgroupMyth_idToggled(int val) {
    switch (val) {
    case -2:
        rpCalc->setMythBonus(0);
        break;
    case -3:
        rpCalc->setMythBonus(2);
        break;
    case -4:
        rpCalc->setMythBonus(3);
        break;
    case -5:
        rpCalc->setMythBonus(4);
        break;
    case -6:
        rpCalc->setMythBonus(6);
        break;
    }
    setItemBonusLabel();
}

void MainWindow::on_bgroupLeftWrist_idToggled(int val) {
    switch (val) {
    case -2:
        rpCalc->setLeftWristBonus(0);
        break;
    case -3:
        rpCalc->setLeftWristBonus(6);
        break;
    case -4:
        rpCalc->setLeftWristBonus(10);
        break;
    }
    setItemBonusLabel();
}

void MainWindow::on_bgroupRightWrist_idToggled(int val) {
    switch (val) {
    case -2:
        rpCalc->setRightWristBonus(0);
        break;
    case -3:
        rpCalc->setRightWristBonus(10);
        break;
    }
    setItemBonusLabel();
}

void MainWindow::on_checkOrions_toggled(bool checked)
{
    if (checked) {
        rpCalc->setBeltBonus(5);
    } else {
        rpCalc->setBeltBonus(0);
    }
    setItemBonusLabel();
}


void MainWindow::on_checkTwohand_toggled(bool checked)
{
    if (checked) {
        rpCalc->setTwohandBonus(5);
    } else {
        rpCalc->setTwohandBonus(0);
    }
    setItemBonusLabel();
}

void MainWindow::setItemBonusLabel() {
    auto printable = QStringLiteral("%1%").arg(rpCalc->getItemBonus());
    ui->amtItemBonus->setText(printable);
}




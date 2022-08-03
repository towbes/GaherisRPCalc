#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rpCalc = new RPCalc();
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
    }
    setBuffBonusLabel();
}

void MainWindow::setBuffBonusLabel() {
    auto printable = QStringLiteral("%1%").arg(rpCalc->getBuffsBonus());
    ui->amtBuffBonus->setText(printable);
}

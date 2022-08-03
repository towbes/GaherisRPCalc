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
    }
    setBuffBonusLabel();
}

void MainWindow::setBuffBonusLabel() {
    auto printable = QStringLiteral("%1%").arg(rpCalc->getBuffsBonus());
    ui->amtBuffBonus->setText(printable);
}

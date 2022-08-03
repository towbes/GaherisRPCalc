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

void MainWindow::on_mrNone_toggled(bool checked)
{
    if (checked) {
        rpCalc->setMinoBonus(0);
        setBuffBonusLabel();
    }
}


void MainWindow::on_mrTen_toggled(bool checked)
{
    if (checked) {
        rpCalc->setMinoBonus(10);
        setBuffBonusLabel();
    }
}

void MainWindow::on_mrTwentyfive_toggled(bool checked)
{
    if (checked) {
        rpCalc->setMinoBonus(25);
        setBuffBonusLabel();
    }
}

void MainWindow::setBuffBonusLabel() {
    auto printable = QStringLiteral("%1%").arg(rpCalc->getBuffsBonus());
    ui->amtBuffBonus->setText(printable);
}

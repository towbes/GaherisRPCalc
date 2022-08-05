#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create a new calc object
    rpCalc = new RPCalc();
    fillComboBoxes();
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
    updateLabels();
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
    updateLabels();
}

void MainWindow::on_checkZoneBonus_toggled(bool checked)
{
    if (checked) {
        //Get the data from the comboZoneBonus box, cast it to an int
        rpCalc->setZoneBonus((ui->comboZoneBonus->itemData(ui->comboZoneBonus->currentIndex())).toInt());
    } else {
        rpCalc->setZoneBonus(0);
    }
    updateLabels();
}

void MainWindow::on_comboZoneBonus_currentIndexChanged(int index)
{
    if (ui->checkZoneBonus->isChecked()) {
        //Get the data from the comboZoneBonus box, cast it to an int
        rpCalc->setZoneBonus((ui->comboZoneBonus->itemData(ui->comboZoneBonus->currentIndex())).toInt());
    } else {
        rpCalc->setZoneBonus(0);
    }
    updateLabels();
}

void MainWindow::on_checkGuildBonus_toggled(bool checked)
{
    if (checked) {
        rpCalc->setGuildBonus(5);
    } else {
        rpCalc->setGuildBonus(0);
    }
    updateLabels();
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
    updateLabels();
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
    updateLabels();
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
    updateLabels();
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
    updateLabels();
}

void MainWindow::on_checkOrions_toggled(bool checked)
{
    if (checked) {
        rpCalc->setBeltBonus(5);
    } else {
        rpCalc->setBeltBonus(0);
    }
    updateLabels();
}


void MainWindow::on_checkTwohand_toggled(bool checked)
{
    if (checked) {
        rpCalc->setTwohandBonus(5);
    } else {
        rpCalc->setTwohandBonus(0);
    }
    updateLabels();
}

void MainWindow::on_comboStart_currentIndexChanged(int index)
{
    int startingRP = ui->comboStart->itemData(ui->comboStart->currentIndex()).toInt();
    ui->editStarting->setText(QLocale(QLocale::English).toString((startingRP)));
    updateLabels();
}

//Manual start editing
void MainWindow::on_editStarting_textEdited(const QString &arg1)
{
    updateLabels();
}


void MainWindow::on_comboEnd_currentIndexChanged(int index)
{
    int endingRP = ui->comboEnd->itemData(ui->comboEnd->currentIndex()).toInt();
    ui->editEnding->setText(QLocale(QLocale::English).toString((endingRP)));
    updateLabels();
}

void MainWindow::on_editEnding_textEdited(const QString &arg1)
{
    updateLabels();
}

void MainWindow::updateLabels() {
    //buff bonus
    auto printableBuffs = QStringLiteral("%1%").arg(rpCalc->getBuffsBonus());
    ui->amtBuffBonus->setText(printableBuffs);

    //Item bonus
    auto printableItems = QStringLiteral("%1%").arg(rpCalc->getItemBonus());
    ui->amtItemBonus->setText(printableItems);

    //Per seal totals
    int baseSeal = rpCalc->getModSealBase();
    auto basePrintable = QStringLiteral("You earn %1 realm points.").arg(QLocale(QLocale::English).toString((baseSeal)));
    ui->labelModBasePoints->setText(basePrintable);
    int buffSeal = rpCalc->getPerSealBuffs();
    auto buffPrintable = QStringLiteral("You earn %1 extra realm points from buffs.").arg(QLocale(QLocale::English).toString((buffSeal)));
    ui->labelBuffPoints->setText(buffPrintable);
    int zoneSeal = rpCalc->getPerSealZone();
    auto zonePrintable = QStringLiteral("You earn %1 extra realm points for fighting in this zone.").arg(QLocale(QLocale::English).toString((zoneSeal)));
    ui->labelZonePoints->setText(zonePrintable);
    int itemSeal = rpCalc->getPerSealItem();
    auto itemPrintable = QStringLiteral("You earn %1 extra realm points from your artifact (items).").arg(QLocale(QLocale::English).toString((itemSeal)));
    ui->labelItemPoints->setText(itemPrintable);
    int guildSeal = rpCalc->getPerSealGuild();
    auto guildPrintable = QStringLiteral("You earn %1 extra realm points from your guild merit bonus.").arg(QLocale(QLocale::English).toString((guildSeal)));
    ui->labelGuildPoints->setText(guildPrintable);
    int totalSeal = rpCalc->getPerSealTotal();
    auto totalPrintable = QStringLiteral("%1 realm points per seal").arg(QLocale(QLocale::English).toString((totalSeal)));
    ui->labelPerSealPoints->setText(totalPrintable);


    //Calc totals
    int startingRP = 0;
    int endingRP = 0;
    //if starting was modified by the user, grab the starting text, otherwise use the combo value
    if (ui->editStarting->isModified()) {
         startingRP = ui->editStarting->text().toInt();
    } else {
        startingRP = ui->comboStart->itemData(ui->comboStart->currentIndex()).toInt();
    }
    //if ending was modified by the user, grab the starting text, otherwise use the combo value
    if (ui->editEnding->isModified()) {
        endingRP = ui->editEnding->text().toInt();
    } else {
        endingRP = ui->comboEnd->itemData(ui->comboEnd->currentIndex()).toInt();
    }
    //Update labels
    auto startingPrintable = QStringLiteral("Starting Realm Points = %1").arg(QLocale(QLocale::English).toString((startingRP)));
    ui->labelStartingPoints->setText(startingPrintable);
    auto endingPrintable = QStringLiteral("Ending Realm Points = %1").arg(QLocale(QLocale::English).toString((endingRP)));
    ui->labelEndingPoints->setText(endingPrintable);

    int sealsNeeded = rpCalc->getSealsNeeded(startingRP, endingRP);
    auto sealsPrintable = QStringLiteral("Seals needed: %1").arg(QLocale(QLocale::English).toString(sealsNeeded));
    ui->labelSealsNeeded->setText(sealsPrintable);
    int effsNeeded = rpCalc->getEffsNeeded(startingRP, endingRP);
    auto effsPrintable  = QStringLiteral("Effulgent seals needed: %1").arg(effsNeeded);
    ui->labelEffsNeeded->setText(effsPrintable);
}


void MainWindow::fillComboBoxes() {
    //Setup the zone bonus combo box
    ui->comboZoneBonus->addItem("50%", 50);
    ui->comboZoneBonus->addItem("100%", 100);

    //Setup the starting and ending combo boxes
    ui->comboStart->addItem("1L1",	0);
    ui->comboStart->addItem("1L2",	25);
    ui->comboStart->addItem("1L3",	125);
    ui->comboStart->addItem("1L4",	350);
    ui->comboStart->addItem("1L5",	750);
    ui->comboStart->addItem("1L6",	1375);
    ui->comboStart->addItem("1L7",	2275);
    ui->comboStart->addItem("1L8",	3500);
    ui->comboStart->addItem("1L9",	5100);
    ui->comboStart->addItem("2L0",	7125);
    ui->comboStart->addItem("2L1",	9625);
    ui->comboStart->addItem("2L2",	12650);
    ui->comboStart->addItem("2L3",	16250);
    ui->comboStart->addItem("2L4",	20475);
    ui->comboStart->addItem("2L5",	25375);
    ui->comboStart->addItem("2L6",	31000);
    ui->comboStart->addItem("2L7",	37400);
    ui->comboStart->addItem("2L8",	44625);
    ui->comboStart->addItem("2L9",	52725);
    ui->comboStart->addItem("3L0",	61750);
    ui->comboStart->addItem("3L1",	71750);
    ui->comboStart->addItem("3L2",	82775);
    ui->comboStart->addItem("3L3",	94875);
    ui->comboStart->addItem("3L4",	108100);
    ui->comboStart->addItem("3L5",	122500);
    ui->comboStart->addItem("3L6",	138125);
    ui->comboStart->addItem("3L7",	155025);
    ui->comboStart->addItem("3L8",	173250);
    ui->comboStart->addItem("3L9",	192850);
    ui->comboStart->addItem("4L0",	213875);
    ui->comboStart->addItem("4L1",	236375);
    ui->comboStart->addItem("4L2",	260400);
    ui->comboStart->addItem("4L3",	286000);
    ui->comboStart->addItem("4L4",	313225);
    ui->comboStart->addItem("4L5",	342125);
    ui->comboStart->addItem("4L6",	372750);
    ui->comboStart->addItem("4L7",	405150);
    ui->comboStart->addItem("4L8",	439375);
    ui->comboStart->addItem("4L9",	475475);
    ui->comboStart->addItem("5L0",	513500);
    ui->comboStart->addItem("5L1",	553500);
    ui->comboStart->addItem("5L2",	595525);
    ui->comboStart->addItem("5L3",	639625);
    ui->comboStart->addItem("5L4",	685850);
    ui->comboStart->addItem("5L5",	734250);
    ui->comboStart->addItem("5L6",	784875);
    ui->comboStart->addItem("5L7",	837775);
    ui->comboStart->addItem("5L8",	893000);
    ui->comboStart->addItem("5L9",	950600);
    ui->comboStart->addItem("6L0",	1010625);
    ui->comboStart->addItem("6L1",	1073125);
    ui->comboStart->addItem("6L2",	1138150);
    ui->comboStart->addItem("6L3",	1205750);
    ui->comboStart->addItem("6L4",	1275975);
    ui->comboStart->addItem("6L5",	1348875);
    ui->comboStart->addItem("6L6",	1424500);
    ui->comboStart->addItem("6L7",	1502900);
    ui->comboStart->addItem("6L8",	1584125);
    ui->comboStart->addItem("6L9",	1668225);
    ui->comboStart->addItem("7L0",	1755250);
    ui->comboStart->addItem("7L1",	1845250);
    ui->comboStart->addItem("7L2",	1938275);
    ui->comboStart->addItem("7L3",	2034375);
    ui->comboStart->addItem("7L4",	2133600);
    ui->comboStart->addItem("7L5",	2236000);
    ui->comboStart->addItem("7L6",	2341625);
    ui->comboStart->addItem("7L7",	2450525);
    ui->comboStart->addItem("7L8",	2562750);
    ui->comboStart->addItem("7L9",	2678350);
    ui->comboStart->addItem("8L0",	2797375);
    ui->comboStart->addItem("8L1",	2919875);
    ui->comboStart->addItem("8L2",	3045900);
    ui->comboStart->addItem("8L3",	3175500);
    ui->comboStart->addItem("8L4",	3308725);
    ui->comboStart->addItem("8L5",	3445625);
    ui->comboStart->addItem("8L6",	3586250);
    ui->comboStart->addItem("8L7",	3730650);
    ui->comboStart->addItem("8L8",	3878875);
    ui->comboStart->addItem("8L9",	4030975);
    ui->comboStart->addItem("9L0",	4187000);
    ui->comboStart->addItem("9L1",	4347000);
    ui->comboStart->addItem("9L2",	4511025);
    ui->comboStart->addItem("9L3",	4679125);
    ui->comboStart->addItem("9L4",	4851350);
    ui->comboStart->addItem("9L5",	5027750);
    ui->comboStart->addItem("9L6",	5208375);
    ui->comboStart->addItem("9L7",	5393275);
    ui->comboStart->addItem("9L8",	5582500);
    ui->comboStart->addItem("9L9",	5776100);
    ui->comboStart->addItem("10L0", 5974125);
    ui->comboStart->addItem("10L1", 6176625);
    ui->comboStart->addItem("10L2", 6383650);
    ui->comboStart->addItem("10L3", 6595250);
    ui->comboStart->addItem("10L4", 6811475);
    ui->comboStart->addItem("10L5", 7032375);
    ui->comboStart->addItem("10L6", 7258000);
    ui->comboStart->addItem("10L7", 7488400);
    ui->comboStart->addItem("10L8", 7723625);
    ui->comboStart->addItem("10L9", 7963725);
    ui->comboStart->addItem("11L0", 8208750);
    ui->comboStart->addItem("11L1", 9111713);
    ui->comboStart->addItem("11L2", 10114001);
    ui->comboStart->addItem("11L3", 11226541);
    ui->comboStart->addItem("11L4", 12461460);
    ui->comboStart->addItem("11L5", 13832221);
    ui->comboStart->addItem("11L6", 15353765);
    ui->comboStart->addItem("11L7", 17042680);
    ui->comboStart->addItem("11L8", 18917374);
    ui->comboStart->addItem("11L9", 20998286);
    ui->comboStart->addItem("12L0", 23308097);
    ui->comboStart->addItem("12L1", 25871988);
    ui->comboStart->addItem("12L2", 28717906);
    ui->comboStart->addItem("12L3", 31876876);
    ui->comboStart->addItem("12L4", 35383333);
    ui->comboStart->addItem("12L5", 39275499);
    ui->comboStart->addItem("12L6", 43595804);
    ui->comboStart->addItem("12L7", 48391343);
    ui->comboStart->addItem("12L8", 53714390);
    ui->comboStart->addItem("12L9", 59622973);
    ui->comboStart->addItem("13L0", 66181501);
    ui->comboStart->addItem("13L1", 73461466);
    ui->comboStart->addItem("13L2", 81542227);
    ui->comboStart->addItem("13L3", 90511872);
    ui->comboStart->addItem("13L4", 100468178);
    ui->comboStart->addItem("13L5", 111519678);
    ui->comboStart->addItem("13L6", 123786843);
    ui->comboStart->addItem("13L7", 137403395);
    ui->comboStart->addItem("13L8", 152517769);
    ui->comboStart->addItem("13L9", 169294723);
    ui->comboStart->addItem("14L0", 187917143);

    ui->comboEnd->addItem("1L1",  0);
    ui->comboEnd->addItem("1L2",  25);
    ui->comboEnd->addItem("1L3",  125);
    ui->comboEnd->addItem("1L4",  350);
    ui->comboEnd->addItem("1L5",  750);
    ui->comboEnd->addItem("1L6",  1375);
    ui->comboEnd->addItem("1L7",  2275);
    ui->comboEnd->addItem("1L8",  3500);
    ui->comboEnd->addItem("1L9",  5100);
    ui->comboEnd->addItem("2L0",  7125);
    ui->comboEnd->addItem("2L1",  9625);
    ui->comboEnd->addItem("2L2",  12650);
    ui->comboEnd->addItem("2L3",  16250);
    ui->comboEnd->addItem("2L4",  20475);
    ui->comboEnd->addItem("2L5",  25375);
    ui->comboEnd->addItem("2L6",  31000);
    ui->comboEnd->addItem("2L7",  37400);
    ui->comboEnd->addItem("2L8",  44625);
    ui->comboEnd->addItem("2L9",  52725);
    ui->comboEnd->addItem("3L0",  61750);
    ui->comboEnd->addItem("3L1",  71750);
    ui->comboEnd->addItem("3L2",  82775);
    ui->comboEnd->addItem("3L3",  94875);
    ui->comboEnd->addItem("3L4",  108100);
    ui->comboEnd->addItem("3L5",  122500);
    ui->comboEnd->addItem("3L6",  138125);
    ui->comboEnd->addItem("3L7",  155025);
    ui->comboEnd->addItem("3L8",  173250);
    ui->comboEnd->addItem("3L9",  192850);
    ui->comboEnd->addItem("4L0",  213875);
    ui->comboEnd->addItem("4L1",  236375);
    ui->comboEnd->addItem("4L2",  260400);
    ui->comboEnd->addItem("4L3",  286000);
    ui->comboEnd->addItem("4L4",  313225);
    ui->comboEnd->addItem("4L5",  342125);
    ui->comboEnd->addItem("4L6",  372750);
    ui->comboEnd->addItem("4L7",  405150);
    ui->comboEnd->addItem("4L8",  439375);
    ui->comboEnd->addItem("4L9",  475475);
    ui->comboEnd->addItem("5L0",  513500);
    ui->comboEnd->addItem("5L1",  553500);
    ui->comboEnd->addItem("5L2",  595525);
    ui->comboEnd->addItem("5L3",  639625);
    ui->comboEnd->addItem("5L4",  685850);
    ui->comboEnd->addItem("5L5",  734250);
    ui->comboEnd->addItem("5L6",  784875);
    ui->comboEnd->addItem("5L7",  837775);
    ui->comboEnd->addItem("5L8",  893000);
    ui->comboEnd->addItem("5L9",  950600);
    ui->comboEnd->addItem("6L0",  1010625);
    ui->comboEnd->addItem("6L1",  1073125);
    ui->comboEnd->addItem("6L2",  1138150);
    ui->comboEnd->addItem("6L3",  1205750);
    ui->comboEnd->addItem("6L4",  1275975);
    ui->comboEnd->addItem("6L5",  1348875);
    ui->comboEnd->addItem("6L6",  1424500);
    ui->comboEnd->addItem("6L7",  1502900);
    ui->comboEnd->addItem("6L8",  1584125);
    ui->comboEnd->addItem("6L9",  1668225);
    ui->comboEnd->addItem("7L0",  1755250);
    ui->comboEnd->addItem("7L1",  1845250);
    ui->comboEnd->addItem("7L2",  1938275);
    ui->comboEnd->addItem("7L3",  2034375);
    ui->comboEnd->addItem("7L4",  2133600);
    ui->comboEnd->addItem("7L5",  2236000);
    ui->comboEnd->addItem("7L6",  2341625);
    ui->comboEnd->addItem("7L7",  2450525);
    ui->comboEnd->addItem("7L8",  2562750);
    ui->comboEnd->addItem("7L9",  2678350);
    ui->comboEnd->addItem("8L0",  2797375);
    ui->comboEnd->addItem("8L1",  2919875);
    ui->comboEnd->addItem("8L2",  3045900);
    ui->comboEnd->addItem("8L3",  3175500);
    ui->comboEnd->addItem("8L4",  3308725);
    ui->comboEnd->addItem("8L5",  3445625);
    ui->comboEnd->addItem("8L6",  3586250);
    ui->comboEnd->addItem("8L7",  3730650);
    ui->comboEnd->addItem("8L8",  3878875);
    ui->comboEnd->addItem("8L9",  4030975);
    ui->comboEnd->addItem("9L0",  4187000);
    ui->comboEnd->addItem("9L1",  4347000);
    ui->comboEnd->addItem("9L2",  4511025);
    ui->comboEnd->addItem("9L3",  4679125);
    ui->comboEnd->addItem("9L4",  4851350);
    ui->comboEnd->addItem("9L5",  5027750);
    ui->comboEnd->addItem("9L6",  5208375);
    ui->comboEnd->addItem("9L7",  5393275);
    ui->comboEnd->addItem("9L8",  5582500);
    ui->comboEnd->addItem("9L9",  5776100);
    ui->comboEnd->addItem("10L0", 5974125);
    ui->comboEnd->addItem("10L1", 6176625);
    ui->comboEnd->addItem("10L2", 6383650);
    ui->comboEnd->addItem("10L3", 6595250);
    ui->comboEnd->addItem("10L4", 6811475);
    ui->comboEnd->addItem("10L5", 7032375);
    ui->comboEnd->addItem("10L6", 7258000);
    ui->comboEnd->addItem("10L7", 7488400);
    ui->comboEnd->addItem("10L8", 7723625);
    ui->comboEnd->addItem("10L9", 7963725);
    ui->comboEnd->addItem("11L0", 8208750);
    ui->comboEnd->addItem("11L1", 9111713);
    ui->comboEnd->addItem("11L2", 10114001);
    ui->comboEnd->addItem("11L3", 11226541);
    ui->comboEnd->addItem("11L4", 12461460);
    ui->comboEnd->addItem("11L5", 13832221);
    ui->comboEnd->addItem("11L6", 15353765);
    ui->comboEnd->addItem("11L7", 17042680);
    ui->comboEnd->addItem("11L8", 18917374);
    ui->comboEnd->addItem("11L9", 20998286);
    ui->comboEnd->addItem("12L0", 23308097);
    ui->comboEnd->addItem("12L1", 25871988);
    ui->comboEnd->addItem("12L2", 28717906);
    ui->comboEnd->addItem("12L3", 31876876);
    ui->comboEnd->addItem("12L4", 35383333);
    ui->comboEnd->addItem("12L5", 39275499);
    ui->comboEnd->addItem("12L6", 43595804);
    ui->comboEnd->addItem("12L7", 48391343);
    ui->comboEnd->addItem("12L8", 53714390);
    ui->comboEnd->addItem("12L9", 59622973);
    ui->comboEnd->addItem("13L0", 66181501);
    ui->comboEnd->addItem("13L1", 73461466);
    ui->comboEnd->addItem("13L2", 81542227);
    ui->comboEnd->addItem("13L3", 90511872);
    ui->comboEnd->addItem("13L4", 100468178);
    ui->comboEnd->addItem("13L5", 111519678);
    ui->comboEnd->addItem("13L6", 123786843);
    ui->comboEnd->addItem("13L7", 137403395);
    ui->comboEnd->addItem("13L8", 152517769);
    ui->comboEnd->addItem("13L9", 169294723);
    ui->comboEnd->addItem("14L0", 187917143);

}

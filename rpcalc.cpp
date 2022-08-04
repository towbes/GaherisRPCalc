#include "rpcalc.h"

RPCalc::RPCalc()
{
    //Base points
    sealBase = 3000;
    serverBonus = 25;

    //Category Bonuses
    buffsBonus = 0;
    zoneBonus = 0;
    guildBonus = 0;
    itemBonus = 0;

    //Sub-category bonuses
    minoBonus = 0;
    rpPotionBonus = 0;
    battlePotionBonus = 0;
    neckBonus = 0;
    mythBonus = 0;
    leftWristBonus = 0;
    rightWristBonus = 0;
    beltBonus = 0;
    twohandBonus = 0;

}

int RPCalc::getSealBase() {
    return sealBase;
}

int RPCalc::getServerBonus() {
    return serverBonus;
}

int RPCalc::getModSealBase() {
    return sealBase * (serverBonus / 100);
}

int RPCalc::getBuffsBonus(){
    buffsBonus = 0;
    buffsBonus += minoBonus + rpPotionBonus + battlePotionBonus;
    return buffsBonus;
}

int RPCalc::getItemBonus() {
    itemBonus = 0;
    itemBonus += neckBonus + mythBonus + leftWristBonus + rightWristBonus + beltBonus + twohandBonus;
    return itemBonus;
}

void RPCalc::setMinoBonus(int value) {
    minoBonus = value;
}

void RPCalc::setRpPotionBonus(int value) {
    rpPotionBonus = value;
}
void RPCalc::setBattlePotionBonus(int value) {
    battlePotionBonus = value;
}

void RPCalc::setZoneBonus(int value) {
    zoneBonus = value;
}

void RPCalc::setGuildBonus(int value) {
    guildBonus = value;
}

void RPCalc::setNeckBonus(int value) {
    neckBonus = value;
}

void RPCalc::setMythBonus(int value) {
    mythBonus = value;
}

void RPCalc::setLeftWristBonus(int value) {
    leftWristBonus = value;
}

void RPCalc::setRightWristBonus(int value) {
    rightWristBonus = value;
}

void RPCalc::setBeltBonus(int value) {
    beltBonus = value;
}

void RPCalc::setTwohandBonus(int value) {
    twohandBonus = value;
}

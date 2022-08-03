#include "rpcalc.h"

RPCalc::RPCalc()
{
    buffsBonus = 0;
    minoBonus = 0;
    rpPotionBonus = 0;
    battlePotionBonus = 0;
}

int RPCalc::getBuffsBonus(){
    buffsBonus = 0;
    buffsBonus += minoBonus + rpPotionBonus + battlePotionBonus;
    return buffsBonus;
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


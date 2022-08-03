#include "rpcalc.h"

RPCalc::RPCalc()
{
    buffsBonus = 0;
    minoBonus = 0;
}

int RPCalc::getBuffsBonus(){
    buffsBonus = 0;
    buffsBonus += minoBonus;
    return buffsBonus;
}

int RPCalc::getMinoBonus(){
    return minoBonus;
}

void RPCalc::setMinoBonus(int value) {
    minoBonus = value;
}


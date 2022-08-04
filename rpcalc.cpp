#include "rpcalc.h"
#include <math.h>

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

float RPCalc::getSealBase() {
    return sealBase;
}

float RPCalc::getServerBonus() {
    return serverBonus;
}

float RPCalc::getModSealBase() {
    float plusMod = (float)serverBonus / 100;
    float modSealBase = sealBase * plusMod;
    float modSealTotal = sealBase + modSealBase;
    return modSealTotal;
}

float RPCalc::getPerSealBuffs() {
    float plusBuffs = (float)getBuffsBonus() / 100;
    return getModSealBase() * plusBuffs;
}

float RPCalc::getPerSealZone() {
    float plusZone = (float)zoneBonus / 100;
    return getModSealBase() * plusZone;
}

float RPCalc::getPerSealGuild() {
    float plusGuild = (float)guildBonus / 100;
    return getModSealBase() * plusGuild;
}

float RPCalc::getPerSealItem() {
    float plusItem = (float)getItemBonus() / 100;
    return getModSealBase() * plusItem;
}

float RPCalc::getPerSealTotal() {
    return floor(getModSealBase()) + floor(getPerSealBuffs()) + floor(getPerSealZone()) + floor(getPerSealGuild()) + floor(getPerSealItem());
}

float RPCalc::getBuffsBonus(){
    buffsBonus = 0;
    buffsBonus += minoBonus + rpPotionBonus + battlePotionBonus;
    return buffsBonus;
}

float RPCalc::getItemBonus() {
    itemBonus = 0;
    itemBonus += neckBonus + mythBonus + leftWristBonus + rightWristBonus + beltBonus + twohandBonus;
    return itemBonus;
}

void RPCalc::setMinoBonus(float value) {
    minoBonus = value;
}

void RPCalc::setRpPotionBonus(float value) {
    rpPotionBonus = value;
}
void RPCalc::setBattlePotionBonus(float value) {
    battlePotionBonus = value;
}

void RPCalc::setZoneBonus(float value) {
    zoneBonus = value;
}

void RPCalc::setGuildBonus(float value) {
    guildBonus = value;
}

void RPCalc::setNeckBonus(float value) {
    neckBonus = value;
}

void RPCalc::setMythBonus(float value) {
    mythBonus = value;
}

void RPCalc::setLeftWristBonus(float value) {
    leftWristBonus = value;
}

void RPCalc::setRightWristBonus(float value) {
    rightWristBonus = value;
}

void RPCalc::setBeltBonus(float value) {
    beltBonus = value;
}

void RPCalc::setTwohandBonus(float value) {
    twohandBonus = value;
}

float RPCalc::getSealsNeeded(int starting, int ending) {
    int rpNeeded = ending - starting;
    if (getPerSealTotal() > 0) {
        if (rpNeeded > 0) {
            if (rpNeeded / getPerSealTotal() > 0) {
                    return ceil(rpNeeded / getPerSealTotal());
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

float RPCalc::getEffsNeeded(int starting, int ending) {
    if (getSealsNeeded(starting, ending) / 250 > 1) {
        return ceil(getSealsNeeded(starting, ending) / 250);
    } else if (getSealsNeeded(starting, ending) == 0) {
        return 0;
    } else {
        return 1;
    }
}

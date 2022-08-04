#ifndef RPCALC_H
#define RPCALC_H


class RPCalc
{
public:
    RPCalc();

    //Base points
    int getSealBase();
    int getServerBonus();
    int getModSealBase();

    //Category bonuses
    int getBuffsBonus();
    void setGuildBonus(int value);
    void setNeckBonus(int value);
    int getItemBonus();

    //Sub-category bonuses
    void setMinoBonus(int value);
    void setRpPotionBonus(int value);
    void setBattlePotionBonus(int value);
    void setZoneBonus(int value);
    void setMythBonus(int value);
    void setLeftWristBonus(int value);
    void setRightWristBonus(int value);
    void setBeltBonus(int value);
    void setTwohandBonus(int value);
private:

    //Base points
    int sealBase;
    int serverBonus;

    //Category Bonuses
    int buffsBonus;
    int zoneBonus;
    int guildBonus;
    int itemBonus;

    //Sub-category bonuses
    int minoBonus;
    int rpPotionBonus;
    int battlePotionBonus;
    int neckBonus;
    int mythBonus;
    int leftWristBonus;
    int rightWristBonus;
    int beltBonus;
    int twohandBonus;
};

#endif // RPCALC_H

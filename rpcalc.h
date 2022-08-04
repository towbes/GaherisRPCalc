#ifndef RPCALC_H
#define RPCALC_H


class RPCalc
{
public:
    RPCalc();

    //Base points
    float getSealBase();
    float getServerBonus();
    float getModSealBase();

    //Per seal calculations
    float getPerSealBuffs();
    float getPerSealZone();
    float getPerSealGuild();
    float getPerSealItem();
    float getPerSealTotal();

    //Category bonuses
    float getBuffsBonus();
    void setGuildBonus(float value);
    void setNeckBonus(float value);
    float getItemBonus();

    //Sub-category bonuses
    void setMinoBonus(float value);
    void setRpPotionBonus(float value);
    void setBattlePotionBonus(float value);
    void setZoneBonus(float value);
    void setMythBonus(float value);
    void setLeftWristBonus(float value);
    void setRightWristBonus(float value);
    void setBeltBonus(float value);
    void setTwohandBonus(float value);

    //Seal calculator
    float getSealsNeeded(int starting, int ending);
    float getEffsNeeded(int starting, int ending);

private:

    //Base points
    float sealBase;
    float serverBonus;

    //Category Bonuses
    float buffsBonus;
    float zoneBonus;
    float guildBonus;
    float itemBonus;

    //Sub-category bonuses
    float minoBonus;
    float rpPotionBonus;
    float battlePotionBonus;
    float neckBonus;
    float mythBonus;
    float leftWristBonus;
    float rightWristBonus;
    float beltBonus;
    float twohandBonus;

};

#endif // RPCALC_H

#ifndef RPCALC_H
#define RPCALC_H


class RPCalc
{
public:
    RPCalc();
    int getBuffsBonus();
    void setMinoBonus(int value);
    void setRpPotionBonus(int value);
    void setBattlePotionBonus(int value);
private:
    int buffsBonus;
    int minoBonus;
    int rpPotionBonus;
    int battlePotionBonus;
};

#endif // RPCALC_H

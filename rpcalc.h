#ifndef RPCALC_H
#define RPCALC_H


class RPCalc
{
public:
    RPCalc();
    int getBuffsBonus();
    int getMinoBonus();
    void setMinoBonus(int value);
private:
    int buffsBonus;
    int minoBonus;
};

#endif // RPCALC_H

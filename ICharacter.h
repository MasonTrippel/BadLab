#pragma once
#include<memory>

class IRace;
class IClass;

class Icharacter{

    public:
        Icharacter(std::shared_ptr<IRace> m_race, std::shared_ptr<IClass> m_class,  int hitPoint, int  armorClass, int  hitBonus, int initiative){}
        ~Icharacter() {}

    protected:
        int m_hitPoint;
        int m_armorClass;
        int m_hitBonus;
        int m_initiative;

};
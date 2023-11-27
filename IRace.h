#pragma once

class IRace{
    public:
        IRace(int hitPointMod, int  armorClassMod, int  hitBonusMod, int initiativeBonus) : 
        m_hitPointMod(hitPointMod),
        m_armorClassMod(armorClassMod),
        m_hitBonusMod(hitBonusMod),
        m_initiativeBonus(initiativeBonus) {}

        ~IRace() {}

        int getHitPointMod(){return m_hitPointMod;}

        int getArmorClassMod(){return m_armorClassMod;}

        int getHitBonusMod(){return m_hitBonusMod;}

        int getInitiativeBonus(){return m_initiativeBonus;}

    protected:
        int m_hitPointMod;
        int m_armorClassMod;
        int m_hitBonusMod;
        int m_initiativeBonus;
        int classType;

};
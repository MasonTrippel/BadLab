#pragma once
#include <string>
#include "IRace.h"
#include <memory>
#include<random>
class IClass{
    public:
        IClass(std::shared_ptr<IRace> race) : 
        m_hitPoint(0),
        m_armorClass(0),
        m_hitBonus(0),
        m_initiative(0),
        m_baseDamage(0),
        m_healing(0),
        m_race(race) {};
        
        

        virtual int getHitPoints(){
            int retVal = m_hitPoint + m_race->getHitPointMod();
            return retVal;
        }

        virtual int getArmorClass(){
            int retVal = m_armorClass + m_race->getArmorClassMod();
            return retVal;
        }

        virtual int getHitBonus(){
            int retVal = m_hitBonus + m_race->getHitBonusMod();
            return retVal;
        }

        virtual int getInitiative(){
            int retVal = m_initiative + m_race->getInitiativeBonus();
            return retVal;
        }

        virtual int getHealing(){
            int retVal = m_initiative + m_race->getInitiativeBonus();
            return retVal;
        }

        int getClassType()
        { return classType;}

        //removes hitpoints from character when getting attacked, taking into account armor
        void takeDamage(int damage){
            int totalDamage = (damage + rand()%20 + 1) - getArmorClass()/2;
            if(totalDamage > 2){
                m_hitPoint -= totalDamage;
            }
            //feels wierd to do no damage at all
            else{
                m_hitPoint -= 2;
            }
        }

    protected:
        int m_hitPoint;
        int m_armorClass;
        int m_hitBonus;
        int m_initiative;
        int m_baseDamage;
        int m_healing;
        std::shared_ptr<IRace> m_race;
        int classType;
        
};
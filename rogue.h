#include "IClass.h"

class rogue : public IClass{
    public:
        rogue(std::shared_ptr<IRace> race) : IClass(race){
        m_hitPoint = 16;
        //easier to hit
        m_armorClass = 12;
        m_hitBonus = 4;
        m_initiative = 20;
        //high single target damage
        m_baseDamage = 5;
        classType = 3;
	}

    virtual ~rogue() {}
    rogue() = delete;

    private:


};
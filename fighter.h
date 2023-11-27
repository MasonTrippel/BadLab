#include "IClass.h"

class fighter : public IClass{
    public: 
        fighter(std::shared_ptr<IRace> race) : IClass(race){
        m_hitPoint = 20;
        //harder to hit
        m_armorClass = 16;
        m_hitBonus = 3;
        m_initiative = 16;
        //mid base damage
        m_baseDamage = 2;
        classType = 1;
	}

    virtual ~fighter() {}
    fighter() = delete;

	
    private:


};
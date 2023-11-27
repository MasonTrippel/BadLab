#include "IClass.h"

class cleric : public IClass{
    public:
        cleric(std::shared_ptr<IRace> race) : IClass(race){
        m_hitPoint = 16;
        //not easy to hit but not too difficult
        m_armorClass = 14;
        m_hitBonus = 2;
        m_initiative = 12;
        //lower damage but can heal
        m_baseDamage = 2;
        m_healing = 2;
        classType = 2;
	}

    virtual ~cleric() {}
    cleric() = delete;

    private:
        int m_healing;

};
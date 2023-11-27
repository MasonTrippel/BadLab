#include "characterFactory.h"


#include "cleric.h"
#include "dwarf.h"
#include "elf.h"
#include "fighter.h"
#include "halfling.h"
#include "human.h"
#include "rogue.h"
#include "wizard.h"


characterFactory & characterFactory::GetCharacterFactory()
{
	static characterFactory c;
	return c;
} // instance


std::shared_ptr<IClass> characterFactory::CreateCharacter(enumOfTypeClass enumOfTypeClassType, raceOfTypeClass raceType)
{
	std::shared_ptr<IClass> retVal = nullptr;
	if (enumOfTypeClassType == Fighter)
	{
		retVal = std::make_shared<fighter>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == Cleric)
	{
		retVal = std::make_shared<cleric>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == Rogue)
	{
		retVal = std::make_shared<rogue>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == Wizard)
	{
		retVal = std::make_shared<wizard>(m_raceMap[raceType]);
	}
    
	return retVal;
}

characterFactory::characterFactory() 
{
		
	std::shared_ptr<IRace> t1 = std::make_shared<elf>();
	std::shared_ptr<IRace> t2 = std::make_shared<dwarf>();
    std::shared_ptr<IRace> t3 = std::make_shared<halfling>();
	std::shared_ptr<IRace> t4 = std::make_shared<human>();
	m_raceMap[Elf] = t1;
	m_raceMap[Dwarf] = t2;
    m_raceMap[Halfling] = t3;
    m_raceMap[Human] = t4;
}


 characterFactory::~characterFactory() 
{
    m_raceMap.clear();
}

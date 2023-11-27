#pragma once


#include "IClass.h"
#include <memory>
#include <map>

//fwd declaration
class IRace;

class characterFactory
{
public:
	enum enumOfTypeClass { Fighter, Cleric, Rogue, Wizard };
	enum raceOfTypeClass { Dwarf, Elf, Halfling, Human};


	std::shared_ptr<IClass>  CreateCharacter(enumOfTypeClass classType, raceOfTypeClass raceType);

	static 	characterFactory & GetCharacterFactory();

  	characterFactory(const characterFactory &) = delete;
  	characterFactory & operator = (const characterFactory &) = delete;

private:
	std::map<raceOfTypeClass,std::shared_ptr<IRace>> m_raceMap;

	characterFactory();
    ~characterFactory();

};

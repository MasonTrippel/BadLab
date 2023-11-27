#include "party.h"
#include "ICharacter.h"
#include "IClass.h"
#include <iostream>
Party::Party(){

}

Party::Party(const std::shared_ptr<IClass> character) : m_flagClass(character){
    m_party.push_back(character);
}

void Party::setFlagClass(const std::shared_ptr<IClass> character){
    m_flagClass = character;
}

std::shared_ptr<IClass> Party::getCharacter() const {
    return m_flagClass;
}

void Party::addCharacter(const std::shared_ptr<IClass> character){
    if (m_party.size() != 0){
        for (int i = 0; i<m_party.size(); i++){
            if(m_party[i]->getClassType() >= character->getClassType())
            {
                m_party.insert(m_party.begin()+i, character);
                return;
            }

        }
        m_party.push_back(character);
    
    }
    else{
        m_party.push_back(character);
        m_flagClass = character;
    }
}

std::vector<std::shared_ptr<IClass>> Party::getParty(){
    return m_party;
}

void Party::removeCharacter(std::shared_ptr<IClass> characterToRemove){
    for(int i = 0; i<m_party.size();i++){
        if(m_party[i] == characterToRemove){
            m_party.erase(m_party.begin() + i);
            return;
        }
    }
}



#include "Duel.h"


Duel::Duel()
{
}

void Duel::attack(std::shared_ptr<IClass> attacker, Party &attackerParty, Party &defender)
{
    //first check if the attacker is a cleric that will heal the frontmost character on the team
    if(attacker->getClassType() == 2){
        attackerParty.getParty()[0]->takeDamage(-3);
    }
   

    //wizard does splash damage so it needs its own case
    if(attacker->getClassType() == 4){
       
        defender.getParty()[0]->takeDamage(attacker->getHitBonus());
       
        if(defender.getParty().size() > 1){
        defender.getParty()[1]->takeDamage(attacker->getHitBonus());
        }

    }


    else{
        defender.getParty()[0]->takeDamage(attacker->getHitBonus());
    }


    checkHP(defender);
    
}

void Duel::checkHP(Party &defender)
{
    //only need to check the first and second characters b/c no more than that can get damaged
    if(defender.getParty()[0]->getHitPoints() <= 0){
       
        defender.removeCharacter(defender.getParty()[0]);
        
        if(defender.getParty().size() > 1 && defender.getParty()[0]->getHitPoints() <= 0){
            defender.removeCharacter(defender.getParty()[0]);
        }

    }
    else if(defender.getParty().size() > 1 && defender.getParty()[1]->getHitPoints() <= 0){
        defender.removeCharacter(defender.getParty()[1]);
    }
}


 void Duel::printStats(Party p1, Party p2){
    std::cout << "Class 1: Fighter,Class 2: Cleric,Class 3: Rouge,Class 4: Wizard \n\n" 
    << "Party 1:\n";
    
    for(auto character : p1.getParty()){
        std::cout << "  Class: "<< character->getClassType() << ", HP: " << character->getHitPoints() << "\n";
    }

    std::cout << "\nParty 2:\n";
    
    for(auto character : p2.getParty()){
        std::cout << "  Class: "<< character->getClassType() << ", HP: " << character->getHitPoints() << "\n";
    }
 }

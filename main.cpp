#include <iostream>
#include "party.h"
#include "characterFactory.h"
#include "ICharacter.h"
#include "Duel.h"



int main(){
    //initialize partys
   
    Party party1(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    party1.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Human));
    party1.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Cleric, characterFactory::GetCharacterFactory().Halfling));
    party1.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Rogue, characterFactory::GetCharacterFactory().Dwarf));

    
    Party party2(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    party2.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Dwarf));
    party2.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Rogue, characterFactory::GetCharacterFactory().Halfling));
    party2.addCharacter(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Cleric, characterFactory::GetCharacterFactory().Human));

    Duel duel;    
   
   

    int winner = 0;
    
    int round = 1;
    
    while(winner == 0){
        //reset every 8 turns (4 characters per team)
         //character with greater initiative goes first
        if(party1.getParty()[(round%(party1.getParty().size()))]->getInitiative() >= party2.getParty()[(round%(party2.getParty().size()))]->getInitiative()){
        //player 1 attacks and we check to see if party 2 is all dead
        duel.attack(party1.getParty()[(round%(party1.getParty().size()))], party1,party2);
        if(party2.getParty().size()==0){
            winner=1;
            duel.printStats(party1,party2);
            break;
        }   

        //player 2 attacks and we check to see if party 1 is all dead
        duel.attack(party2.getParty()[(round%(party2.getParty().size()))], party2, party1);
        
        if(party1.getParty().size()==0){
            winner=2;
            duel.printStats(party1,party2);
            break;
        }
        }
        else{
            //player 2 attacks and we check to see if party 1 is all dead
            duel.attack(party2.getParty()[(round%(party2.getParty().size()))], party2, party1);
        
            if(party1.getParty().size()==0){
                winner=2;
                duel.printStats(party1,party2);
                break;
            }
           //player 1 attacks and we check to see if party 2 is all dead
            duel.attack(party1.getParty()[(round%(party1.getParty().size()))], party1,party2);
            if(party2.getParty().size()==0){
            winner=1;
            duel.printStats(party1,party2);
            break;
        }   



        }

        //print the results after each round
        std::cout << "After round " << std::to_string(round) <<  ": \n\n";
        duel.printStats(party1,party2);

        
        //added this so you can see how the stats change over time rather than the whole game getting printed at once
        do {
        std::cout << '\n' << "Press enter to go to the next round";
        } 
        while (std::cin.get() != '\n');
        
        round++;
    }
    std::cout<< "Party " << std::to_string(winner) << " wins!\n";


    return 0;
}
#include <gtest/gtest.h>
#include "party.h"
#include "characterFactory.h"
#include "ICharacter.h"
#include "Duel.h"

TEST(PartyClass, initialize){
    Party myParty(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    //auto character = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf);
    //a fighter with and elf race mod should have a class type of 1(fighter), 16 armor, 5 hit bonus, 19 hp, and 17 initiative
    ASSERT_EQ(myParty.getCharacter(), myParty.getParty()[0]);
   
}
TEST(PartyClass, addToParty) {
    Party myParty(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    auto character2 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Human);
    myParty.addCharacter(character2);

    ASSERT_EQ(myParty.getParty().size(), 2);
}

//given that the characterFactory only has one purpose a second test case seems redundant
TEST(characterFactory, Create){
    std::shared_ptr<IClass> newChar = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf);
    
    //a fighter with and elf race mod should have a class type of 1(fighter), 16 armor, 5 hit bonus, 19 hp, and 17 initiative
    ASSERT_EQ(newChar->getClassType(), 1);
    ASSERT_EQ(newChar->getArmorClass(), 16);
    ASSERT_EQ(newChar->getHitBonus(), 5);
    ASSERT_EQ(newChar->getHitPoints(), 19);
    ASSERT_EQ(newChar->getInitiative(), 17);
}

TEST(Deuling, basic){

    //make sure that when a character is attacked they lose hp
    Party p1(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    Party p2(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Human));
    Duel duel;
    ASSERT_EQ(p2.getCharacter()->getHitPoints(), 14);
    duel.attack(p1.getCharacter(), p1,p2);
    ASSERT_TRUE(p2.getCharacter()->getHitPoints() < 14);
    
}
TEST(Deuling, defenderDies){

    //make sure that when a character is attacked they lose hp
    Party p1(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf));
    Party p2(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Human));
    Duel duel;
    ASSERT_EQ(p2.getCharacter()->getHitPoints(), 14);
    while(p2.getCharacter()->getHitPoints()>0){
        duel.attack(p1.getCharacter(), p1,p2);
    }
    ASSERT_TRUE(p2.getParty().size() == 0);
}
TEST(Deuling, wizardKillsSecondaryBeforePrimary){

    //make sure that when a wizard (that does splash dmg) kills the second in line before the the third in line becomes the second in line
    auto character1 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Fighter, characterFactory::GetCharacterFactory().Elf);
    auto character2 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Elf);
    auto character3 = characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Elf);
    Party p1(character1);
    p1.addCharacter(character2);
    p1.addCharacter(character3);

    Party p2(characterFactory::GetCharacterFactory().CreateCharacter(characterFactory::GetCharacterFactory().Wizard, characterFactory::GetCharacterFactory().Human));
    Duel duel;
    int psize = p1.getParty().size();
    //character 3 which is a wizard with less hp should die first and character 2 should take their spot
    //note the reason its character 3 being replaced is because of the way the addCharacter function works sorting by class 
    //so when 2 identical characters are placed in the newest one will be put first
    ASSERT_TRUE(p1.getParty()[1] == character3);
    
    while(p1.getParty().size() == psize){
        duel.attack(p2.getCharacter(), p2,p1);
    }

    ASSERT_TRUE(p1.getParty()[1] == character2);
    
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
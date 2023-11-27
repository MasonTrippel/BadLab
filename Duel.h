#include "party.h"
#include "characterFactory.h"
#include <algorithm>
#include <iostream>

class Duel{

    public:
    Duel();



    void attack(std::shared_ptr<IClass> attacker, Party &attackerParty, Party &defender);

    void checkHP(Party &defender);

    void printStats(Party p1, Party p2);
    private:

    
    int round;

};
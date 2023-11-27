

#pragma once

#include <vector>
#include <memory>


// Declaration for the class 

class IClass;

class Party
{
private:
   // Data field
   std::shared_ptr<IClass> m_flagClass;
   std::vector<std::shared_ptr<IClass>> m_party;
   
public:
   // Default constructor
    Party();
   
   // Parameterized constructor
    Party(const std::shared_ptr<IClass> character);
   
   // Mutator method that can change the value of the data field
   void setFlagClass(const std::shared_ptr<IClass> character);
   
   // Accessor method to get the value of the data field
   std::shared_ptr<IClass> getCharacter() const;

   void addCharacter(const std::shared_ptr<IClass> character);

   std::vector<std::shared_ptr<IClass>> getParty();

   void removeCharacter(std::shared_ptr<IClass> characterToRemove);

}; // end PlainBox
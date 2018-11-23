/*********************************************************************
** Program name: Character.hpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file is the Character class specification/interface.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"
#include <iostream>
#include "../constants/constants.hpp"
#include "../utilities/utilities.hpp"

class Character
{
    private:
        // declare member variables
        std::string type;
        std::string name;
        int armor;
        int strength;
        int startingStrength;
        int attackRoll;
        int defenseRoll;
        int damage;
        Die* recoveryDie;
    protected:
        Die* attackDie;
        Die* defenseDie;
    public:
        // declare constructors
        Character(std::string, std::string, int, int);
        // declare member functions, set/get
        void setAttackRoll(int);
        void setDefenseRoll(int);
        void setDamage(int);
        void updateStrength();
        void updateStrength(int);
        void recoverStrength();
        std::string getType() const;
        std::string getName() const;
        int getArmor() const;
        int getStrength() const;
        int getAttackRoll() const;
        int getDefenseRoll() const;
        int getDamage() const;
        virtual int attack();           // overwritten by derived classes
        virtual void defense(int) = 0;  // make pure virtual so Character base
                                        // base class is abstract
        virtual ~Character();
};

#endif

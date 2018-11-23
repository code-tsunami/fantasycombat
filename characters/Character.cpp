/*********************************************************************
** Program name: Character.cpp
** Author: Sonam D. Kindy
** Date: 10/28/17
** Description: This file contains the Character class implementation
** wherein each Character object has the data members of type (string),
** armor (int), strength (int), attackRoll (int), defenseRoll(int), and
** damage(int). The aforementioned data members starting with attackRoll
** are initialized to zero, whereas the previous are assigned the values
** of the passed parameters. It also has the member functions to set
** the relevant data members, update the strength according to damage, or
** re-initialize it as a set value, and gets their values.
*********************************************************************/

#include "Character.hpp"
#include <cmath>

/*********************************************************************
** Description: This constructor sets the given parameters of type (string),
** armor (int), and strength (int) to the data members type (string),
** armor (int), and strength (int). The attackRoll, defenseRoll and damage
** data members are set to 0.
*********************************************************************/
Character::Character(std::string name, std::string type, int armor, int strength)
{
    this->name = name;
    this->type = type;
    this->armor = armor;
    this->strength = strength;
    startingStrength = strength;
    recoveryDie = new Die(1, 10);
    attackRoll = defenseRoll = damage = 0;
}

/*********************************************************************
** Description: This member function sets the attackRoll (int) data member
** value to the given parameter of attackRoll (int).
*********************************************************************/
void Character::setAttackRoll(int attackRoll)
{
    this->attackRoll = attackRoll;
}

/*********************************************************************
** Description: This member function sets the defenseRoll (int) data member
** value to the given parameter of defenseRoll (int).
*********************************************************************/
void Character::setDefenseRoll(int defenseRoll)
{
    this->defenseRoll = defenseRoll;
}

/*********************************************************************
** Description: This member function sets the damage (int) data member
** value to the given parameter of damageTaken (int) if damageTaken's
** value is non-negative. Otherwise, if it is negative, the damage is
** set to 0.
*********************************************************************/
void Character::setDamage(int damageTaken)
{
    if (damageTaken < 0)
        damage = 0;
    else
        damage = damageTaken;
}

/*********************************************************************
** Description: This member function checks the value of damage (int)
** inflicted by the opponent and if the damage inflicted is greater
** than or equal to the strength of the (defending) character, then
** their strength is set to zero, i.e. the character dies. Else if
** the damage inflicted is greater than zero, then the strength is
** updated by subtracting the damage inflicted. If neither condition
** is met, then damage inflicted must be negative, which signifies that
** the (defending) character was able to ward off the attack, so do not
** update their strength.
*********************************************************************/
void Character::updateStrength()
{
    if (damage >= strength)
        strength = 0;
    else
        strength -= damage;
}

/*********************************************************************
** Description: This member function takes as a parameter newStrength (int)
** to which to assign the data member strength, i.e. update to a new strength
** value.
*********************************************************************/
void Character::updateStrength(int newStrength)
{
    strength = newStrength;
}

/*********************************************************************
** Description: This member function determines the percentage of strength
** to recover for the given character by the roll of 1 dice with 10 sides.
** It then multiplies the floating-point value representation of the percentage
** by the starting strength and rounds the resulting product and assigns the
** rounded product to the strength data member.
** Ref: http://www.cplusplus.com/reference/cmath/round/
*********************************************************************/
void Character::recoverStrength()
{
    int strengthToRecover = getStrength() + ceil(getStrength() *
                            (static_cast<double>(recoveryDie->rollDice()) / 10));
    
    if (strengthToRecover < startingStrength)
        updateStrength(strengthToRecover);
    else
        // this is a safehold to ensure that the strength recovered does not 
        // exceed the character's starting (max) strength
        updateStrength(startingStrength);
                   
}


/*********************************************************************
** Description: This member function returns the value of the attack roll.
*********************************************************************/
int Character::getAttackRoll() const
{
    return attackRoll;
}

/*********************************************************************
** Description: This member function returns the value of the defense roll.
*********************************************************************/
int Character::getDefenseRoll() const
{
    return defenseRoll;
}

/*********************************************************************
** Description: This member function returns the value of damage.
*********************************************************************/
int Character::getDamage() const
{
    return damage;
}

/*********************************************************************
** Description: This member function returns the type.
*********************************************************************/
std::string Character::getType() const
{
    return type;
}

/*********************************************************************
** Description: This member function returns the name.
*********************************************************************/
std::string Character::getName() const
{
    return name;
}

/*********************************************************************
** Description: This member function returns the strength.
*********************************************************************/
int Character::getStrength() const
{
    return strength;
}

/*********************************************************************
** Description: This member function returns the armor.
*********************************************************************/
int Character::getArmor() const
{
    return armor;
}

/*********************************************************************
** Description: This member function sets the attack roll value using
** the attackDie Die object and returns the value of the attack roll. 
*********************************************************************/
int Character::attack()
{
    setAttackRoll(attackDie->rollDice());
    return attackRoll;
}

/*********************************************************************
** Description: This destructor frees the memory allocated to the pointer
** to a dynamically created Die object data member recoveryDie. 
*********************************************************************/
Character::~Character()
{
    delete recoveryDie;
}

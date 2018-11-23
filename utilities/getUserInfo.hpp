/*********************************************************************
** Program name: getUserInfo.hpp
** Author: Sonam D. Kindy
** Date: 11/13/17
** Description: This file contains the startGame function prototype,
** which takes two int parameters, and createPlayer function prototype,
** which takes an int parameter and returns a pointer to a Character object.
*********************************************************************/

#ifndef GET_USER_INFO_HPP
#define GET_USER_INFO_HPP

#include "../game/Menu.hpp"
#include "../containers/Queue.hpp"
#include "../game/Game.hpp"
#include "../characters/Barbarian.hpp"
#include "../characters/BlueMen.hpp"
#include "../characters/Vampire.hpp"
#include "../characters/Medusa.hpp"
#include "../characters/HarryPotter.hpp"

void startGame(int, int);
Character* createPlayer(int);

#endif

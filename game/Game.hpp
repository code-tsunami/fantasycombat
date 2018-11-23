/*********************************************************************
** Program name: Game.hpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This file is the Game class specification/interface.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "../containers/Stack.hpp"
#include "../containers/Queue.hpp"
#include "../constants/constants.hpp"

class Game
{
    private:
        // declare member variables
        Queue * teamA;
        Queue * teamB;
        Stack * losers;
        int roundNum;
        int teamAWins;
        int teamBWins;
        // declare private member functions only accessible within class
        void battle(Character*, Character*);
        void printStats(Character*, Character*, bool) const;
        void printGameStats() const;
        void printLosers() const;
    public:
        // declare constructors
        Game(Queue* tA, Queue* tB);
        // declare member functions, set/get
        void play();
        ~Game();
};

#endif

/*********************************************************************
** Program name: Game.cpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This program is the Game class function implementation
** wherein each Game object has as data members: two pointers to Queue 
** objects that represent the two teams and an int that represents the 
** number of rounds in the game as well as a member functions to play the 
** game, present the stats for the round and whether the game should continue.
*********************************************************************/

#include "Game.hpp"
#include <string>

/*********************************************************************
** Description: This constructor initializes the data members Team A and
** Team B to the passed Queue* parameters, the number of wins of each
** team to zero, the round number to 1, and dynamically allocates memory 
** for a Stack class object, the pointer to which is called losers. 
*********************************************************************/
Game::Game(Queue* teamA, Queue* teamB) {
    this->teamA = teamA;
    this->teamB = teamB;
    losers = new Stack;
    teamAWins = 0;
    teamBWins = 0;
    roundNum = 1;
}

/*********************************************************************
** Description: This member function has the game/tournament continue 
** until one of the team's players all die.
*********************************************************************/
void Game::play()
{
    std::string teamAStr,
                teamBStr;

    // get first players to battle
    Character* characterPtrA = teamA->getFront();
    Character* characterPtrB = teamB->getFront();
    
    while(characterPtrA && characterPtrB) {
        printBorder();
        printHeader("TOURNAMENT ROUND " + std::to_string(roundNum));
        teamAStr = "Team A " + characterPtrA->getType() + SPACE + 
                                characterPtrA->getName();
        teamBStr = "Team B " + characterPtrB->getType() + SPACE + 
                                characterPtrB->getName();
        printHeader(teamAStr + " vs. " + teamBStr);

        battle(characterPtrA, characterPtrB);

        printBorder();

        // if Team A's member/player has strength remaining, i.e. won the battle 
        // else Team B's member/player has strength remaining, i.e. won the battle
        if (characterPtrA->getStrength()) {
            printHeader(teamAStr + " DEFEATED " + teamBStr);
            characterPtrA->recoverStrength(); // recover strength of winner
            teamA->removeFront();             // remove winner from front of queue
            teamA->addBack(characterPtrA);    // place winner at back of queue
            teamB->removeFront();             // remove loser from queue
            losers->push(characterPtrB);      // push loser to top of losers stack
            teamAWins++;
        } else {
            printHeader(teamBStr + " DEFEATED " + teamAStr);
            characterPtrB->recoverStrength(); // follow same process above
            teamB->removeFront();
            teamB->addBack(characterPtrB);
            teamA->removeFront();
            losers->push(characterPtrA);
            teamBWins++;
        }
        characterPtrA = teamA->getFront(); // get next player from Team A
        characterPtrB = teamB->getFront(); // "                 "  Team B

        roundNum++;
    }
    printGameStats(); // print end of tournament stats
    printLosers();    // ask user if they want to see losers; if yes, display losers
}

/*********************************************************************
** Description: This member function conducts a (one-on-one) battle until 
** one of the characters dies, i.e. their strength is equal equal to 0.
*********************************************************************/
void Game::battle(Character* player1, Character* player2)
{
    int battleRoundNum = 1;

    while( player1->getStrength() && player2->getStrength() ) {
        printBorder(DASH);
        printHeader("BATTLE ROUND " + std::to_string(battleRoundNum));
        printStats(player1, player2, false);
        player1->attack();
        player2->defense(player1->getAttackRoll()); 
        
        printStats(player1, player2, true);
        if(player2->getStrength()) {
            printStats(player2, player1, false);
            player2->attack();
            player1->defense(player2->getAttackRoll());
            printStats(player2, player1, true);
        }
        battleRoundNum++;
    }

}

/*********************************************************************
** Description: This member function prints the stats for the round
** given pointers to the current players (attacker and defender) and 
** boolean for whether the stats to be printed are after an attack (true) 
** or before (false). 
*********************************************************************/
void Game::printStats(Character* attacker, Character* defender, bool afterAttack) const
{
    if (!afterAttack) {
        printHeader(attacker->getType() + SPACE + attacker->getName() + 
                    " attacked " + defender->getType() + "!\n");
        printCol("ATTACKER TYPE");
        printCol("DEFENDER TYPE");
        printCol("DEFENDER ARMOR");
        printCol("DEFENDER STRENGTH");
        std::cout << std::endl;
        printCol(attacker->getType());
        printCol(defender->getType());
        printCol(defender->getArmor());
        printCol(defender->getStrength());
        std::cout << std::endl << std::endl;
    } else {

        printCol("ATTACKER ROLL");
        printCol("DEFENDER ROLL");
        printCol("ACTUAL DAMAGE");
        printCol("NEW STRENGTH");
        std::cout << std::endl;
        printCol(attacker->getAttackRoll());
        printCol(defender->getDefenseRoll());
        printCol(defender->getDamage());
        printCol(defender->getStrength());
        std::cout << std::endl << std::endl;
    }
}

/*********************************************************************
** Description: This member function prints the end of game stats.
*********************************************************************/
void Game::printGameStats() const
{
    printBorder();
    printHeader("TOURNAMENT COMPLETED");

    if(teamAWins > teamBWins) {
        printHeader(" Team A wins! ");
    } else if (teamBWins > teamAWins) {
        printHeader(" Team B wins! ");
    } else {
        printHeader(" Team A and Team B tied! ");
    }

    printHeader(" FINAL SCORES ", DASH);
    printCol("Team A", 35);
    printCol("Team B", 35);
    std::cout << std::endl;
    printCol(teamAWins, 35);
    printCol(teamBWins, 35);

    std::cout << std::endl;
    printBorder();
}

/*********************************************************************
** Description: This member function prompts the user for input on whether
** they want to see the losers of the tournament/game. If yes, the losers 
** are displayed displayed from top to bottom, i.e. team members/players 
** defeated in order of last to first.
*********************************************************************/
void Game::printLosers() const
{
    printHeader("Would you like to see the losers?");
    std::cout << "\t\t\tEnter your selection (0 - No; 1 - Yes): ";
    int option = getInt(1, 0);
    if (option) {
        printBorder();
        printHeader("LOSERS");
        losers->traverseList();
        printBorder();
    }
    std::cout << std::endl;
}

/*********************************************************************
** Description: This deconstructor frees memory allocated to losers. 
*********************************************************************/
Game::~Game() {
    delete losers;
}

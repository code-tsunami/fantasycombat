/*********************************************************************
** Program name: constants.hpp
** Author: Sonam D. Kindy
** Date: 9/30/17
** Description: This file specifies the global constants.
*********************************************************************/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <climits>

const int MAX_WIDTH = 90,
          KILL = INT_MAX,
          GLARE_ACTIVATED = 12,
          COL_LEN = 22;
const std::string INTRO = "Project 4: Fantasy Combat Tournament",
                  NOT_INT_MSG = "Invalid input. Enter an integer: ",
                  NOT_STRING_MSG = "Enter a string, not an empty line or space: ",
                  GENERIC_PROMPT = "\nPlease enter your selection: ",
                  EMPTY_LIST = "\nList is empty! Add some nodes!\n",
                  EMPTY_STR = "",
                  GOODBYE = " GOODBYE! ",
                  MENU = " MENU ";
const char SPACE = ' ',
           LINE = '|',
           STAR = '*',
           DASH = '-',
           WAVE = '~';

#endif

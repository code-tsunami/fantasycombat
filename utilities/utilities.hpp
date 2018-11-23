/*********************************************************************
** Program name: utilities.hpp
** Author: Sonam D. Kindy
** Date: 11/11/17
** Description: This file contains the function prototypes for input
** validation, including getting an integer in some range (specifying
** the range is optional) and getting an input string, which has a length
** within some range (specifying the length range is optional). It also
** includes the function prototypes for print functions that format output
** to the console, including header strings, borders of an optional character, 
** and strings with a optional width, the default values for which are defined
** in constants.hpp.
*********************************************************************/

#ifndef VALIDATE_INPUT_HPP
#define VALIDATE_INPUT_HPP

#include "../constants/constants.hpp"
#include <string>
#include <iomanip>

int getInt(const int max = 0, const int min = 0);
std::string getStr(const unsigned int maxLen = 0, const unsigned int minLen = 1);

void printHeader(std::string, const char ch = SPACE);
void printBorder(char ch = DASH);
void printCol(std::string, int width = COL_LEN);
void printCol(int, int width = COL_LEN);

#endif

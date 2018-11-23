/*********************************************************************
** Program name: validateInput.cpp
** Author: Sonam D. Kindy
** Date: 9/22/17
** Description: This set of functions serve as utility functions to 
** 1) validate user input and 2) print headers/borders to the console. 
** More utility functions to be added in the future.
*********************************************************************/

#include "utilities.hpp"
#include "../constants/constants.hpp"
#include <iostream>
#include <sstream>

/*********************************************************************
** Description: This function checks the user input and returns the user
** input cast as an integer only if the input is the intended data type of
** integer, i.e. is within the specified range (if given as parameters),
** is not an empty string/new line, and is not a floating-point value.
*********************************************************************/
int getInt(const int max, const int min)
{
    bool isInt = false;
    double num;
    std::string input;

    while(!isInt) {
        std::getline(std::cin,input);
        std::stringstream ss(input);

        if (input == EMPTY_STR) {
            std::cout << NOT_INT_MSG;
        }

        if (ss >> num && ss.eof()) {
            if ( (max || min) && (num > max || num < min) ) {
                std::cout << "Enter an integer between " << min
                          << " and " << max << ": ";
            } else if (num != static_cast<int>(num)) {
                std::cout << NOT_INT_MSG;
            } else {
                isInt = true;
            }
        }
        // input is not an empty string so there's been at least one user input
        else if (input.length() != 0) {
            if (max || min) {
                std::cout << "Enter an integer between " << min
                          << " and " << max << ": ";
            } else {
                std::cout << NOT_INT_MSG;
            }
        }
    }

    return static_cast<int>(num);
}

/*********************************************************************
** Description: This function checks the user input and returns the user
** input as a string if the input is at least one character long OR if
** the input string's length is within the specified range given as
** parameters. This function may be further adapted to account for
** allowing only alphabetical characters. As it is now, it accepts any
** characters as long as it is not an empty string.
*********************************************************************/
std::string getStr(const unsigned int maxLen, const unsigned int minLen)
{
    bool isCorrectLen = false;
    std::string input;

    while (!isCorrectLen) {
        std::getline(std::cin, input);
        if (input == EMPTY_STR || input == " ") {
            std::cout << NOT_STRING_MSG;
        } else if (maxLen && minLen &&
                   (input.length() > maxLen || input.length() < minLen)) {
            std::cout << "Enter a string with at least " << minLen << " character"
                      << " and no more than " << maxLen << " characters: ";
        } else {
            isCorrectLen = true;
        }
    }
    return input;
}

/*********************************************************************
** Description: This function takes as a parameter a header string to
** serve as the 'title' or way of sectioning off output and an optional
** parameter for the char to use for spacing. The default character used
** if the parameter is not given in the function call is a space. The
** headerStr is centered in the console between repeated characters
** of the character given (or defaulted to a space), based on the half
** of the length of the INTRO or title of the program multiplied by
** some arbitrary multiple (3 used in this case) divided by 2.
*********************************************************************/
void printHeader(std::string headerStr, char ch)
{
    const int LEN = (MAX_WIDTH - headerStr.length()) / 2;
    std::string repeatChars;

    repeatChars.assign(LEN, ch);

    headerStr = repeatChars + headerStr + repeatChars;

    std::cout << std::endl << headerStr << std::endl << std::endl;
}

/*********************************************************************
** Description: This function takes as a parameter a character to serve
** as the border or means of sectioning off output and its length is
** determined by the length of the INTRO or title of the program multiplied
** by some arbitrary multiple (3 used in this case).
*********************************************************************/
void printBorder(char ch)
{
    std::string charBorder;

    charBorder.assign(MAX_WIDTH, ch);
    std::cout << charBorder << std::endl;
}

/*********************************************************************
** Description: This function takes as a parameter a string to print 
** out with a given col width, which defaults to 15 if not given.
*********************************************************************/
void printCol(std::string headerStr, int width)
{
    std::cout << std::setw(width) << headerStr;
}

/*********************************************************************
** Description: This function takes as a parameter a string to print 
** out with the parameter of col width, the latter of which defaults to 
** the value specified in constants.hpp if not given.
*********************************************************************/
void printCol(int val, int width)
{
    std::cout << std::setw(width) << val;
}

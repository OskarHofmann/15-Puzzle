#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "Direction.h"
#include <iostream>
#include <set>

namespace UserInput {

    const std::set<char> allowedInputs{ 'w','s','a','d','q' };
    constexpr char exitInput = 'q';
    
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValidInput(char input) {
        return allowedInputs.find(input) != allowedInputs.end();
    }

    char getCharFromUser() {
        char input{};
        std::cin >> input;

        // if the user entered an invalid character
        if (!std::cin)
            std::cin.clear(); // reset any error flags
        // ignore any extra characters in the input buffer (regardless of whether we had an error or not)
        ignoreLine();

        return std::tolower(input, std::locale());
    }

    char getUserInput() {
        char input{};
        while (!isValidInput(input)) {
            input = getCharFromUser();
        }
        return input;
    }

    bool isQuitCommand(char input) {
        return input == exitInput;
    }

    Direction getDirectionFromChar(char dir) {
        switch (dir) {
        case 'w': return Direction::Type::up;
        case 'a': return Direction::Type::left;
        case 's': return Direction::Type::down;
        case 'd': return Direction::Type::right;
        default: throw std::logic_error("Invalid input for direction conversion");
        }
    }

}
#endif // !USER_INPUT_H


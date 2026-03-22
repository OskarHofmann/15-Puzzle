#include "Board.h"
#include "Direction.h"
#include <iostream>
#include <stdexcept>
#include <set>

namespace UserInput {

    std::set<char> allowedInputs{ 'w','s','a','d','q' };

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

    Direction getDirectionFromChar(char dir) {
        switch (dir) {
        case 'w': return Direction(Direction::up);
        case 'a': return Direction(Direction::left);
        case 's': return Direction(Direction::down);
        case 'd': return Direction(Direction::right);
        default: throw std::logic_error("Invalid input for direction conversion");
        }
    }

}

int main()
{
    Board<4> board;
    std::cout << board;

    for (int i = 0; i < 4; ++i) {
        std::cout << "Generation random direction..." << Direction::getRandomDirection() << '\n';
    }

    std::cout << "Enter a command: ";
    char input;
    while (true) {
        input = UserInput::getUserInput();
        if (input == 'q') {
            break;
        }
        Direction direction = UserInput::getDirectionFromChar(input);
        std::cout << "You entered a direction: " << direction <<'\n';


    }
    std::cout << "\n\nBye!\n";

    return 0;
}
#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Board<4> board;
    std::cout << board;

    for (int i = 0; i < 4; ++i) {
        std::cout << "Generation random direction..." << Direction::getRandomDirection() << '\n';
    }

    std::cout << board.getEmptyPosition() << '\n';

    std::cout << "Enter a command: ";
    char input;
    while (true) {
        input = UserInput::getUserInput();
        if (UserInput::isQuitCommand(input)) {
            break;
        }
        Direction direction = UserInput::getDirectionFromChar(input);
        std::cout << "You entered a direction: " << direction <<'\n';


    }
    std::cout << "\n\nBye!\n";

    return 0;
}
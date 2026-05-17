#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Board<4> board;
    std::cout << board;

    std::cout << "Enter a command: (w: up, a: left, s: down, d: right, q: quit)  ";
    char input;
    while (true) {
        input = UserInput::getUserInput();
        if (UserInput::isQuitCommand(input)) {
            break;
        }
        Direction direction = UserInput::getDirectionFromChar(input);
        if (board.moveTile(direction)) {
            std::cout << board;
        }
        else {
            std::cout << "Invalid move. Try again." << '\n';
        }

    }
    std::cout << "\n\nBye!\n";

    return 0;
}
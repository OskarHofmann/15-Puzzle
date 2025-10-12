#include "Board.h"
#include <iostream>
#include <set>

namespace UserInput {
    enum class Inputs {
        up,
        down,
        left,
        right,
        quit,
        UNKNOWN
    };

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

    Inputs getUserInput() {
        
        while (true) {
            char input{};
            while (!isValidInput(input)) {
                input = getCharFromUser();
            }
            
            std::cout << "Valid command: " << input << '\n';

            if (input == 'q') {
                return Inputs::quit;
            }
        }
    }

}

int main()
{
    Board<4> board;
    std::cout << board;

    UserInput::getUserInput();
    std::cout << "\n\nBye!\n";

    return 0;
}
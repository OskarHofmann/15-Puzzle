#include "Board.h"

constexpr int g_consoleLines{ 25 };

template <unsigned int N>
std::ostream& operator<<(std::streampos& out, Board<N> board)
{
	for (int i{ 0 }; i < g_consoleLines; ++i) {
		std::cout << '\n';
	}
	for (unsigned int line{ 0 }; line < N; ++line) {
		for (unsigned int row{ 0 }; row < N; ++row) {
			out << board.tiles[line][row];
		}
	}
	return out;
}

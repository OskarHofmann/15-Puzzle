#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Point.h"
#include <iostream>
#include <array>
#include <stdexcept>

constexpr int g_consoleLines{ 25 };

template <std::size_t N>
class Board
{
public:
	Board();

	Point getEmptyPosition() const;

	template <std::size_t M>
	friend std::ostream& operator<<(std::ostream& out, const Board<M>& board);

private:
	std::array<std::array<Tile, N>, N> tiles{};

};

template<std::size_t N>
Board<N>::Board()
{
	for (std::size_t line{ 0 }; line < N; ++line) {
		for (std::size_t row{ 0 }; row < N; ++row) {
			// the last tile is empty
			if (line == N - 1 && row == N - 1) {
				tiles[line][row] = Tile{ 0 };
				continue;
			}
			tiles[line][row] = Tile{ static_cast<int>((line*N) + row + 1)};
		}
	}
}

template<std::size_t N>
Point Board<N>::getEmptyPosition() const {

	for (std::size_t line{ 0 }; line < N; ++line) {
		for (std::size_t row{ 0 }; row < N; ++row) {
			if (tiles[line][row].isEmpty()) {
				return Point(static_cast<int>(row), static_cast<int>(line));
			}
		}
	}
	// there should always be an empty position
	throw std::logic_error("No empty position in board found.");
 }

template <std::size_t M>
std::ostream& operator<<(std::ostream& out, const Board<M>& board)
{
	for (int i{ 0 }; i < g_consoleLines; ++i) {
		std::cout << '\n';
	}
	for (std::size_t line{ 0 }; line < M; ++line) {
		for (std::size_t row{ 0 }; row < M; ++row) {
			out << board.tiles[line][row];
		}
		std::cout << '\n';
	}
	return out;
}

#endif
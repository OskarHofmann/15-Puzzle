#pragma once
#include "Tile.h"
#include <iostream>
#include <array>

constexpr int g_consoleLines{ 25 };

template <std::size_t N>
class Board
{
public:
	Board();

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

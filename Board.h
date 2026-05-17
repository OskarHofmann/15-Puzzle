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

	bool moveTile(const Direction& direction);

	template <std::size_t M>
	friend std::ostream& operator<<(std::ostream& out, const Board<M>& board);

private:
	std::array<std::array<Tile, N>, N> tiles{};

	Point getEmptyPoint() const;
	void swapTiles(const Point& p1, const Point& p2);
	Tile& getTile(const Point& point);
	bool isValidPoint(const Point& point) const;

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
Point Board<N>::getEmptyPoint() const 
{
	for (std::size_t line{ 0 }; line < N; ++line) {
		for (std::size_t row{ 0 }; row < N; ++row) {
			if (tiles[line][row].isEmpty()) {
				// x: row, y: line
				return Point(static_cast<int>(row), static_cast<int>(line));
			}
		}
	}
	// there should always be an empty position
	throw std::logic_error("No empty position in board found.");
 }

template <std::size_t N>
bool Board<N>::moveTile(const Direction& direction) {
	Point currentEmpty = getEmptyPoint();
	Point positionToMove = currentEmpty.getAdjacentPoint(-direction);
	if (!isValidPoint(positionToMove)) {
		return false;
	}
	swapTiles(currentEmpty, positionToMove);
	return true;
}

template <std::size_t N>
void Board<N>::swapTiles(const Point& p1, const Point& p2) {
	std::swap(getTile(p1), getTile(p2));
}

template <std::size_t N>
Tile& Board<N>::getTile(const Point& point) {
	// points use x,y which is swapped compared to row, column
	return tiles[static_cast<size_t>(point.getY())][static_cast<size_t>(point.getX())];
}

template <std::size_t N>
bool Board<N>::isValidPoint(const Point& point) const {
	return (
		(point.getX() >= 0) && (point.getX() < N) && 
		(point.getY() >= 0) && (point.getY() < N) 
	);
}

template <std::size_t N>
std::ostream& operator<<(std::ostream& out, const Board<N>& board)
{
	for (int i{ 0 }; i < g_consoleLines; ++i) {
		out << '\n';
	}
	for (std::size_t line{ 0 }; line < N; ++line) {
		for (std::size_t row{ 0 }; row < N; ++row) {
			out << board.tiles[line][row];
		}
		out << '\n';
	}
	return out;
}

#endif
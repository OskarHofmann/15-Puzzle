#include "Tile.h"
#include <string>

int Tile::getNum()
{
	return number;
}

bool Tile::isEmpty()
{
	return number == 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	std::string tile_print{ " " };
	if (tile.number <= 9) {
		tile_print += " ";
	}
	tile_print += std::to_string(tile.number);
	tile_print += " ";

	out << tile_print;
	return out;
}

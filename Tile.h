#pragma once
#include <utility>
#include <iostream>

class Tile
{
public:
	int getNum();
	bool isEmpty();

	Tile() = default;
	explicit Tile(int num) : number{ num } {};


	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);


private:
	int number{ 0 };
};


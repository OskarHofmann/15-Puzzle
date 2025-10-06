#pragma once
#include <utility>
#include <iostream>

class Tile
{
public:
	int getNum() const;
	bool isEmpty() const;

	Tile() = default;
	explicit Tile(int num) : number{ num } {};


	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);


private:
	int number{ 0 };
};


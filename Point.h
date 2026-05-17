#ifndef POINT_H
#define POINT_H

#include "Direction.h"
#include <iostream>

class Point {
public:
	Point() : Point(0, 0) {};
	Point(int x, int y) : m_x{ x }, m_y{ y } {};

	int getX() const{ return m_x; }
	int getY() const{ return m_y; }

	Point getAdjacentPoint(const Direction& direction);

	friend bool operator==(const Point& p1, const Point& p2) { return ((p1.m_x == p2.m_x) && (p1.m_y == p2.m_y)); }
	friend bool operator!=(const Point& p1, const Point& p2) { return !(p1 == p2); }
	friend std::ostream& operator<<(std::ostream& out, const Point& point);

private:
	int m_x;
	int m_y;
};


#endif


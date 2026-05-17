#include "Point.h"

Point Point::getAdjacentPoint(const Direction& direction)
{
    switch (direction.getType()) {
    case Direction::Type::up:
        return Point(m_x, m_y - 1);
    case Direction::Type::right:
        return Point(m_x + 1, m_y);
    case Direction::Type::down:
        return Point(m_x, m_y + 1);
    case Direction::Type::left:
        return Point(m_x - 1, m_y);
    default:
        throw std::logic_error("Direction types other than up, down, left or right should not be possible.");
    }
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << '(' << point.getX() << ',' << point.getY() << ")\n";
    return out;
}

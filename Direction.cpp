#include "Direction.h"
#include "Random.h"
#include <stdexcept>
#include <string_view>

constexpr std::string_view UP = "up";
constexpr std::string_view LEFT = "left";
constexpr std::string_view DOWN = "down";
constexpr std::string_view RIGHT = "right";

std::ostream& operator<<(std::ostream& out, const Direction& direction)
{
    switch (direction.m_type) {
    case Direction::Type::up:
        out << UP;
        break;
    case Direction::Type::right:
        out << RIGHT;
        break;
    case Direction::Type::down:
        out << DOWN;
        break;
    case Direction::Type::left:
        out << LEFT;
        break;
    }
    return out;
}

Direction::Direction(Type type) : m_type {type}
{
    if (type == Type::numberOfDirections)
        throw std::invalid_argument("Direction type must be up, down, left or right.");
}

Direction Direction::getRandomDirection()
{
    Type type{ static_cast<Type>(Random::get(0,static_cast<int>(Type::numberOfDirections) - 1)) };
    return Direction{ type };
}

Direction Direction::operator-() const
{
    switch (m_type) {
    case Type::up:
        return Direction{ Type::down };
    case Type::right:
        return Direction{ Type::left };
    case Type::down:
        return Direction{ Type::up };
    case Type::left:
        return Direction{ Type::right };
    default:
        throw std::logic_error("Direction types other than up, down, left or right should not be possible.");
    }
    
}

#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction
{
public:
    enum class Type {
        up,
        down,
        left,
        right,
        numberOfDirections
    };

    Direction() = delete;
    Direction(Type type);

    Type getType() const { return m_type; };

    static Direction getRandomDirection();

    Direction operator-() const;
    friend std::ostream& operator<<(std::ostream& out, const Direction& direction);

private:
    Type m_type;

};

#endif
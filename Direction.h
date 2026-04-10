#pragma once
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
    explicit Direction(Type type);

    Type getType() const { return m_type; };

    static Direction getRandomDirection();

    Direction operator-() const;
    friend std::ostream& operator<<(std::ostream& out, const Direction& direction);

private:
    Type m_type;

};


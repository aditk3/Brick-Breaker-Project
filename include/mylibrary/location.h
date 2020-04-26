// Brought from CS126 Snake repo

#ifndef FINALPROJECT_LOCATION_H
#define FINALPROJECT_LOCATION_H

#include <cstddef>
#include <iostream>

namespace brickbreaker {

// Represents a location on the board.
    class Location {
    public:
        int l;
        Location(int x, int y);

        // Comparison operators.
        bool operator()(const Location& lhs, const Location& rhs) const;
        bool operator==(const Location& rhs) const;
        bool operator!=(const Location& rhs) const;
        bool operator<(const Location& rhs) const;
        bool operator<=(const Location& rhs) const;
        bool operator>(const Location& rhs) const;
        bool operator>=(const Location& rhs) const;

        // Vector operators.
        Location operator+(const Location& rhs) const;
        // Note: Always returns positive coordinates.
        Location operator%(const Location& rhs) const;
        Location operator-(const Location& rhs) const;
        Location& operator+=(const Location& rhs);
        Location operator-() const;

        // Accessors.
        int X();
        int Y();

    private:
        int x_;
        int y_;
    };

//    std::ostream& operator<<(std::ostream& os, const Location& location);

}  // namespace snake
#endif //FINALPROJECT_LOCATION_H

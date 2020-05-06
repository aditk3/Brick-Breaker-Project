// Brought from CS126 Snake repo

#include "mylibrary/location.h"

namespace brickbreaker{

    Location::Location(int x, int y) : x_(x), y_(y) {}

    bool Location::operator==(const Location& rhs) const {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }

    bool Location::operator()(const Location& lhs, const Location& rhs) const {
        return lhs <= rhs;
    }

    bool Location::operator!=(const Location& rhs) const {
        return !(*this == rhs);
    }

    bool Location::operator<(const Location& rhs) const {
        return x_ < rhs.x_ || (rhs.x_ >= x_ && y_ < rhs.y_);
    }

    bool Location::operator<=(const Location& rhs) const {
        return !(rhs < *this);
    }

    bool Location::operator>(const Location& rhs) const {
        return rhs < *this;
    }

    bool Location::operator>=(const Location& rhs) const {
        return !(*this < rhs);
    }

    Location Location::operator+(const Location& rhs) const {
        return { x_ + rhs.x_, y_ + rhs.y_ };
    }

    Location Location::operator-(const Location& rhs) const {
      return *this + (-rhs);
    }

    Location Location::operator-() const { return {-x_, -y_}; }

    Location& Location::operator+=(const Location& rhs) {
      *this = *this + rhs;
      return *this;
    }

    Location& Location::operator-=(const Location& rhs) {
      *this = *this - rhs;
      return *this;
    }

    int mod(int a, int b) {
      int c = a % b;
      return c + (c < 0 ? b : 0);
    }

    Location Location::operator%(const Location& rhs) const {
      return {mod(x_, rhs.x_), mod(y_, rhs.y_)};
    }

    int Location::X() { return x_; }

    int Location::Y() { return y_; }

//    std::ostream& operator<<(std::ostream& os, const Location& location) {
//        os << "{row=" << location.X() << ", col=" << location.Y() << "}";
//        return os;
//    }

}  // namespace brickbreaker

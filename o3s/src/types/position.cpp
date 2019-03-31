#include "types/position.hpp"

namespace o3s {

Position::Position() : data{0.0, 0.0, 0.0} {}

Position::Position(double x, double y, double z) : data{x, y, z} {}

Position& Position::operator=(const Position& rhs) {
  if (this != &rhs) {
    data[0] = rhs.data[0];
    data[1] = rhs.data[1];
    data[2] = rhs.data[2];
  }
  return *this;
}

Position& Position::operator+=(const Position& rhs) {
  data[0] += rhs.data[0];
  data[1] += rhs.data[1];
  data[2] += rhs.data[2];
  return *this;
}

Position& Position::operator-=(const Position& rhs) {
  data[0] -= rhs.data[0];
  data[1] -= rhs.data[1];
  data[2] -= rhs.data[2];
  return *this;
}

const Position Position::operator+(const Position& other) const {
  Position result = *this;
  result += other;
  return result;
}

const Position Position::operator-(const Position& other) const {
  Position result = *this;
  result -= other;
  return result;
}

Position Position::inverse() const {
  return Position(-data[0], -data[1], -data[2]);
}

}  // namespace o3s

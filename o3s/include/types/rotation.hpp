#ifndef _O3S_TYPES_ROTATION_HPP_
#define _O3S_TYPES_ROTATION_HPP_

#include "types/position.hpp"

namespace o3s {
class Rotation {
 public:
  Rotation();
  Rotation(double x, double y, double z, double w);

  // Operators
  Rotation& operator=(const Rotation& rhs);

  Rotation& operator*=(const Rotation& rhs);
  const Rotation operator*(const Rotation& other) const;

  Position operator*(const Position& rhs) const;

  // Getter
  inline double x() const { return data[0]; }
  inline double y() const { return data[1]; }
  inline double z() const { return data[2]; }
  inline double w() const { return data[3]; }

  // Interfaces
  Rotation inverse() const;

 private:
  // Used only for multiplication with Position
  Rotation(const Position& p);
  void normalize();
  double magnitude();

 private:
  double data[4];
};
}  // namespace o3s

#endif

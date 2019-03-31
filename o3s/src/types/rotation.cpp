#include "types/rotation.hpp"

#include <math.h>

namespace o3s {

Rotation::Rotation() : data{0.0, 0.0, 0.0, 1.0} {}

Rotation::Rotation(double x, double y, double z, double w) : data{x, y, z, w} {
  normalize();
}

Rotation& Rotation::operator=(const Rotation& rhs) {
  if (this != &rhs) {
    data[0] = rhs.data[0];
    data[1] = rhs.data[1];
    data[2] = rhs.data[2];
    data[3] = rhs.data[3];
  }
  return *this;
}

Rotation& Rotation::operator*=(const Rotation& rhs) {
  double x = data[0] * rhs.data[3] + data[1] * rhs.data[2] -
             data[2] * rhs.data[1] + data[3] * rhs.data[0];
  double y = -data[0] * rhs.data[2] + data[1] * rhs.data[3] +
             data[2] * rhs.data[0] + data[3] * rhs.data[1];
  double z = data[0] * rhs.data[1] - data[1] * rhs.data[0] +
             data[2] * rhs.data[3] + data[3] * rhs.data[2];
  double w = -data[0] * rhs.data[0] - data[1] * rhs.data[1] -
             data[2] * rhs.data[2] + data[3] * rhs.data[3];

  data[0] = x;
  data[1] = y;
  data[2] = z;
  data[3] = w;
  return *this;
}

const Rotation Rotation::operator*(const Rotation& other) const {
  Rotation result = *this;
  result *= other;
  return result;
}

Position Rotation::operator*(const Position& rhs) const {
  // TODO: Need to check it is optimal way to rotate point
  Rotation p_aug(rhs);
  Rotation q_inverse = (*this).inverse();

  Rotation result = (*this) * p_aug * q_inverse;

  return Position(result.data[0], result.data[1], result.data[2]);
}

Rotation Rotation::inverse() const {
  // Inverse of a quaternion is same as conjugate of the quaternion, if only it
  // is unit quaternion. It must be guaranteed that the magnitude of the
  // Rotation class is always 1. Therefore, all public interfaces must assure
  // that the provided quaternion is unit quaternion.
  return Rotation(-data[0], -data[1], -data[2], -data[3]);
}

void Rotation::normalize() {
  double len = magnitude();
  if (len > 0.0) {
    double len_inverse = 1.0 / len;
    data[0] *= len_inverse;
    data[1] *= len_inverse;
    data[2] *= len_inverse;
    data[3] *= len_inverse;
  }
}

double Rotation::magnitude() {
  return sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2] +
              data[3] * data[3]);
}

}  // namespace o3s

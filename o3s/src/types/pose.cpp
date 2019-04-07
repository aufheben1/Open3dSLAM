#include "types/pose.hpp"

namespace o3s {

Pose::Pose() : pos(), rot() {}

Pose::Pose(const Position& p, const Rotation& r) : pos(p), rot(r) {}

Pose::Pose(const Rotation& r, const Position& p) : pos(p), rot(r) {}

Pose& Pose::operator=(const Pose& rhs) {
  if (this != &rhs) {
    pos = rhs.pos;
    rot = rhs.rot;
  }
  return *this;
}

Pose& Pose::operator*=(const Pose& rhs) {
  (*this).pos =
      rhs.rot * (*this).pos;  // TODO: Implement *= operator in Position
  (*this).pos += rhs.pos;
  (*this).rot *= rhs.rot;
  return *this;
}

const Pose Pose::operator*(const Pose& other) {
  Pose result = *this;
  result *= other;
  return result;
}

Pose Pose::inverse() const {
  Rotation tmp_rot = rot.inverse();
  Position tmp_pos = tmp_rot * pos.inverse();
  return Pose(tmp_pos, tmp_rot);
}

}  // namespace o3s

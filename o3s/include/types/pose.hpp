#ifndef _O3S_TYPES_POSE_HPP_
#define _O3S_TYPES_POSE_HPP_

#include "types/position.hpp"
#include "types/rotation.hpp"

namespace o3s {
class Pose {
 public:
  Pose();
  Pose(const Position& p, const Rotation& r);
  Pose(const Rotation& r, const Position& p);

  // Operators
  Pose& operator=(const Pose& rhs);
  Pose& operator*=(const Pose& rhs);
  const Pose operator*(const Pose& other);

  // Getter
  Position p() const { return pos; }
  Rotation r() const { return rot; }

  // Interfaces
  Pose inverse() const;

 private:
  Position pos;
  Rotation rot;
};
}  // namespace o3s

#endif

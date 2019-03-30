#ifndef _O3S_TYPES_POSITION_HPP_
#define _O3S_TYPES_POSITION_HPP_

namespace o3s {
class Position {
 public:
  Position();
  Position(double x, double y, double z);

  // Operators
  Position& operator=(const Position& rhs);

  Position& operator+=(const Position& rhs);
  Position& operator-=(const Position& rhs);
  const Position operator+(const Position& other) const;
  const Position operator-(const Position& other) const;

  // Getter
  inline double x() const { return data[0]; }
  inline double y() const { return data[1]; }
  inline double z() const { return data[2]; }

  // Interfaces
  Position inverse() const;

 private:
  double data[3];
};
}  // namespace o3s

#endif
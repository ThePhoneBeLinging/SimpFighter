//
// Created by eal on 08/08-2025.
//

#include "Vector.hpp"
#include <cmath>

Vector Vector::operator*(const double scalar) const
{
  auto vector2D = Vector();
  vector2D.x_ = x_ * scalar;
  vector2D.y_ = y_ * scalar;
  return vector2D;
}

void Vector::operator*=(const double scalar)
{
  x_ *= scalar;
  y_ *= scalar;
}

void Vector::normalizeDirection()
{
  double length = std::sqrt(x_ * x_ + y_ * y_);

  if (length == 0)
  {
    return;
  }

  double divisor = 1.0 / length;
  x_ *= divisor;
  y_ *= divisor;
}

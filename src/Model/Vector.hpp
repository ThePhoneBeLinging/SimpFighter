//
// Created by eal on 08/08-2025.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP


class Vector
{
public:
  Vector() = default;
  double x_;
  double y_;

  Vector operator*(double scalar) const;
  void operator*=(double scalar);

  void normalizeDirection();
};


#endif //VECTOR_HPP

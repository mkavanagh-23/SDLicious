#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point2d {
  public:
    int x{ 0 };
    int y{ 0 };

    Point2d(int xPos, int yPos)
      : x{ xPos }, y{ yPos }
      {}

    friend std::ostream& operator<<(std::ostream& out, const Point2d& point) {
      out << "Point2d(" << point.x << ',' << point.y << ')';
      return out;
    }
};

//struct Point3d : public Point2d {
//  public:
//    int z{ 0 };
//};

#endif
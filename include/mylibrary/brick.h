//
// Created by Adit Kapoor on 29-04-2020.
//

#ifndef FINALPROJECT_BRICK_H
#define FINALPROJECT_BRICK_H

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/direction.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {

class Brick {
 public:
  Brick(int width, int height, Location location, int value, Color color);
  void DrawBrick();
  int Value() { return point_val_; }
  Location GetLocation() { return location_; }
  int Width() { return width_; }
  int Height() { return height_; }

 private:
  Location location_;
  Color color_;
  int width_, height_, point_val_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_BRICK_H

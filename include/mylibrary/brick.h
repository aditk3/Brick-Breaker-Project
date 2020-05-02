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

  /**
   * Constructor for a Brick object
   * @param width int
   * @param height int
   * @param location Location
   * @param value int
   * @param color ci::Color
   */
  Brick(int width, int height, Location location, int value, Color color);

  /**
   * Draws a rectangle at the Brick's location with the specified height, width,
   * and color
   */
  void DrawBrick();

  /**
   * Returns the point_val_ of the Brick
   * @return int
   */
  int Value() { return point_val_; }

  /**
   * Returns the location_ of the Brick
   * @return Location
   */
  Location GetLocation() { return location_; }

  /**
   * Returns the width_ of the Brick
   * @return int
   */
  int Width() { return width_; }

  /**
   * Returns the height_ of the Brick
   * @return int
   */
  int Height() { return height_; }

 private:

  Location location_;

  Color color_;

  int width_, height_, point_val_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_BRICK_H

//
// Created by Adit Kapoor on 4/26/20.
//

#ifndef FINALPROJECT_PADDLE_H
#define FINALPROJECT_PADDLE_H

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/direction.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {
class Paddle {
 public:
  /**
   * Constructor for Paddle objects
   */
  Paddle();

  /**
   * Returns the width_ of the Paddle
   * @return int
   */
  int Width() { return width_; }

  /**
   * Used to move the Paddle
   * @param dir Direction
   */
  void MovePaddle(Direction dir);

  /**
   * Draws a rectangle with a texture at the paddle's location
   */
  void DrawPaddle();

  /**
   * Returns the Paddle's location_
   * @return Location
   */
  Location GetLocation() { return location_; }

  /**
   * Return's the Paddle's speed_
   * @return size_t
   */
  size_t GetSpeed() { return speed_; }

  /**
   * Sets the Paddle's speed_
   * @param speed size_t
   */
  void SetSpeed(size_t speed) { speed_ = speed; }

 private:
  size_t speed_{15};

  int width_{100}, height_{15};

  cinder::gl::Texture2dRef paddle_texture_;

  Location location_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_PADDLE_H

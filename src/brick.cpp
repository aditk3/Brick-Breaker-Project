//
// Created by Adit Kapoor on 29-04-2020.
//

#include "mylibrary/brick.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {
Brick::Brick(int width, int height, Location location, int value, Color color)
    : width_{width - 1},
      height_{height - 1},
      point_val_{value},
      color_{color},
      location_(location.X(), location.Y()) {}

void Brick::DrawBrick() {
  gl::color(Color(1, 1, 1));
  gl::pushMatrices();
  gl::translate(location_.X(), location_.Y());
  gl::drawSolidRect(Rectf(0, 0, width_, height_));
  gl::popMatrices();
}
}  // namespace brickbreaker
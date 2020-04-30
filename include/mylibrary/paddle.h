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
  size_t speed_{15};
  int width_{100}, height_{15};
  //        Color color_ = Color::white();
  Color color_ = Color(128, 0, 128);
  cinder::gl::Texture2dRef paddle_texture_;
  Location location_;

 public:
  Paddle();

  int Width() { return width_; }

  void MovePaddle(Direction dir);

  void DrawPaddle();

  Location GetLocation() { return location_; }
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_PADDLE_H

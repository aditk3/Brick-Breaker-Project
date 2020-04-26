//
// Created by Adit Kapoor on 4/26/20.
//

#ifndef FINALPROJECT_PADDLE_H
#define FINALPROJECT_PADDLE_H

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {
class Paddle {
  int width_{100}, height_{15};
  Color color_ = Color::white();
  Location location_;

 public:
    Paddle();
  int Width();
  void DrawPaddle();
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_PADDLE_H

//
// Created by Adit Kapoor on 26-04-2020.
//

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {

class Ball {
 public:
  Ball();
  void DrawBall();
  void MoveBall();
  void ReverseX();
  void ReverseY();
  size_t GetRadius() { return radius_; }
  Location GetLocation() { return location_; }
  Location GetVelocity() { return velocity_; }
  void ResetVelocity(int vel = -1);
  void SetVelocity(Location velocity) { velocity_ = velocity; }
  void SetLocation(Location location) { location_ = location; }

 private:
  size_t radius_{10}, speed_{10};
  Color color_ = Color::white();
  Location location_, velocity_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_BALL_H

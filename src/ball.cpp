//
// Created by Adit Kapoor on 26-04-2020.
//

#include "mylibrary/ball.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include "mylibrary/location.h"

using namespace ci;

namespace brickbreaker {
Ball::Ball() : location_(400, 555), velocity_(speed_, -(speed_ - 2)) {}

void Ball::MoveBall() { location_ = location_ + velocity_; }

void Ball::DrawBall() {
  gl::color(color_);
  gl::drawSolidCircle(vec2(location_.X(), location_.Y()), radius_);
}

void Ball::ReverseX() { velocity_ = Location(-(velocity_.X()), velocity_.Y()); }

void Ball::ReverseY() { velocity_ = Location(velocity_.X(), -(velocity_.Y())); }

void Ball::ResetVelocity(int vel) {
  if (vel == -1)
    velocity_ = Location(speed_, -(speed_ - 2));
  else
    velocity_ = Location(vel, -(vel - 2));
}

void Ball::ZoneBasedRebounding(int zone) {
  switch (zone) {
    case 1: {
      velocity_ = Location(-(speed_ + 1), -(speed_ - 3));
      break;
    }
    case 2: {
      velocity_ = Location(-speed_, -(speed_ - 2));
      break;
    }
    case 3: {
      velocity_ = Location(-speed_, -(speed_ - 1));
      break;
    }
    case 4: {
      velocity_ = Location(speed_, -(speed_ - 1));
      break;
    }
    case 5: {
      velocity_ = Location(speed_, -(speed_ - 2));
      break;
    }
    case 6: {
      velocity_ = Location((speed_ + 1), -(speed_ - 3));
      break;
    }
    default: {
      break;
    }
  }
}
}  // namespace brickbreaker
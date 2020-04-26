//
// Created by Adit Kapoor on 26-04-2020.
//

#include "mylibrary/ball.h"
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

using namespace ci;

namespace brickbreaker{
    Ball::Ball() : location_(400, 555), velocity_(speed_, -speed_) {};

    void Ball::MoveBall() { location_ = location_ + velocity_; }

    void Ball::DrawBall() {
        gl::color(color_);
        gl::drawSolidCircle(vec2(location_.X(), location_.Y()), radius_);
    }
}
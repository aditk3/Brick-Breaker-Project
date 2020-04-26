//
// Created by Adit Kapoor on 4/26/20.
//

#include <mylibrary/paddle.h>

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;
namespace brickbreaker {
    int Paddle::Width() { return width_; }

    Paddle::Paddle() : location_((800 / 2) - (width_ / 2), 600 - 35) {}

    void Paddle::DrawPaddle() {
        gl::color(Color::white());
        gl::pushMatrices();
        gl::translate(location_.X(), location_.Y());
        gl::drawSolidRect(Rectf(0, 0, width_, height_));
        gl::popMatrices();
    }

}  // namespace brickbreaker
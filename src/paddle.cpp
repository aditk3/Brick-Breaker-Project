//
// Created by Adit Kapoor on 4/26/20.
//

#include <mylibrary/paddle.h>

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>
#include <mylibrary/direction.h>

using namespace ci;
using namespace ci::app;
namespace brickbreaker {
    int Paddle::Width() { return width_; }

    Paddle::Paddle() : location_((800 / 2) - (width_ / 2), 600 - 35) {}

    void Paddle::DrawPaddle() {
        gl::color(color_);
        gl::pushMatrices();
        gl::translate(location_.X(), location_.Y());
        gl::drawSolidRect(Rectf(0, 0, width_, height_));
        gl::popMatrices();
    }

    void Paddle::MovePaddle(Direction dir) {
        switch (dir) {
            case Direction::kRight: {
                this->location_ = location_ + Location(speed_, 0);
                break;
            }
            case Direction::kLeft: {
                this->location_ = location_ + Location(-1 * speed_, 0);
                break;
            }
            default:
                break;
        }
    }

}  // namespace brickbreaker
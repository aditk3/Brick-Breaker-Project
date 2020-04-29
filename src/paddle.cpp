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

    Paddle::Paddle() : location_((800 / 2) - (width_ / 2), 600 - 35) {
        ci::gl::enableDepthRead();
        auto img = loadImage(loadAsset("paddle_short.png"));
        paddle_texture_ = gl::Texture2d::create(img);
    }

    void Paddle::DrawPaddle() {
        gl::color(Color(1, 1, 1));
        gl::pushMatrices();
        gl::translate(location_.X(), location_.Y());
        gl::draw(paddle_texture_, Rectf(0, 0, width_, height_));
        gl::popMatrices();
    }

    void Paddle::MovePaddle(Direction dir) {
        switch (dir) {
            case Direction::kRight: {
                if (this->location_.X() + width_ <= 800)
                    this->location_ = location_ + Location(speed_, 0);
                break;
            }
            case Direction::kLeft: {
                if (this->location_.X() >= 0)
                    this->location_ = location_ + Location(-1 * speed_, 0);
                break;
            }
            default:
                break;
        }
    }

}  // namespace brickbreaker
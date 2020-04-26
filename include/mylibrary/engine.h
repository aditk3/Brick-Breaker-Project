// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/paddle.h>
#include <mylibrary/player.h>
#include <mylibrary/ball.h>
#include <mylibrary/direction.h>

namespace brickbreaker {
    class Engine {
    public:
        Engine();
        void MovePaddle(Direction dir) {paddle_.MovePaddle(dir);}
        void DrawPaddle() { paddle_.DrawPaddle(); }
        void DrawBall() { ball_.DrawBall(); }
        Location getPaddleLocation() { return paddle_.GetLocation(); }
        size_t Score() { return score_; }
        size_t Lives() { return lives_; }

    private:
        Paddle paddle_;
        Ball ball_;
        size_t width_{600}, height_{600}, score_{}, lives_{3};
//        vec2 left_, right_;
    };
}  // namespace brickbreaker

#endif  // FINALPROJECT_MYLIBRARY_EXAMPLE_H_

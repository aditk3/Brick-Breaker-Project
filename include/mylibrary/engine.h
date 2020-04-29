// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/paddle.h>
#include <mylibrary/player.h>
#include <mylibrary/ball.h>
#include <mylibrary/brick.h>
#include <mylibrary/direction.h>

namespace brickbreaker {
    class Engine {
    public:
        Engine();
        void MovePaddle(Direction dir) { paddle_.MovePaddle(dir); }
        void DrawPaddle() { paddle_.DrawPaddle(); }
        void DrawBrick() { brick_.DrawBrick(); }
        void DrawBall() { ball_.DrawBall(); }
        void MoveBall() { ball_.MoveBall(); }
        void SetGameState(bool state) { has_started_ = state; }
        bool IsInGame() { return has_started_; }
        void EdgeChecks();
        void Bounces();
        void PaddleHitCheck();
        Location GetPaddleLocation() { return paddle_.GetLocation(); }
        size_t Score() { return score_; }
        size_t Lives() { return lives_; }

    private:
        bool has_started_{false};
        Paddle paddle_; // "static class variables in c++"
        Ball ball_;
        Brick brick_;
        size_t width_{800}, height_{600}, score_{}, lives_{3};
    };
}  // namespace brickbreaker

#endif  // FINALPROJECT_MYLIBRARY_EXAMPLE_H_

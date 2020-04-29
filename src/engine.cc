// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/engine.h>

#include <iostream>
#include <mylibrary/location.h>
#include <mylibrary/brick.h>

namespace brickbreaker {
    Engine::Engine() {}

    void Engine::EdgeChecks() {
        // Horizontal Edges
        if((ball_.GetLocation().X() + ball_.GetRadius() >= width_)
            || ball_.GetLocation().X() - ball_.GetRadius() <= 0) {
            ball_.ReverseX();
        }

        // Top Edge
        if(ball_.GetLocation().Y() - ball_.GetRadius() <= 5) {
            ball_.ReverseY();
        }
    }

    void Engine::PaddleHitCheck() {
        // CChecks if the ball is in line with the paddle (horizontally)
        if ((ball_.GetLocation().X() + ball_.GetRadius() >= paddle_.GetLocation().X())
            && (ball_.GetLocation().X() - ball_.GetRadius() <= paddle_.GetLocation().X() + paddle_.Width())) {
            // Checks if the ball is in line with the paddle (vertically)
            if (ball_.GetLocation().Y() + ball_.GetRadius() > paddle_.GetLocation().Y()) {
                ball_.SetLocation(Location(ball_.GetLocation().X(), paddle_.GetLocation().Y() -
                    ball_.GetRadius()));
                ball_.ReverseY();
            }
        }
    }

    void Engine::Bounces() {
        PaddleHitCheck();
        EdgeChecks();
    }

    void Engine::DrawEngineElements() {
        paddle_.DrawPaddle();
        ball_.DrawBall();
        for (auto brick : bricks_) {
            brick.DrawBrick();
        }
    }

    void Engine::CreateBricks() {
        brick_width_ = width_/bricks_per_row_;
        for(size_t i{0}; i < bricks_per_row_; i++) {
            bricks_.emplace_back(brick_width_, brick_height_, Location(i * brick_width_, 120));
        }
    }

    void Engine::BrickCollisions() {
//        using namespace std;
//        for (auto it = bricks_.begin(); it != bricks_.end();) {
//            if (BottomBrickCollision(*it)) {
//                bricks_.erase(it);
//                ball_.ReverseY();
//            }
//        }
        for (Brick brick : bricks_) {
            if (BottomBrickCollision(brick))
                ball_.ReverseY();
        }
    }

    bool Engine::BottomBrickCollision(Brick &brick_location) {
        return ball_.GetLocation().Y() - ball_.GetRadius() <= brick_location.GetLocation().Y() + brick_height_
               && ball_.GetLocation().Y() + ball_.GetRadius() >= brick_location.GetLocation().Y()
               && ball_.GetLocation().X() + ball_.GetRadius() >= brick_location.GetLocation().X()
               && ball_.GetLocation().X() - ball_.GetRadius() <= brick_location.GetLocation().X() + brick_width_;
    }

// Member initializer lists

}  // namespace brickbreaker

// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/engine.h>

#include <iostream>
#include <mylibrary/location.h>

namespace brickbreaker {
    Engine::Engine() : brick_(80, Location(140, 150)) {}

    void Engine::EdgeChecks() {
        // Horizontal Edges
        if((ball_.GetLocation().X() + ball_.GetRadius() >= width_)
            || ball_.GetLocation().X() - ball_.GetRadius() <= 0) {
            ball_.SetVelocity(Location(-(ball_.GetVelocity().X()), ball_.GetVelocity().Y()));
        }

        // Top Edge
        if(ball_.GetLocation().Y() - ball_.GetRadius() <= 5) {
            ball_.SetVelocity(Location(ball_.GetVelocity().X(), -(ball_.GetVelocity().Y())));
        }
    }

    void Engine::PaddleHitCheck() {
        // CChecks if the ball is in line with the paddle (horizontally)
        if ((ball_.GetLocation().X() + ball_.GetRadius() >= paddle_.GetLocation().X())
            && (ball_.GetLocation().X() - ball_.GetRadius() <= paddle_.GetLocation().X() + paddle_.Width())) {
            // Checks if the ball is in line with the paddle (vertically)
            if (ball_.GetLocation().Y() + ball_.GetRadius() > paddle_.GetLocation().Y()) {
                ball_.SetLocation(Location(ball_.GetLocation().X(), paddle_.GetLocation().Y() - ball_.GetRadius()));
                ball_.SetVelocity(Location(ball_.GetVelocity().X(), -(ball_.GetVelocity().Y())));
            }

        }
    }

    void Engine::Bounces() {
        PaddleHitCheck();
        EdgeChecks();
    }
// Member initializer lists

}  // namespace brickbreaker

// Copyright (c) 2020 Adit Kapoor. All rights reserved.

#include <cinder/gl/gl.h>
#include <mylibrary/brick.h>
#include <mylibrary/engine.h>
#include <mylibrary/location.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace brickbreaker {
Engine::Engine() {}

void Engine::EdgeChecks() {
  // Horizontal Edges
  if ((ball_.GetLocation().X() + ball_.GetRadius() >= width_) ||
      ball_.GetLocation().X() - ball_.GetRadius() <= 0) {
    ball_.ReverseX();
  }

  // Top Edge
  if (ball_.GetLocation().Y() - ball_.GetRadius() <= 5) {
    ball_.ReverseY();
  }
}

void Engine::PaddleHitCheck() {
  // Checks if the ball is in line with the paddle (horizontally)
  if ((ball_.GetLocation().X() + ball_.GetRadius() >=
       paddle_.GetLocation().X()) &&
      (ball_.GetLocation().X() - ball_.GetRadius() <=
       paddle_.GetLocation().X() + paddle_.GetWidth())) {
    // Checks if the ball is in line with the paddle (vertically)
    if (ball_.GetLocation().Y() + ball_.GetRadius() >
        paddle_.GetLocation().Y()) {
      ball_.SetLocation(
          Location(ball_.GetLocation().X(),
                   paddle_.GetLocation().Y() - ball_.GetRadius()));
      // Used to determine the zone in which the ball landed
      int zone{6}, num_zones{6}, ball_x{ball_.GetLocation().X()},
          paddle_width{paddle_.GetWidth()}, paddle_x{paddle_.GetLocation().X()},
          zone_width;
      zone_width = paddle_width / num_zones;

      for (int i{num_zones - 1}; i > 0; i--) {
        if (ball_x < paddle_x + (zone_width * i)) {
          zone = i;
        } else {
          break;
        }
      }

      ball_.ZoneBasedRebounding(zone);
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
  bricks_.clear();
  ci::Color colors[3]{
      Color(0, 255, 255),
      Color(255, 128, 0),
      Color(255, 0, 255),
  };

  std::srand(std::time(NULL));
  brick_width_ = width_ / bricks_per_row_;
  for (size_t i{0}; i < rows_of_bricks_; i++) {
    for (size_t j{0}; j < bricks_per_row_; j++) {
      int value = rand() % 3;
      bricks_.emplace_back(
          brick_width_, brick_height_,
          Location(j * brick_width_, 50 + (25 + brick_height_) * i), value + 1,
          colors[value]);
    }
  }
}

void Engine::BrickCollisions() {
  if (bricks_.empty()) {
    return;
  }
  using namespace std;
  for (auto it = bricks_.begin(); it != bricks_.end();) {
    if (BoxBoundsAlgorithm(*it)) {
      score_ += it->Value();
      // Checks whether the ball hit the horizontal or vertical edges of the
      // brick and reflects the ball across the respective axis
      if (ball_.GetLocation().X() < it->GetLocation().X() ||
          ball_.GetLocation().X() > (it->GetLocation().X() + it->Width())) {
        ball_.ReverseX();
      } else {
        ball_.ReverseY();
      }

      bricks_.erase(it);
    } else {
      ++it;
    }
  }
}

bool Engine::BoxBoundsAlgorithm(Brick &brick) {
  return ball_.GetLocation().Y() - ball_.GetRadius() <=
             brick.GetLocation().Y() + brick_height_ &&
         ball_.GetLocation().Y() + ball_.GetRadius() >=
             brick.GetLocation().Y() &&
         ball_.GetLocation().X() + ball_.GetRadius() >=
             brick.GetLocation().X() &&
         ball_.GetLocation().X() - ball_.GetRadius() <=
             brick.GetLocation().X() + brick_width_;
}

bool Engine::LifeOver() {
  if (ball_.GetLocation().Y() + ball_.GetRadius() >
      paddle_.GetLocation().Y() + 10) {
    lives_--;
    return true;
  }

  return false;
}

bool Engine::GameOver() { return lives_ == 0; }

void Engine::Reset() {
  ball_.SetLocation(Location(400, 555));
  ball_.ResetVelocity(ball_speed_);
}

void Engine::NextRound() {
  //  ball_speed_++;
  paddle_.SetSpeed(paddle_.GetSpeed() - 1);
  Reset();
  rows_of_bricks_++;
  bricks_per_row_ += 2;
  round_++;
  CreateBricks();
}

bool Engine::IsRoundOver() { return (bricks_.empty()); }

}  // namespace brickbreaker

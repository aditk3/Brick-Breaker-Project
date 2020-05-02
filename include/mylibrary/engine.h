// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/ball.h>
#include <mylibrary/brick.h>
#include <mylibrary/direction.h>
#include <mylibrary/paddle.h>
#include <mylibrary/player.h>

#include <vector>

namespace brickbreaker {
class Engine {
 public:
  Engine();
  void MovePaddle(Direction dir) { paddle_.MovePaddle(dir); }

  void DrawEngineElements();

  void MoveBall() { ball_.MoveBall(); }

  void SetGameState(bool state) { has_started_ = state; }

  bool IsInGame() { return has_started_; }

  bool LifeOver();

  bool GameOver();

  bool IsRoundOver();

  void Reset();

  void NextRound();

  void CreateBricks();

  void BrickCollisions();

  bool BoxBoundsAlgorithm(Brick &brick_location);

  void EdgeChecks();

  void Bounces();

  void PaddleHitCheck();

  Location GetPaddleLocation() { return paddle_.GetLocation(); }

  size_t Score() { return score_; }

  size_t Round() { return round_; }

  size_t Lives() { return lives_; }

 private:

  bool has_started_{false};

  Paddle paddle_;

  Ball ball_;

  std::vector<Brick> bricks_{};

  int brick_width_, brick_height_{25}, ball_speed_{4};

  size_t width_{800}, height_{600}, score_{}, lives_{10}, bricks_per_row_{6},
      rows_{2}, round_{1};
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_MYLIBRARY_EXAMPLE_H_

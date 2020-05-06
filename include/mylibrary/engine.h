// Copyright (c) 2020 Adit Kapoor. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <mylibrary/ball.h>
#include <mylibrary/brick.h>
#include <mylibrary/direction.h>
#include <mylibrary/paddle.h>

#include <vector>

namespace brickbreaker {
class Engine {
 public:
  /**
   * Construtor for Engine objects
   */
  Engine();

  /**
   * Used to move the paddle_ based on the user's key-presses
   * @param dir
   */
  void MovePaddle(Direction dir) { paddle_.MovePaddle(dir); }

  /**
   * Used to draw all the Engine elements with draw methods
   */
  void DrawEngineElements();

  /**
   * Calls the ball_'s move function
   */
  void MoveBall() { ball_.MoveBall(); }

  /**
   * Sets the state of the Engine
   * @param state
   */
  void SetGameState(bool state) { has_started_ = state; }

  /**
   * Returns has_started_
   * @return bool
   */
  bool IsInGame() { return has_started_; }

  /**
   * Returns whether the ball_ has missed the paddle_
   * @return bool
   */
  bool LifeOver();

  /**
   * Returns whether all the player's lives_ are over
   * @return bool
   */
  bool GameOver();

  /**
   * Returns whether the player has destroyed all the bricks_ on the screen
   * @return bool
   */
  bool IsRoundOver();

  /**
   * Resets the location_ of the ball_ and stops it from moving
   */
  void Reset();

  /**
   * Sets up for the next round by:
   *    Making the paddle_ slower
   *    Adding more rows_of_bricks_ of Bricks
   *    Adding more bricks_per_row_
   *    Creating a new set of Bricks
   */
  void NextRound();

  /**
   * Fills the bricks_ vector with Bricks
   */
  void CreateBricks();

  /**
   * Removes a Brick from the bricks_ vector if the ball_ collides with it
   */
  void BrickCollisions();

  /**
   * Calls the functions responsible for making the ball_ bounce
   */
  void Bounces();

  /**
   * Returns the paddle_'s location_
   * @return Location
   */
  Location GetPaddleLocation() { return paddle_.GetLocation(); }

  /**
   * Returns the score_
   * @return size_t
   */
  size_t Score() { return score_; }

  /**
   * Returns the round_
   * @return size_t
   */
  size_t Round() { return round_; }

  /**
   * Returns the number of lives_ left
   * @return size_t
   */
  size_t Lives() { return lives_; }

  /**
   * Returns the paddle_'s width_
   * @return int
   */
  int GetPaddleWidth() { return paddle_.GetWidth(); }

  /**
   * Returns the paddle_'s width_
   * @return int
   */
  size_t GetPaddleSpeed() { return paddle_.GetSpeed(); }

  /**
   * Sets the Paddle's speed_
   * @param speed size_t
   */
  void SetPaddleSpeed(size_t speed) { paddle_.SetSpeed(speed); }

  /**
   * Returns the bricks_ vector
   * @return std::vector<Brick>
   */
  std::vector<Brick> GetBricks() { return bricks_; }

  /**
   * Returns rows_of_bricks_
   * @return size_t
   */
  size_t GetRowsOfBricks() { return rows_of_bricks_; }

  /**
   * Returns bricks_per_row_
   * @return size_t
   */
  size_t GetBricksPerRow() { return bricks_per_row_; }

 private:
  /**
   * Returns whether the ball_ has entered the periphery of a Brick
   * @param brick Brick&
   * @return bool
   */
  bool BoxBoundsAlgorithm(Brick &brick);

  /**
   * Makes sure the ball_ is restricted to the dimensions of the window
   */
  void EdgeChecks();

  /**
   * Checks whether the ball_ has hit the paddle_
   */
  void PaddleHitCheck();

  bool has_started_{false};

  Paddle paddle_;

  Ball ball_;

  std::vector<Brick> bricks_{};

  int brick_width_, brick_height_{25}, ball_speed_{4};

  size_t width_{800}, height_{600}, score_{}, lives_{3}, bricks_per_row_{6},
      rows_of_bricks_{2}, round_{1};
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_MYLIBRARY_EXAMPLE_H_

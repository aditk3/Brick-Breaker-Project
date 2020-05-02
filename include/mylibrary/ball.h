//
// Created by Adit Kapoor on 26-04-2020.
//

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/location.h>

using namespace ci;
using namespace ci::app;

namespace brickbreaker {

class Ball {
 public:

  /**
   * Constructor for Ball objects
   * Sets up the starting location and velocity of the ball
   */
  Ball();

  /**
   * Draws circle at the Ball's location
   */
  void DrawBall();

  /**
   * Increments the location_ of the Ball by it's velocity_ every game tick
   */
  void MoveBall();

  /**
   * Reverse's the Ball's velocity acorss the X-axis
   */
  void ReverseX();

  /**
   * Reverse's the Ball's velocity acorss the Y-axis
   */
  void ReverseY();

  /**
   * Returns the radius_
   * @return size_t
   */
  size_t GetRadius() { return radius_; }

  /**
   * Returns the speed_
   * @return int
   */
  int GetSpeed() { return speed_; }

  /**
   * Returns the location_
   * @return Location
   */
  Location GetLocation() { return location_; }

  /**
   * Returns the velocity_
   * @return Location
   */
  Location GetVelocity() { return velocity_; }

  /**
   * Reset's the velocity of the ball after a round
   * @param speed int - default value of -1 used if no speed has been specified
   *                    when calling the function (defaults to original speed)
   */
  void ResetVelocity(int speed = -1);

  /**
   * Used to configure the velocity_ of the ball based of where the Ball
   * rebounded off the Paddle
   *
   * @param zone int
   */
  void ZoneBasedRebounding(int zone);

  /**
   * Set's the velocity_ of the Ball
   * @param velocity Location
   */
  void SetVelocity(Location velocity) { velocity_ = velocity; }

  /**
   * Set's the Ball's location_
   * @param location Location
   */
  void SetLocation(Location location) { location_ = location; }

 private:

  size_t radius_{10};

  int speed_{5};

  Color color_ = Color::white();

  Location location_, velocity_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_BALL_H

// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/Texture.h>
#include <mylibrary/engine.h>
#include <mylibrary/player.h>

#include "SoundPlayer.h"
#include "ciAnimatedGif.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();

  void setup() override;

  void update() override;

  void draw() override;

  void keyDown(cinder::app::KeyEvent) override;

 private:
  /**
   * Starts background music (looped)
   */
  void SetUpMusic();

  /**
   * Prints out the current score and number of lives left
   */
  void DrawScoreBoard();

  /**
   * Initializes GIF
   */
  void SetUpGif();

  /**
   * Draws the gifs
   */
  void DrawGif();

  /**
   * Creates textures for the background
   */
  void SetUpBackground();

  /**
   * Draws the background
   */
  void DrawBackground();

  brickbreaker::Engine engine_;

  brickbreaker::Player player_;

  rph::SoundPlayerRef sound_track_, game_over_sound_;

  cinder::gl::Texture2dRef main_background_texture_;

  ciAnimatedGifRef gif_, bg_gif_;

  float volume_{1.0};
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

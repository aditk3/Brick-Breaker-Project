// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/direction.h>
#include <mylibrary/location.h>

#include <iostream>
#include <string>

#include "SoundPlayer.h"

using namespace ci::app;
using namespace ci;

const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial Bold";
const char kDifferentFont[] = "Papyrus";

namespace myapp {

using cinder::app::KeyEvent;

/**
 * Draws a vertical line to separate the scoreboard and play area
 */
static void DrawBorder();

/**
 * Draws instructions to start the game
 */
static void DrawStartGame();

/**
 * Prints text
 * @param text std::string - String to print
 * @param color ci::Color - Color of text
 * @param size ivec2 - Size of text
 * @param loc vec2 - Location to print at
 */
template <typename C>
void PrintText(const std::string &text, const C &color,
               const cinder::ivec2 &size, const cinder::vec2 &loc,
               const int font_size = 30) {
  cinder::gl::color(color);

  auto box = TextBox()
                 .alignment(TextBox::CENTER)
                 .font(cinder::Font(kNormalFont, font_size))
                 .size(size)
                 .color(color)
                 .backgroundColor(ColorA(0, 0, 0, 1))
                 .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

MyApp::MyApp() : player_("adit", 0) {}

void MyApp::setup() {
  SetUpMusic();
  SetUpGif();
  SetUpBackground();
  engine_.CreateBricks();
}

void MyApp::update() {
  if (engine_.GameOver()) {
    sound_track_->stop();
    game_over_sound_->play();
    player_.score_ = engine_.Score();
  }
  if (engine_.IsInGame()) {
    engine_.Bounces();
    engine_.MoveBall();
    engine_.BrickCollisions();

    if (engine_.LifeOver()) {
      engine_.SetGameState(false);
      engine_.Reset();
    }

    if (engine_.IsRoundOver()) {
      engine_.SetGameState(false);
      engine_.NextRound();
    }
  }
}

void MyApp::draw() {
  gl::clear(Color::black());
  DrawScoreBoard();
  if (!engine_.GameOver()) {
    DrawBorder();
    if (!engine_.IsInGame()) {
      DrawStartGame();
    }
    engine_.DrawEngineElements();
    DrawBackground();
  } else {
    DrawGif();
  }
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_RETURN: {
      if (!engine_.IsInGame() && !engine_.GameOver()) {
        engine_.SetGameState(true);
      }
      break;
    }

    case KeyEvent::KEY_LEFT:
    case KeyEvent::KEY_a: {
      engine_.MovePaddle(brickbreaker::Direction::kLeft);
      break;
    }

    case KeyEvent::KEY_RIGHT:
    case KeyEvent::KEY_d: {
      engine_.MovePaddle(brickbreaker::Direction::kRight);
      break;
    }

    case KeyEvent::KEY_m: {
      if (volume_ == 0) {
        volume_ = 1.0f;
      } else {
        volume_ = 0.0f;
      }
      sound_track_->setVolume(volume_);
    }
  }
}

static void DrawBorder() {
  gl::color(Color::white());
  gl::drawSolidRect(Rectf(800, 0, 802, 600));
}

static void DrawStartGame() {
  const cinder::vec2 loc_score(400, 225);
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::white();
  std::string to_print = "Press the 'Enter Key' to begin";
  PrintText(to_print, color, size, loc_score);
}

void MyApp::DrawScoreBoard() {
  if (!engine_.GameOver()) {
    // Prints score
    const cinder::vec2 loc_score(900, 50);
    const cinder::ivec2 size = {190, 35};
    const Color color = Color::white();
    std::string to_print = "Score: " + std::to_string(engine_.Score());
    PrintText(to_print, color, size, loc_score, 22);

    //Prints round
    const cinder::vec2 loc_round(900, 400);
    to_print = "Round: " + std::to_string(engine_.Round());
    PrintText(to_print, color, size, loc_round, 22);

    //Prints lives
    const cinder::vec2 loc_lives(900, 600 - 35);
    to_print = "Lives: " + std::to_string(engine_.Lives());
    PrintText(to_print, color, size, loc_lives, 22);
  } else {
    const cinder::vec2 loc_score(500, 400);
    const cinder::ivec2 size = {300, 75};
    const Color color = Color::white();
    std::string to_print = "Score: " + std::to_string(player_.score_);
    PrintText(to_print, color, size, loc_score, 50);
  }
}

void MyApp::SetUpMusic() {
  sound_track_ = rph::SoundPlayer::create(loadAsset("temp.mp3"));
  sound_track_->setLoop(true);
  sound_track_->setVolume(volume_);
  sound_track_->start();

  game_over_sound_ = rph::SoundPlayer::create(loadAsset("loser.mp3"));
  game_over_sound_->setVolume(1.0f);
}

void MyApp::SetUpBackground() {
  ci::gl::enableDepthRead();
  auto img = loadImage(loadAsset("main_bg.png"));
  main_background_texture_ = gl::Texture2d::create(img);
}

void MyApp::SetUpGif() {
  gif_ = ciAnimatedGif::create(loadAsset("game_over.gif"));

  bg_gif_ = ciAnimatedGif::create(loadAsset("game_over_bg.gif"));
}

void MyApp::DrawBackground() {
  gl::color(Color(1, 1, 1));
  gl::draw(main_background_texture_, Rectf(0, 0, 1000, 600));
}

void MyApp::DrawGif() {
  gl::color(Color(1, 1, 1));
  gl::pushMatrices();
  gl::translate((1000 - 580) / 2, 100);
  gl::scale(.50, .50);
  gif_->draw();
  gl::popMatrices();
  gl::pushMatrices();
  gl::scale(2.2, 2.2);
  bg_gif_->draw();
  gl::popMatrices();
}

}  // namespace myapp

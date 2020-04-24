// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

#include "SoundPlayer.h"

using namespace ci::app;
using namespace ci;

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  sound_track_ = rph::SoundPlayer::create(loadAsset("temp.mp3"));
  sound_track_->setLoop(true);
  sound_track_->setVolume(1.0);
  sound_track_->start();

  gif_ = ciAnimatedGif::create(loadAsset("temp.gif"));
}

void MyApp::update() { }

void MyApp::draw() {
  gl::clear(Color(0.5, 0.5, 0.5));
  float gray = sin(getElapsedSeconds()) * 0.5f + 0.5f;
  gl::color(Color(gray, gray, gray));
  gl::drawSolidCircle(getWindowCenter(), 200);
  gl::color(Color(1, 1, 1));

  gl::translate(140, 100);
  gif_->draw();
  gl::translate(-140, -100);
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp

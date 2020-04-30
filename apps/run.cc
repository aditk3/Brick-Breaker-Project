// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <gflags/gflags.h>

#include "my_app.h"

using cinder::app::App;
using cinder::app::RendererGl;

namespace myapp {

const int kSamples = 8;
const int kWidth = 1000;
const int kHeight = 600;

void SetUp(App::Settings *settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setFrameRate(60.0f);
  settings->setTitle("My CS 126 Application");
}

}  // namespace myapp

// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)

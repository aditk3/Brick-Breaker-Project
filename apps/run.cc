// Copyright (c) 2020 Adit Kapoor. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <gflags/gflags.h>

#include <string>
#include <vector>

#include "my_app.h"

using cinder::app::App;
using cinder::app::RendererGl;
using std::string;
using std::vector;

namespace myapp {
DEFINE_string(name, "Adit", "the name of the player");

// Code taken from CS126 Snake Repo
void ParseArgs(vector<string>* args) {
  gflags::SetUsageMessage(
      "Play a game of Brick Breaker. Pass --helpshort for options.");
  int argc = static_cast<int>(args->size());

  vector<char*> argvs;
  for (string& str : *args) {
    argvs.push_back(&str[0]);
  }

  char** argv = argvs.data();
  gflags::ParseCommandLineFlags(&argc, &argv, true);
}

const int kSamples = 8;
const int kWidth = 1000;
const int kHeight = 600;

void SetUp(App::Settings* settings) {
  // Code taken from CS126 Snake Repo
  vector<string> args = settings->getCommandLineArgs();
  ParseArgs(&args);

  settings->setWindowSize(kWidth, kHeight);
  settings->setFrameRate(60.0f);
  settings->setTitle("Brick-Breaker");
}

}  // namespace myapp

// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)

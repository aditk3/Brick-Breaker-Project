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
        void SetUpMusic();

        void DrawScoreBoard();

        void SetUpGif();

        brickbreaker::Engine engine_;
        brickbreaker::Player player_;
        rph::SoundPlayerRef sound_track_;
        ciAnimatedGifRef gif_;
    };

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_

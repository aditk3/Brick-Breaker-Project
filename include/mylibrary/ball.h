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
            Ball();
            void DrawBall();
        private:
            size_t radius_{10};
            Color color_ = Color::white();
            Location location_;
        };
}

#endif //FINALPROJECT_BALL_H

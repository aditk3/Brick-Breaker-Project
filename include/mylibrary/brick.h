//
// Created by Adit Kapoor on 29-04-2020.
//

#ifndef FINALPROJECT_BRICK_H
#define FINALPROJECT_BRICK_H


#include <mylibrary/location.h>

namespace brickbreaker {

    class Brick {
        public:
            Brick(int width, int height, Location location);
            void DrawBrick();
            Location GetLocation() { return location_; }
            int Width() { return width_; }
            int Height() { return height_; }

        private:
            Location location_;
            int width_, height_;
    };
}

#endif //FINALPROJECT_BRICK_H

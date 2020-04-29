//
// Created by Adit Kapoor on 29-04-2020.
//

#ifndef FINALPROJECT_BRICK_H
#define FINALPROJECT_BRICK_H


#include <mylibrary/location.h>

namespace brickbreaker {

    class Brick {
        public:
            Brick(int width, Location location);
            void DrawBrick();

        private:
            Location location_;
            int width_, height_{25};
    };
}

#endif //FINALPROJECT_BRICK_H

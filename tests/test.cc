// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/ball.h>
#include <mylibrary/brick.h>
#include <mylibrary/direction.h>
#include <mylibrary/engine.h>
#include <mylibrary/location.h>
#include <mylibrary/paddle.h>
#include <mylibrary/player.h>

#include <catch2/catch.hpp>

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}
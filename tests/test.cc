// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <mylibrary/location.h>
#include <mylibrary/player.h>

#include <catch2/catch.hpp>
#include <string>

TEST_CASE("Player Class tests") {
  std::string name{"test_player"};
  int score{0};
  brickbreaker::Player player(name, score);

  SECTION("Player constructor") {
    REQUIRE(0 == player.score);
    REQUIRE(name == player.name);
  }

  SECTION("Player value editing") {
    player.score = player.score + 1;
    REQUIRE(1 == player.score);

    player.score = player.score - 1;
    REQUIRE(score == player.score);
  }
}

TEST_CASE("Location Class tests") {
  int x{}, y{};
  brickbreaker::Location loc(x, y);

  SECTION("Location constructor") {
    REQUIRE(loc.X() == x);
    REQUIRE(loc.Y() == y);
  }

  SECTION("Adding Locations") {
    // Adding positive values
    x += 5;
    y += 5;
    brickbreaker::Location to_add_pos(x, y);
    loc += to_add_pos;
    REQUIRE(loc.X() == x);
    REQUIRE(loc.Y() == x);

    // Adding negative values
    int x2{-3}, y2{-4};
    loc += brickbreaker::Location(x2, y2);
    REQUIRE(loc.X() == x - (-x2));
    REQUIRE(loc.Y() == y - (-y2));
  }

  SECTION("Subtracting Locations") {
    x += 5;
    y += 5;
    brickbreaker::Location to_sub_from(x, y);
    loc -= to_sub_from;
    REQUIRE(loc.X() == -x);
    REQUIRE(loc.Y() == -y);
  }
}
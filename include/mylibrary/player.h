//
// Created by Adit Kapoor on 4/26/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>

namespace brickbreaker {
struct Player {
  Player(const std::string& name, size_t score) : name_(name), score_(score) {}

  std::string name_;

  size_t score_;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_PLAYER_H

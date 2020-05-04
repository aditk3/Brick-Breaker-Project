//
// Created by Adit Kapoor on 4/26/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>

namespace brickbreaker {
struct Player {
  Player(const std::string& player_name, size_t player_score)
      : name(player_name), score(player_score) {}

  std::string name;

  size_t score;
};
}  // namespace brickbreaker

#endif  // FINALPROJECT_PLAYER_H

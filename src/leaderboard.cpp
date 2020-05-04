//
// Code taken from CS126 Snake project
//

#include <mylibrary/leaderboard.h>
#include <mylibrary/player.h>
#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

namespace brickbreaker {
using std::string;
using std::vector;

// See examples: https://github.com/SqliteModernCpp/sqlite_modern_cpp/tree/dev

LeaderBoard::LeaderBoard(const string& db_path) : db_{db_path} {
  db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  name  TEXT NOT NULL,\n"
         "  score INTEGER NOT NULL\n"
         ");";
}

void LeaderBoard::AddScoreToLeaderBoard(const Player& player) {
  string command =
      "INSERT INTO leaderboard (name, score) "
      "VALUES( '" +
      player.name + "', " + std::to_string(player.score) + ");";
  try {
    db_ << command;
  } catch (std::exception& e) {
    std::cout << command;
  }
}

vector<Player> GetPlayers(sqlite::database_binder* rows) {
  vector<Player> players;

  for (auto&& row : *rows) {
    string name;
    size_t score;
    row >> name >> score;
    Player player = {name, score};
    players.push_back(player);
  }

  return players;
}

vector<Player> LeaderBoard::RetrieveHighScores(const size_t limit) {
  auto rows = db_ << "SELECT * from leaderboard ORDER BY score DESC LIMIT " +
                         std::to_string(limit) + ";";
  return GetPlayers(&rows);
}

vector<Player> LeaderBoard::RetrieveHighScores(const Player& player,
                                               const size_t limit) {
  auto rows = db_ << "SELECT * from leaderboard WHERE name = '" + player.name +
                         "' ORDER BY score DESC LIMIT " +
                         std::to_string(limit) + ";";
  return GetPlayers(&rows);
}
}  // namespace brickbreaker
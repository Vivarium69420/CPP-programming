#include <iostream>
using namespace std;

class BallGame {
private:
  double fieldRadius;
  int numPlayers;

public:
  BallGame() : numPlayers(0) {}

  void setFieldRadius(double radius) { fieldRadius = radius; }
  void getNumPlayers() {
    cout << "The number of players: " << numPlayers << endl;
  }

  class Player {
  private:
    int playerNumber;

  public:
    Player(BallGame &game) { game.numPlayers++; }

    void setPlayerNumber(int num) { playerNumber = num; }
    void ackFieldSize(BallGame &game) {
      cout << "Player " << playerNumber
           << " acknowledge the field radius: " << game.fieldRadius << endl;
    }
  };
};

int main() {
  BallGame game;
  game.setFieldRadius(100.0);

  BallGame::Player player(game);
  player.setPlayerNumber(1);

  BallGame::Player player2(game);
  player2.setPlayerNumber(22);

  player.ackFieldSize(game);
  game.getNumPlayers();
}

#include <cstdarg>
#include <iostream>

using namespace std;
class Player {
 private:
  int *number;

 public:
  Player(int playerNumber) : number(new int(playerNumber)) {}
  void setNumber(int playerNumber) { *this->number = playerNumber; }
  int *getNumber() { return this->number; }
  Player(const Player &player) {
    this->number = new int();
    *number = *player.number;  // Deep copy
    // this->number = player.number;   // Shallow copy
  }
  ~Player() { delete[] number; }
};

void printPlayerNumber(int numPlayer...) {
  va_list args;
  va_start(args, numPlayer);

  for (size_t i = 0; i < numPlayer; i++) {
    Player *player = va_arg(args, Player *);
    cout << "Memory address of player number " << i + 1 << ": "
         << player->getNumber() << endl;
    cout << "The value player number " << i + 1 << ": " << *player->getNumber()
         << endl;
  }
}

int main(int argc, char *argv[]) {
  Player c1 = 12;

  Player c2 = c1;
  printPlayerNumber(2, &c1, &c2);

  c2.setNumber(15);

  printPlayerNumber(2, &c1, &c2);

  return 0;
}

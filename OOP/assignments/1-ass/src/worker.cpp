#include "../include/worker.h"

// Getter for level
int Worker::getLevel() { return level; }

// Setter for level
void Worker::setLevel(int level) { this->level = level; }

// Print details of Worker
void Worker::printDetails() {
  cout << "Worker: " << getName() << ", " << getAge() << ", " << getGender()
       << ", " << getAddress() << ", " << getLevel() << endl;
}
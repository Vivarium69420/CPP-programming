#include "../include/staff.h"

// Getter for level
string Staff::getTask() { return task; }

// Setter for level
void Staff::setTask(string task) { this->task = task; }

// Print details of Staff
void Staff::printDetails() {
  cout << "Staff: " << getName() << ", " << getAge() << ", " << getGender()
       << ", " << getAddress() << ", " << getTask() << endl;
}
#include "../include/engineer.h"

// Getter for speciality
string Engineer::getSpeciality() { return speciality; }

// Setter for speciality
void Engineer::setSpeciality(string speciality) {
  this->speciality = speciality;
}

// Print details of Engineer
void Engineer::printDetails() {
  cout << "Engineer: " << getName() << ", " << getAge() << ", " << getGender()
       << ", " << getAddress() << ", " << getSpeciality() << endl;
}
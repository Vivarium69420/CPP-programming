#include "../include/Newspaper.h"

// Getter for publicationDay
int Newspaper::getPublicationDay() { return publicationDay; }

// Setter for publicationDay
void Newspaper::setPublicationDay(int pd) { publicationDay = pd; }

// Implementation of display method
void Newspaper::display() {
  Document::display();
  cout << "Publishcation Day: " << publicationDay << endl;
  cout << "--------------------------------\n";
}

// Implementation of getType method
doc_t Newspaper::getType() { return NEWSPAPER; }
#include "../include/Magazine.h"

// Getter for issueNumber
int Magazine::getIssueNumber() { return issueNumber; }

// Setter for issueNumber
void Magazine::setIssueNumber(int in) { issueNumber = in; }

// Getter for publicationMonth
int Magazine::getPublicationMonth() { return publicationMonth; }

// Setter for publicationMonth
void Magazine::setPublicationMonth(int pm) { publicationMonth = pm; }

// Implementation of display method
void Magazine::display() {
  Document::display();
  cout << "Issue Number: " << issueNumber << endl;
  cout << "Publication Month: " << publicationMonth << endl;
  cout << "--------------------------------\n";
}

// Implementation of getType method
doc_t Magazine::getType() { return MAGAZINE; }

#include "../include/Document.h"

// Getter for documentId
string Document::getDocId() { return documentId; }

// Setter for documentId
void Document::setDocId(string id) { documentId = id; }

// Getter for publisher
string Document::getPublisher() { return publisher; }

// Setter for publisher
void Document::setPublisher(string ps) { publisher = ps; }

// Getter for copiesCount
int Document::getCopiesCount() { return copiesCount; }

// Setter for copiesCount
void Document::setCopiesCount(int cnt) { copiesCount = cnt; }

void Document::display() {
  cout << "Document ID: " << documentId << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Copies Count: " << copiesCount << endl;
}

doc_t Document::getType() { return DOCUMENT; }
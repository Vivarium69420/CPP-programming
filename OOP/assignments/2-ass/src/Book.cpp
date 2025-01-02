#include "../include/Book.h"

#include "../include/Document.h"

// Getter for authorName
string Book::getAuthorName() { return authorName; }

// Setter for authorName
void Book::setAuthorName(string n) { authorName = n; }

// Getter for pageCount
int Book::getPageCount() { return pageCount; }

// Setter for pageCount
void Book::setPageCount(int cnt) { pageCount = cnt; }

// Implementation of display method
void Book::display() {
  Document::display();
  cout << "Author Name: " << authorName << endl;
  cout << "Page Count: " << pageCount << endl;
  cout << "--------------------------------\n";
}

// Implementation of getType method
doc_t Book::getType() { return BOOK; }
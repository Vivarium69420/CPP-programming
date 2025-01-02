#include "../include/LibraryManager.h"

#include <iostream>
#include <limits>

#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/Newspaper.h"

void LibraryManager::addDoc(shared_ptr<Document> doc) {
  documents.push_back(doc);
}

void LibraryManager::deleteDoc(const string &docId) {
  documents.remove_if([&docId](const shared_ptr<Document> &doc) {
    return doc->getDocId() == docId;
  });
}

void LibraryManager::searchByDocType(doc_t type) {
  for (const auto &doc : documents) {
    if (doc->getType() == type) {
      doc->display();
    }
  }
}

void LibraryManager::showList() {
  for (const auto &doc : documents) {
    doc->display();
  }
}

int LibraryManager::getValidIntInput(int min, int max) {
  int input;
  while (true) {
    cin >> input;
    if (cin.fail() || input < min || input > max) {
      cin.clear();  // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // discard invalid input
      cout << "Invalid input. Please enter a number between " << min << " and "
           << max << ": ";
    } else {
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // discard any extra input
      return input;
    }
  }
}

void LibraryManager::addDocument() {
  cout << "Enter document type (1. Book, 2. Magazine, 3. Newspaper): ";
  int type = getValidIntInput(1, 3);

  cout << "Enter document ID: ";
  string id;
  cin.ignore();
  getline(cin, id);

  cout << "Enter publisher: ";
  string publisher;
  getline(cin, publisher);

  cout << "Enter number of copies: ";
  int copies = getValidIntInput(1, numeric_limits<int>::max());

  if (type == 1) {
    cout << "Enter author: ";
    string author;
    getline(cin, author);

    cout << "Enter page count: ";
    int pageCount = getValidIntInput(1, numeric_limits<int>::max());
    addDoc(make_shared<Book>(id, publisher, copies, author, pageCount));
  } else if (type == 2) {
    cout << "Enter issue number: ";
    int issueNumber = getValidIntInput(1, numeric_limits<int>::max());

    cout << "Enter publication month: ";
    int publicationMonth = getValidIntInput(1, 12);
    addDoc(make_shared<Magazine>(id, publisher, copies, issueNumber,
                                 publicationMonth));
  } else if (type == 3) {
    cout << "Enter publication date: ";
    int publicationDate = getValidIntInput(1, numeric_limits<int>::max());
    addDoc(make_shared<Newspaper>(id, publisher, copies, publicationDate));
  }
  cout << "Document added successfully\n";
  cout << "--------------------------------\n";
}

void LibraryManager::deleteDocument() {
  cout << "--------------------------------\n";
  cout << "Enter document ID to delete: ";
  string id;
  cin.ignore();
  getline(cin, id);
  deleteDoc(id);
  cout << "Document deleted successfully\n";
  cout << "--------------------------------\n";
}

void LibraryManager::searchDocument() {
  cout
      << "Enter document type to search (1. Book, 2. Magazine, 3. Newspaper): ";
  int type = getValidIntInput(1, 3);
  if (type == 1) {
    searchByDocType(BOOK);
  } else if (type == 2) {
    searchByDocType(MAGAZINE);
  } else if (type == 3) {
    searchByDocType(NEWSPAPER);
  }
  cout << "--------------------------------\n";
}

void LibraryManager::showDocumentList() {
  showList();
  cout << "--------------------------------\n";
}
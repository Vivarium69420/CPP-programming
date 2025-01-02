#include <iostream>
#include <limits>
#include <memory>

#include "../include/Book.h"
#include "../include/LibraryManager.h"
#include "../include/Magazine.h"
#include "../include/Newspaper.h"

int getValidIntInput(int min, int max) {
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

int main(int argc, char *argv[]) {
  LibraryManager lm;

  // std::shared_ptr<Document> b =
  //     std::make_shared<Book>("Hello", "Hi", 123, "awdjiwa", 123123);
  // lm.addDoc(b);
  // lm.searchByDocType(BOOK);
  // lm.deleteDoc("Hello");

  while (true) {
    cout << "1. Add a document\n"
            "2. Delete a document\n"
            "3. Search by document type\n"
            "4. Exit\n";

    cout << "Enter your choice: ";
    int choice = getValidIntInput(1, 4);

    switch (choice) {
      case 1: {
        cout << "--------------------------------\n";
        cout << "Enter document type (1. Book, 2. Journal, 3. Magazine): ";
        int type = getValidIntInput(1, 3);

        cout << "Enter document ID: ";
        string id;
        getline(cin, id);

        cout << "Enter publisher: ";
        string publisher;
        getline(cin, publisher);

        cout << "Enter count: ";
        int count = getValidIntInput(1, numeric_limits<int>::max());

        switch (type) {
          case 1: {
            cout << "Enter author name: ";
            string author;
            getline(cin, author);

            cout << "Enter page count: ";
            int pages = getValidIntInput(1, numeric_limits<int>::max());

            std::shared_ptr<Document> b =
                std::make_shared<Book>(id, publisher, count, author, pages);
            lm.addDoc(b);

            cout << "Book added successfully\n";
            cout << "--------------------------------\n";
            break;
          }
          case 2: {
            cout << "Enter issue number: ";
            int issue = getValidIntInput(1, numeric_limits<int>::max());

            cout << "Enter publication month: ";
            int pm = getValidIntInput(1, 12);

            std::shared_ptr<Document> j =
                std::make_shared<Magazine>(id, publisher, count, issue, pm);
            lm.addDoc(j);

            cout << "Magazine added successfully\n";
            cout << "--------------------------------\n";
            break;
          }
          case 3: {
            cout << "Enter publication day: ";
            int pd = getValidIntInput(1, numeric_limits<int>::max());

            std::shared_ptr<Document> m =
                std::make_shared<Newspaper>(id, publisher, count, pd);
            lm.addDoc(m);

            cout << "Newspaper added successfully\n";
            cout << "--------------------------------\n";
            break;
          }
        }
        break;
      }
      case 2: {
        cout << "--------------------------------\n";
        cout << "Enter document ID: ";
        string id;
        getline(cin, id);
        lm.deleteDoc(id);

        cout << "Document deleted successfully\n";
        cout << "--------------------------------\n";
        break;
      }
      case 3: {
        cout << "--------------------------------\n";
        cout << "Enter document type (1. Book, 2. Journal, 3. Magazine): ";
        int type = getValidIntInput(1, 3);
        if (type == 1) {
          cout << "Books\n";
          lm.searchByDocType(BOOK);
        } else if (type == 2) {
          cout << "Magazines\n";
          lm.searchByDocType(MAGAZINE);
        } else if (type == 3) {
          cout << "Newspapers\n";
          lm.searchByDocType(NEWSPAPER);
        }
        cout << "--------------------------------\n";
        break;
      }
      default:
        return 0;
    }
  }
  return 0;
}
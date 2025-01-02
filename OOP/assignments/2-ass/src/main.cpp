#include <iostream>
#include <limits>
#include <vector>

#include "../include/LibraryManager.h"

// Define macros for menu options
#define OPTION_ADD_DOCUMENT 1
#define OPTION_SHOW_DOCUMENT_LIST 2
#define OPTION_SEARCH_DOCUMENT 3
#define OPTION_DELETE_DOCUMENT 4
#define OPTION_EXIT 5

int main() {
  LibraryManager lm;

  while (true) {
    cout << "--------------------------------\n";
    cout << OPTION_ADD_DOCUMENT << ". Add document\n";
    cout << OPTION_SHOW_DOCUMENT_LIST << ". Show document list\n";
    cout << OPTION_SEARCH_DOCUMENT << ". Search document\n";
    cout << OPTION_DELETE_DOCUMENT << ". Delete document\n";
    cout << OPTION_EXIT << ". Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
    int choice = lm.getValidIntInput(OPTION_ADD_DOCUMENT, OPTION_EXIT);

    switch (choice) {
      case OPTION_ADD_DOCUMENT:
        lm.addDocument();
        break;
      case OPTION_SHOW_DOCUMENT_LIST:
        lm.showDocumentList();
        break;
      case OPTION_SEARCH_DOCUMENT:
        lm.searchDocument();
        break;
      case OPTION_DELETE_DOCUMENT:
        lm.deleteDocument();
        break;
      case OPTION_EXIT:
        cout << "Exiting...\n";
        return 0;
      default:
        cout << "Invalid choice\n";
        break;
    }
  }

  return 0;
}
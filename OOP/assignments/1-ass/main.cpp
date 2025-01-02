#include <iostream>
#include <limits>
#include <vector>

#include "include/engineer.h"
#include "include/officer_management.h"
#include "include/staff.h"
#include "include/worker.h"

// Define macros for menu options
#define OPTION_ADD_OFFICER 1
#define OPTION_SHOW_OFFICER_LIST 2
#define OPTION_SEARCH_OFFICER 3
#define OPTION_EXIT 4

int main() {
  OfficerManager om;

  while (true) {
    cout << "--------------------------------\n";
    cout << OPTION_ADD_OFFICER << ". Add officer\n";
    cout << OPTION_SHOW_OFFICER_LIST << ". Show officer list\n";
    cout << OPTION_SEARCH_OFFICER << ". Search officer\n";
    cout << OPTION_EXIT << ". Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
    int choice = om.getValidIntInput(OPTION_ADD_OFFICER, OPTION_EXIT);

    switch (choice) {
      case OPTION_ADD_OFFICER:
        om.addOfficer();
        break;
      case OPTION_SHOW_OFFICER_LIST:
        om.showOfficerList();
        break;
      case OPTION_SEARCH_OFFICER:
        om.searchOfficerByName();
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
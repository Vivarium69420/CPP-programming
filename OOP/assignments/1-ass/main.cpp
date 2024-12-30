#include <iostream>
#include <limits>

#include "include/engineer.h"
#include "include/officer_management.h"
#include "include/staff.h"
#include "include/worker.h"

using namespace std;

int getValidatedInput(int min, int max) {
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

int main() {
  OfficerManager om;
  while (true) {
    cout << "1. Add an officer\n"
            "2. Show list\n"
            "3. Search by name\n"
            "4. Exit\n";

    cout << "Enter your choice: ";
    int choice = getValidatedInput(1, 4);

    switch (choice) {
      case 1: {
        cout << "--------------------------------\n";
        cout << "Enter officer type (1. Engineer, 2. Staff, 3. Worker): ";
        int type = getValidatedInput(1, 3);

        cout << "Enter name: ";
        string name;
        cin >> name;

        cout << "Enter age: ";
        int age = getValidatedInput(1, numeric_limits<int>::max());

        cout << "Gender: ";
        string gender;
        cin >> gender;

        cout << "Address: ";
        string address;
        cin >> address;

        if (type == 1) {
          cout << "Enter speciality: ";
          string speciality;
          cin >> speciality;
          om.add(new Engineer(name, age, gender, address, speciality));
        } else if (type == 2) {
          cout << "Enter task: ";
          string task;
          cin >> task;
          om.add(new Staff(name, age, gender, address, task));
        } else if (type == 3) {
          cout << "Enter level: ";
          int level = getValidatedInput(1, numeric_limits<int>::max());
          om.add(new Worker(name, age, gender, address, level));
        }
        cout << "Officer added successfully\n";
        cout << "--------------------------------\n";
        break;
      }
      case 2:
        cout << "--------------------------------\n";
        cout << "List of officers\n";
        om.showList();
        cout << "--------------------------------\n";
        break;

      case 3: {
        cout << "--------------------------------\n";
        cout << "Enter name to search: ";
        string name;
        cin >> name;
        Officer *officer = om.searchByName(name);
        if (officer) {
          cout << "Officer found\n";
          officer->printDetails();
        } else {
          cout << "Officer not found\n";
        }
        cout << "--------------------------------\n";
        break;
      }
      case 4:
        return 0;

      default:
        cout << "Invalid choice\n";
    }
  }

  return 0;
}
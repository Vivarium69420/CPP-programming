#include "../include/officer_management.h"

void OfficerManager::add(Officer *officer) { officers.push_back(officer); }

Officer *OfficerManager::searchByName(const string &name) {
  for (auto it = officers.begin(); it != officers.end(); ++it) {
    if ((*it)->getName() == name) {
      return *it;
    }
  }
  return 0;
}

void OfficerManager::showList() {
  for (const auto &officer : officers) {
    officer->printDetails();
  }
}

int OfficerManager::getValidIntInput(int min, int max) {
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

void OfficerManager::addOfficer() {
  cout << "--------------------------------\n";
  cout << "Enter officer type (1. Engineer, 2. Staff, 3. Worker): ";
  int type = getValidIntInput(1, 3);

  cout << "Enter name: ";
  string name;
  cin.ignore();
  getline(cin, name);

  cout << "Enter age: ";
  int age = getValidIntInput(1, numeric_limits<int>::max());

  cout << "Gender: ";
  string gender;
  getline(cin, gender);

  cout << "Address: ";
  string address;
  getline(cin, address);

  if (type == 1) {
    cout << "Enter speciality: ";
    string speciality;
    getline(cin, speciality);
    add(new Engineer(name, age, gender, address, speciality));
  } else if (type == 2) {
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    add(new Staff(name, age, gender, address, task));
  } else if (type == 3) {
    cout << "Enter level: ";
    int level = getValidIntInput(1, numeric_limits<int>::max());
    add(new Worker(name, age, gender, address, level));
  }
  cout << "Officer added successfully\n";
  cout << "--------------------------------\n";
}

void OfficerManager::showOfficerList() {
  cout << "--------------------------------\n";
  showList();
  cout << "--------------------------------\n";
}

void OfficerManager::searchOfficerByName() {
  cout << "--------------------------------\n";
  cout << "Enter name to search: ";
  string name;
  cin.ignore();
  getline(cin, name);
  Officer *officer = searchByName(name);
  if (officer) {
    cout << "Officer found\n";
    officer->printDetails();
  } else {
    cout << "Officer not found\n";
  }
  cout << "--------------------------------\n";
}
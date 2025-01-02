#include "../include/Hotel.h"

#include <iostream>
#include <limits>

void Hotel::addCus(unique_ptr<Customer> customer) {
  customers.push_back(std::move(customer));
}

void Hotel::displayCus() {
  for (const auto &customer : customers) {
    cout << customer->getDetails() << endl;
  }
}

void Hotel::displayRoomType(const string &type) {
  auto it = rooms.find(type);
  if (it != rooms.end()) {
    cout << "Room type " << type << ": " << it->second << " rooms available\n";
  } else {
    cout << "Room type not found\n";
  }
}

int Hotel::getValidIntInput(int min, int max) {
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

void Hotel::deleteCusById(const string &id) {
  for (auto it = customers.begin(); it != customers.end(); ++it) {
    if ((*it)->getID() == id) {
      customers.erase(it);
      cout << "Customer deleted successfully\n";
      return;
    }
  }
  cout << "Customer not found\n";
}

int Hotel::calculateRentalFeeById(const string &id) {
  for (const auto &customer : customers) {
    if (customer->getID() == id) {
      string roomType = customer->getRoomType();
      int rentalDays = customer->getRentalDays();
      auto it = rooms.find(roomType);
      if (it != rooms.end()) {
        return it->second * rentalDays;
      }
    }
  }
  cout << "Customer not found\n";
  return 0;
}

Customer *Hotel::searchCusById(const string &id) {
  for (const auto &customer : customers) {
    if (customer->getID() == id) {
      return customer.get();
    }
  }
  return nullptr;
}

void Hotel::addCustomer() {
  cout << "--------------------------------\n";
  cout << "Enter full name: ";
  string fullName;
  cin.ignore();
  getline(cin, fullName);

  cout << "Enter age: ";
  int age = getValidIntInput(1, numeric_limits<int>::max());

  cout << "Enter ID: ";
  string ID;
  getline(cin, ID);

  cout << "Enter rental days: ";
  int rentalDays = getValidIntInput(1, numeric_limits<int>::max());

  cout << "Enter room type (A, B, C): ";
  string roomType;
  getline(cin, roomType);

  addCus(make_unique<Customer>(fullName, age, ID, rentalDays, roomType));
  cout << "Customer added successfully\n";
  cout << "--------------------------------\n";
}

void Hotel::displayCustomers() {
  cout << "--------------------------------\n";
  displayCus();
  cout << "--------------------------------\n";
}

void Hotel::displayRoomType() {
  cout << "--------------------------------\n";
  cout << "Enter room type (A, B, C): ";
  string type;
  cin.ignore();
  getline(cin, type);
  displayRoomType(type);
  cout << "--------------------------------\n";
}

void Hotel::deleteCustomerByID() {
  cout << "--------------------------------\n";
  cout << "Enter customer ID to delete: ";
  string ID;
  cin.ignore();
  getline(cin, ID);
  deleteCusById(ID);
  cout << "--------------------------------\n";
}

void Hotel::calculateRentalFeeByCustomerID() {
  cout << "--------------------------------\n";
  cout << "Enter customer ID to calculate rental fee: ";
  string ID;
  cin.ignore();
  getline(cin, ID);
  int fee = calculateRentalFeeById(ID);
  if (fee > 0) {
    cout << "Total rental fee: " << fee << endl;
  }
  cout << "--------------------------------\n";
}

void Hotel::searchByCustomerID() {
  cout << "--------------------------------\n";
  cout << "Enter customer ID to search: ";
  string ID;
  cin.ignore();
  getline(cin, ID);
  Customer *customer = searchCusById(ID);
  if (customer) {
    cout << customer->getDetails() << endl;
  } else {
    cout << "Customer not found\n";
  }
  cout << "--------------------------------\n";
}
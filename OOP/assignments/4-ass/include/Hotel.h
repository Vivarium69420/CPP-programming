#ifndef HOTEL_H
#define HOTEL_H

#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Customer.h"

using namespace std;

class Hotel {
 private:
  list<unique_ptr<Customer>> customers;
  map<string, int> rooms = {{"A", 500}, {"B", 300}, {"C", 100}};

  void addCus(unique_ptr<Customer> customer);
  void displayCus();
  void displayRoomType(const string &type);
  void deleteCusById(const string &id);
  int calculateRentalFeeById(const string &id);
  Customer *searchCusById(const string &id);

 public:
  // Constructor
  Hotel() {}

  // Destructor
  ~Hotel() {}

  int getValidIntInput(int min, int max);
  void addCustomer();
  void displayCustomers();
  void displayRoomType();
  void deleteCustomerByID();
  void calculateRentalFeeByCustomerID();
  void searchByCustomerID();
};

#endif  // HOTEL_H
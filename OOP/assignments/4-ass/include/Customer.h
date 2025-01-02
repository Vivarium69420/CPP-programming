#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
 private:
  string fullName;
  int age;
  string ID;
  int rentalDays;
  string roomType;

 public:
  // Constructor
  Customer(const string &name, int age, const string &id, int days,
           const string &type)
      : fullName(name), age(age), ID(id), rentalDays(days), roomType(type) {}

  // Destructor
  ~Customer() {}

  // Getters and Setters
  string getFullName() const;
  void setFullName(const string &name);

  int getAge() const;
  void setAge(int age);

  string getID() const;
  void setID(const string &id);

  int getRentalDays() const;
  void setRentalDays(int days);

  string getRoomType() const;
  void setRoomType(const string &type);

  // Method to get details
  string getDetails() const;
};

#endif  // CUSTOMER_H
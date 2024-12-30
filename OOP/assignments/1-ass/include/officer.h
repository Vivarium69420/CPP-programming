/*
 * ┌───────────────────────────────────┐
   │Officer                            │
   ├───────────────────────────────────┤
   │- name: String                     │
   │- age: Integer                     │
   │- gender: String                   │
   │- address: String                  │
   ├───────────────────────────────────┤
   │+ getName(): String                │
   │+ setName(name: String): void      │
   │+ getAge(): Integer                │
   │+ setAge(age: Integer): void       │
   │+ getGender(): String              │
   │+ setGender(gender: String): void  │
   │+ getAddress(): String             │
   │+ setAddress(address: String): void│
   └───────────────────────────────────┘
 * */

#ifndef OFFICER_H
#define OFFICER_H

#include "common.h"

class Officer {
 private:
  string name;
  int age;
  string gender;
  string address;

 public:
  Officer(const string &name, int age, const string &gender,
          const string &address)
      : name(name), age(age), gender(gender), address(address) {}

  string getName();
  void setName(string name);

  int getAge();
  void setAge(int age);

  void setGender(string gender);
  string getGender();

  void setAddress(string address);
  string getAddress();

  virtual void printDetails() = 0;
};

#endif  // !OFFICER_H

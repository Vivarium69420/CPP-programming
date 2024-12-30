/*
 * ┌───────────────────────────────────────────┐
 * │ Engineer                                  │
 * ├───────────────────────────────────────────┤
 * │ - speciality: String                      │
 * ├───────────────────────────────────────────┤
 * │ + getSpeciality(): String                 │
 * │ + setSpeciality(speciality: String): void │
 * └───────────────────────────────────────────┘
 * */

#ifndef ENGINEER_H
#define ENGINEER_H

#include "common.h"
#include "officer.h"

class Engineer : public Officer {
 private:
  string speciality;

 public:
  Engineer(const string &name, int age, const string &gender,
           const string &address, const string &speciality)
      : Officer(name, age, gender, address), speciality(speciality) {}

  string getSpeciality();
  void setSpeciality(string speciality);

  void printDetails() override;
};

#endif  // !ENGINEER_H

/*
 * ┌───────────────────────────────┐
 * │ Staff                         │
 * ├───────────────────────────────┤
 * │ - task: String                │
 * ├───────────────────────────────┤
 * │ + getTask(): String           │
 * │ + setTask(task: String): void │
 * └───────────────────────────────┘
 * */

#ifndef STAFF_H
#define STAFF_H

#include "common.h"
#include "officer.h"
class Staff : public Officer {
 private:
  string task;

 public:
  Staff(const string& name, int age, const string& gender,
        const string& address, const string& task)
      : Officer(name, age, gender, address), task(task) {}

  string getTask();
  void setTask(string task);

  void printDetails() override;
};

#endif  // STAFF_H
#ifndef OFFICER_MANAGER_H
#define OFFICER_MANAGER_H

#include <iostream>
#include <limits>
#include <list>
#include <string>

#include "common.h"
#include "engineer.h"
#include "officer.h"
#include "staff.h"
#include "worker.h"

class OfficerManager {
 private:
  list<Officer *> officers;
  void add(Officer *officer);
  Officer *searchByName(const string &name);
  void showList();

 public:
  int getValidIntInput(int min, int max);
  void addOfficer();
  void showOfficerList();
  void searchOfficerByName();
};

#endif  // OFFICER_MANAGER_H
/*
 * ┌─────────────────────────────────────┐
 * │OfficerManager                       │
 * ├─────────────────────────────────────┤
 * │- officers: List<Officer>            │
 * ├─────────────────────────────────────┤
 * │+ add(officer: Officer): void        │
 * │+ searchByName(name: String): Officer│
 * │+ showList(): void                   │
 * └─────────────────────────────────────┘
 * */

#ifndef OFFICER_MANAGER_H
#define OFFICER_MANAGER_H

#include <iostream>
#include <list>

#include "common.h"
#include "engineer.h"
#include "officer.h"
#include "staff.h"
#include "worker.h"

class OfficerManager {
private:
  list<Officer *> officers;

public:
  void add(Officer *officer);
  Officer *searchByName(const string &name);
  void showList();
};

#endif // OFFICER_MANAGER_H

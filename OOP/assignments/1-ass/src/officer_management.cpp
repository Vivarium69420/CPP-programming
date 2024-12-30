#include "../include/officer_management.h"

void OfficerManager::add(Officer *officer) { officers.push_back(officer); }

void OfficerManager::showList() {
  for (const auto &officer : officers) {
    officer->printDetails();
  }
}

Officer *OfficerManager::searchByName(const string &name) {
  for (auto it = officers.begin(); it != officers.end(); ++it) {
    if ((*it)->getName() == name) {
      return *it;
    }
  }
  return 0;
}

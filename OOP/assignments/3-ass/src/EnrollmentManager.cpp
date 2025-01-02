#include "../include/EnrollmentManager.h"

#include <iostream>
#include <limits>

EnrollmentManager::EnrollmentManager() {
  // Initialize shared instances of exam groups
  auto groupA = std::make_shared<GroupA>();
  auto groupB = std::make_shared<GroupB>();
  auto groupC = std::make_shared<GroupC>();

  // Add shared instances to the examGroups list
  examGroups.push_back(groupA);
  examGroups.push_back(groupB);
  examGroups.push_back(groupC);
}

EnrollmentManager::~EnrollmentManager() {}

void EnrollmentManager::add(std::shared_ptr<Candidate> candidate) {
  candidates.push_back(candidate);
}

void EnrollmentManager::display() {
  for (const auto &candidate : candidates) {
    candidate->display();
  }
}

void EnrollmentManager::searchByCandidateRegistrationNumber(
    const std::string &regNumber) {
  for (const auto &candidate : candidates) {
    if (candidate->getRegistrationNumber() == regNumber) {
      candidate->display();
      return;
    }
  }
  std::cout << "Candidate not found\n";
}

std::shared_ptr<ExamGroup> EnrollmentManager::findExamGroup(group_t group) {
  for (const auto &examGroup : examGroups) {
    if (examGroup->getGroup() == group) {
      return examGroup;
    }
  }
  return nullptr;  // or handle the case where the group is not found
}

void EnrollmentManager::displayExamGroup(group_t group) {
  for (const auto &examGroup : examGroups) {
    if (examGroup->getGroup() == group) {
      std::cout << "Exam Group "
                << static_cast<char>('A' + static_cast<int>(group))
                << " (Reference Count: " << examGroup.use_count() << "): ";
      for (const auto &exam : examGroup->getExams()) {
        std::cout << exam << " ";
      }
      std::cout << "\n";
    }
  }
}

int EnrollmentManager::getValidIntInput(int min, int max) {
  int input;
  while (true) {
    std::cin >> input;
    if (std::cin.fail() || input < min || input > max) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number between " << min
                << " and " << max << ": ";
    } else {
      break;
    }
  }
  return input;
}

void EnrollmentManager::addCandidate() {
  std::string regNum, fullName, address;
  int priorityLevel;
  std::shared_ptr<ExamGroup> examGroup;

  std::cout << "Enter registration number: ";
  std::cin >> regNum;
  std::cout << "Enter full name: ";
  std::cin.ignore();
  std::getline(std::cin, fullName);
  std::cout << "Enter address: ";
  std::getline(std::cin, address);
  std::cout << "Enter priority level: ";
  priorityLevel = getValidIntInput(1, 10);

  std::cout << "Select exam group (A/B/C): ";
  char group;
  std::cin >> group;
  switch (group) {
    case 'A':
      examGroup = findExamGroup(group_t::A);
      break;
    case 'B':
      examGroup = findExamGroup(group_t::B);
      break;
    case 'C':
      examGroup = findExamGroup(group_t::C);
      break;
    default:
      std::cout << "Invalid group selected. Defaulting to Group A.\n";
      examGroup = findExamGroup(group_t::A);
      break;
  }

  auto candidate = std::make_shared<Candidate>(regNum, fullName, address,
                                               priorityLevel, examGroup);
  add(candidate);
}

void EnrollmentManager::searchCandidate() {
  std::string regNum;
  std::cout << "Enter registration number to search: ";
  std::cin >> regNum;
  searchByCandidateRegistrationNumber(regNum);
}

void EnrollmentManager::showCandidateList() { display(); }

void EnrollmentManager::showExamGroup() {
  std::string group;
  std::cout << "Enter exam group to display (A/B/C): ";
  std::cin >> group;
  if (group == "A") {
    displayExamGroup(group_t::A);
  } else if (group == "B") {
    displayExamGroup(group_t::B);
  } else if (group == "C") {
    displayExamGroup(group_t::C);
  } else {
    std::cout << "Invalid group\n";
  }
}

void EnrollmentManager::addExamGroup(std::shared_ptr<ExamGroup> examGroup) {
  examGroups.push_back(examGroup);
}
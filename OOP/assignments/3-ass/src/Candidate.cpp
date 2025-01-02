#include "../include/Candidate.h"

std::string Candidate::getRegistrationNumber() const {
  return registrationNumber;
}

void Candidate::setRegistrationNumber(const std::string &regNumber) {
  registrationNumber = regNumber;
}

std::string Candidate::getFullName() const { return fullName; }

void Candidate::setFullName(const std::string &name) { fullName = name; }

std::string Candidate::getAddress() const { return address; }

void Candidate::setAddress(const std::string &addr) { address = addr; }

int Candidate::getPriorityLevel() const { return priorityLevel; }

void Candidate::setPriorityLevel(int priority) { priorityLevel = priority; }

std::shared_ptr<ExamGroup> Candidate::getExamGroup() const { return examGroup; }

void Candidate::setExamGroup(std::shared_ptr<ExamGroup> group) {
  examGroup = group;
}

void Candidate::display() const {
  std::cout << "Registration Number: " << registrationNumber << "\n"
            << "Full Name: " << fullName << "\n"
            << "Address: " << address << "\n"
            << "Priority Level: " << priorityLevel << "\n"
            << "Exam Group: ";
  for (const auto &exam : examGroup->getExams()) {
    std::cout << exam << " ";
  }
  std::cout << "\n";
}
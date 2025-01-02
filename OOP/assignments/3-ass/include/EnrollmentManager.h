#ifndef ENROLLMENT_MANAGER_H
#define ENROLLMENT_MANAGER_H

#include <list>
#include <memory>
#include <vector>

#include "Candidate.h"
#include "ExamGroup.h"
#include "GroupA.h"
#include "GroupB.h"
#include "GroupC.h"
#include "common.h"

class EnrollmentManager {
 private:
  std::list<std::shared_ptr<Candidate>> candidates;
  std::list<std::shared_ptr<ExamGroup>> examGroups;

  std::shared_ptr<ExamGroup> findExamGroup(group_t group);

  void add(std::shared_ptr<Candidate> candidate);
  void display();
  void searchByCandidateRegistrationNumber(const std::string &regNumber);

 public:
  EnrollmentManager();
  ~EnrollmentManager();

  void displayExamGroup(group_t group);
  int getValidIntInput(int min, int max);
  void addCandidate();
  void searchCandidate();
  void showCandidateList();
  void showExamGroup();
  void addExamGroup(std::shared_ptr<ExamGroup> examGroup);
};

#endif  // ENROLLMENT_MANAGER_H
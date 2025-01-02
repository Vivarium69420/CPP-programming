#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <memory>

#include "ExamGroup.h"
#include "common.h"

class Candidate {
 private:
  std::string registrationNumber;
  std::string fullName;
  std::string address;
  int priorityLevel;
  std::shared_ptr<ExamGroup> examGroup;

 public:
  Candidate(const std::string &regNum, const std::string &fn,
            const std::string &a, int lv, std::shared_ptr<ExamGroup> grp)
      : registrationNumber(regNum),
        fullName(fn),
        address(a),
        priorityLevel(lv),
        examGroup(grp) {}

  ~Candidate() {}

  // Getter and Setter for registrationNumber
  std::string getRegistrationNumber() const;
  void setRegistrationNumber(const std::string &regNumber);

  // Getter and Setter for fullName
  std::string getFullName() const;
  void setFullName(const std::string &name);

  // Getter and Setter for address
  std::string getAddress() const;
  void setAddress(const std::string &addr);

  // Getter and Setter for priorityLevel
  int getPriorityLevel() const;
  void setPriorityLevel(int level);

  // Getter and Setter for examGroup
  std::shared_ptr<ExamGroup> getExamGroup() const;
  void setExamGroup(std::shared_ptr<ExamGroup> group);

  // Display method
  void display() const;
};

#endif  // CANDIDATE_H
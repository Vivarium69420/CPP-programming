#ifndef EXAM_GROUP_H
#define EXAM_GROUP_H

#include <string>
#include <vector>

#include "common.h"

class ExamGroup {
 protected:
  std::vector<std::string> exams;

 public:
  virtual ~ExamGroup() = default;

  const std::vector<std::string>& getExams() const { return exams; }
  virtual group_t getGroup() const = 0;
};

#endif  // EXAM_GROUP_H
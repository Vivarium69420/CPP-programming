#ifndef GROUP_B_H
#define GROUP_B_H

#include "ExamGroup.h"

class GroupB : public ExamGroup {
 public:
  GroupB() { exams = {"Math", "Chemistry", "Biology"}; }
  group_t getGroup() const override { return group_t::B; }
};

#endif  // GROUP_B_H
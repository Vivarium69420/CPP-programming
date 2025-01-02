#ifndef GROUP_A_H
#define GROUP_A_H

#include "ExamGroup.h"

class GroupA : public ExamGroup {
 public:
  GroupA() { exams = {"Math", "Physics", "Chemistry"}; }
  group_t getGroup() const override { return group_t::A; }
};

#endif  // GROUP_A_H
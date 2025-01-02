#ifndef GROUP_C_H
#define GROUP_C_H

#include "ExamGroup.h"

class GroupC : public ExamGroup {
 public:
  GroupC() { exams = {"Literature", "History", "Geography"}; }
  group_t getGroup() const override { return group_t::C; }
};

#endif  // GROUP_C_H
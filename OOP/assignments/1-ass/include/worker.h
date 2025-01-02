#ifndef WORKER_H
#define WORKER_H

#include "common.h"
#include "officer.h"
class Worker : public Officer {
 private:
  int level;

 public:
  Worker(const string& name, int age, const string& gender,
         const string& address, int level)
      : Officer(name, age, gender, address), level(level) {}
  int getLevel();
  void setLevel(int level);

  void printDetails() override;
};

#endif  // WORKER_H
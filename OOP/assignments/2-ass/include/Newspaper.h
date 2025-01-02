#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "Document.h"

class Newspaper : public Document {
 private:
  int publicationDay;

 public:
  // Constructor
  Newspaper(string id, string ps, int cnt, int day)
      : Document(id, ps, cnt), publicationDay(day) {}

  // Destructor
  ~Newspaper() {}

  int getPublicationDay();
  void setPublicationDay(int pd);

  void display() override;
  doc_t getType() override;
};

#endif  // !NEWSPAPER_H
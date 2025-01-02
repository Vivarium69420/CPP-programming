#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Document.h"
class Magazine : public Document {
 private:
  int issueNumber;
  int publicationMonth;

 public:
  // Constructor
  Magazine(string id, string ps, int cnt, int issue, int month)
      : Document(id, ps, cnt), issueNumber(issue), publicationMonth(month) {}

  // Destructor
  ~Magazine() {}

  int getIssueNumber();
  void setIssueNumber(int in);

  int getPublicationMonth();
  void setPublicationMonth(int pm);

  void display() override;
  doc_t getType() override;
};

#endif  // !MAGAZINE_H

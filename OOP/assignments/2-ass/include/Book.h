#ifndef BOOK_H
#define BOOK_H

#include "Document.h"
#include "common.h"

class Book : public Document {
 private:
  string authorName;
  int pageCount;

 public:
  // Constructor
  Book(string id, string ps, int cnt, string author, int pages)
      : Document(id, ps, cnt), authorName(author), pageCount(pages) {}

  // Destructor
  ~Book() {}

  string getAuthorName();
  void setAuthorName(string n);

  int getPageCount();
  void setPageCount(int cnt);

  void display() override;
  doc_t getType() override;
};

#endif  // !BOOK_H

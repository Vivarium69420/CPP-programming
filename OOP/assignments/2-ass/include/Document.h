#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "common.h"
class Document {
 private:
  string documentId;
  string publisher;
  int copiesCount;

 public:
  // Constructor
  Document(string id, string ps, int cnt)
      : documentId(id), publisher(ps), copiesCount(cnt) {}

  // Destructor
  virtual ~Document() {}

  string getDocId();
  void setDocId(string id);

  string getPublisher();
  void setPublisher(string ps);

  int getCopiesCount();
  void setCopiesCount(int cnt);

  virtual void display() = 0;
  virtual doc_t getType() = 0;
};

#endif  // !DOCUMENT_H

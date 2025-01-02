#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include <list>
#include <memory>
#include <string>

#include "Document.h"
#include "common.h"

class LibraryManager {
 private:
  std::list<std::shared_ptr<Document>> documents;

  void addDoc(std::shared_ptr<Document> doc);
  void deleteDoc(const std::string &docId);
  void searchByDocType(doc_t type);
  void showList();
  int getValidIntInput(int min, int max);

 public:
  // Constructor
  LibraryManager() {}

  // Destructor
  ~LibraryManager() {}

  void addDocument();
  void deleteDocument();
  void searchDocument();
  void showDocumentList();
};

#endif  // LIBRARY_MANAGER_H
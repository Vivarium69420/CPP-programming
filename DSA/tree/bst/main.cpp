#include "bst.h"

int main(int argc, char *argv[]) {
  BST<int> bst;
  bst.insert(12);
  bst.insert(4);
  bst.insert(29);

  bst.breadthFirst();
  int *result = bst.search(12);
  cout << *result << endl;

  bst.findAndDeleteByMerging(12);
  bst.breadthFirst();

  return 0;
}

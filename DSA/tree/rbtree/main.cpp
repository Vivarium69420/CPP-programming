#include "rbtree.h"

void testLeftRotation() {
  RBT<int> tree;

  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(35);
  tree.insert(45);

  cout << "Tree before left rotation:" << endl;
  tree.printTree(tree.root);
  cout << endl;

  // Perform left rotation on node with value 30
  RBNode<int> *node = tree.root;
  tree.rotateLeft(node);

  cout << "Tree after left rotation:" << endl;
  tree.printTree(tree.root);
  cout << "-----------------------------------------" << endl;
  cout << endl;
}

void testRightRotation() {
  RBT<int> tree;

  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(10);
  tree.insert(25);

  cout << "Tree before right rotation:" << endl;
  tree.printTree(tree.root);
  cout << endl;

  // Perform right rotation on node with value 30
  RBNode<int> *node = tree.root;
  tree.rotateRight(node);

  cout << "Tree after right rotation:" << endl;
  tree.printTree(tree.root);
  cout << "-----------------------------------------" << endl;
  cout << endl;
}

void testClearAndInsert() {
  RBT<int> tree;

  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(10);
  tree.insert(25);

  cout << "Tree before clearing:" << endl;
  tree.printTree(tree.root);
  cout << endl;

  tree.clear();

  cout << "Tree after clearing:" << endl;
  tree.printTree(tree.root);
  cout << endl;

  tree.insert(50);
  tree.insert(60);

  cout << "Tree after inserting new nodes:" << endl;
  tree.printTree(tree.root);
  cout << "-----------------------------------------" << endl;
  cout << endl;
}

void testFixInsert() {
  RBT<int> tree;

  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(10);
  tree.insert(25);
  tree.insert(35);
  tree.insert(45);
  tree.insert(5);
  tree.insert(4);
  tree.insert(7);
  tree.insert(50);
  tree.insert(42);
  tree.insert(60);
  cout << "Tree after inserting " << endl;
  tree.printTree(tree.root);
}

int main() {
  // testClearAndInsert();
  // testLeftRotation();
  // testRightRotation();

  testFixInsert();

  return 0;
}

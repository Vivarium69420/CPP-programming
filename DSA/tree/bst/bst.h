#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <deque>
#include <iostream>
#include <queue>
using namespace std;

template <class T> class Queue : public queue<T, deque<T>> {
public:
  T dequeue() {
    T tmp = queue<T, deque<T>>::front();
    queue<T, deque<T>>::pop();
    return tmp;
  }
  void enqueue(const T &el) { queue<T, deque<T>>::push(el); }
  bool isEmpty() { return queue<T, deque<T>>::empty(); }
};

template <class T> class BSTNode {
public:
  BSTNode() { left = right = 0; }
  BSTNode(const T &e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
    el = e;
    left = l;
    right = r;
  }

  BSTNode<T> *left, *right;
  T el;
};

template <class T> class BST {
public:
  BST() { root = 0; }
  ~BST() {
    clear(root);
    root = 0;
  }
  void insert(const T &);
  T *search(const T &);
  void findAndDeleteByMerging(const T &);
  void breadthFirst();

protected:
  BSTNode<T> *root;
  void deleteByMerging(BSTNode<T> *&node);
  virtual void visit(BSTNode<T> *p) { cout << p->el << ' '; }
};

template <typename T> void BST<T>::insert(const T &el) {
  BSTNode<T> *p = root, *prev;
  while (p != 0) {
    prev = p; // Keeping the parent in each iteration
    if (el < p->el)
      p = p->left;
    else
      p = p->right;
  }
  if (root == 0)
    root = new BSTNode<T>(el);
  else if (el < prev->el)
    prev->left = new BSTNode<T>(el);
  else
    prev->right = new BSTNode<T>(el);
}

template <typename T> T *BST<T>::search(const T &el) {
  BSTNode<T> *p = root;
  while (p != 0) {
    if (el == p->el)
      return &p->el;
    else if (el < p->el)
      p = p->left;
    else
      p = p->right;
  }
  return 0;
}

template <typename T> void BST<T>::deleteByMerging(BSTNode<T> *&node) {
  BSTNode<T> *tmp = node;
  if (node != 0) {
    if (!node->right)
      node = node->left;
    else if (node->left == 0)
      node = node->right;
    else {
      tmp = node->left;       // Move left
      while (tmp->right != 0) // Find the last node in the right tree
        tmp = tmp->right;

      tmp->right = node->right; // Attach the rightmost node of the left
                                // subtree and the right subtree
      tmp = node;               // Point back to the original before deletion
      node = node->left;        // Attach the first left node as the new parent
    }
    delete tmp;
  }
}

template <typename T> void BST<T>::findAndDeleteByMerging(const T &el) {
  BSTNode<T> *node = root, *prev = 0;
  // Find where the node to be delete is
  while (node != 0) {
    if (node->el == el)
      break;
    prev = node;
    if (el < node->el)
      node = node->left;
    else
      node = node->right;
  }
  if (node != 0 && node->el == el) {
    if (node == root)
      deleteByMerging(root);
    else if (prev->left == node)
      deleteByMerging(prev->left);
    else
      deleteByMerging(prev->right);
  } else if (root != 0)
    cout << "element" << el << "is not in the tree\n";
  else
    cout << "the tree is empty\n";
}

template <typename T> void BST<T>::breadthFirst() {
  Queue<BSTNode<T> *> queue;
  BSTNode<T> *p = root;
  if (p != 0) {
    queue.enqueue(p);
    while (!queue.isEmpty()) {
      p = queue.dequeue();
      visit(p);
      if (p->left != 0)
        queue.enqueue(p->left);
      if (p->right != 0)
        queue.enqueue(p->right);
    }
  }
  cout << endl;
}

#endif // BINARY_SEARCH_TREE_H

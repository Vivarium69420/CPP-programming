/* Red-Black Tree (RBT)
 * @properties
 * 1. Every node is either red or black.
 * 2. All NIL nodes are considered black.
 * 3. A red node does not have a red child
 *    (no two consecutive red nodes on any path).
 * 4. Every path from a given node to any of its descendant NIL
 *    nodes goes through the same number of black nodes
 * 5. If a node N has exactly one child, the child must be red,
 *    because if it were black, its NIL descendant would sit at a
 *    different black depth than N's NIL child violating 4.
 * 6. The root is always black (depends)
 * -> The path from the root to the farthest leaf is no more than
 *    twice as long as the path from the root to the nearest leaf
 * */
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <queue>
using namespace std;

typedef enum { BLACK, RED } color_t;

template <class T>
class RBNode {
 public:
  RBNode() { parent = left = right = 0; }

  RBNode(const T &el, color_t c = RED, RBNode<T> *par = 0, RBNode<T> *l = 0,
         RBNode<T> *r = 0)
      : el(el), color(c), parent(par), left(l), right(r) {}

  RBNode<T> *parent, *left, *right;
  color_t color;
  T el;
};

template <class T>
class RBT {
 public:
  RBNode<T> *root;
  RBT() { root = 0; }
  ~RBT() { clear(); }

  void rotateRight(RBNode<T> *&node);
  void rotateLeft(RBNode<T> *&node);
  void insert(const T &value);

  void fixInsertion(RBNode<T> *&node);

  void printTree(RBNode<T> *root, int space = 0, int height = 10);
  void clearTree(RBNode<T> *node);
  void swapColor(RBNode<T> *a, RBNode<T> *b);
  void clear() {
    clearTree(root);
    root = 0;
  }
};

template <class T>
void RBT<T>::insert(const T &value) {
  RBNode<T> *newNode = new RBNode<T>(value);
  RBNode<T> *p = root, *prev = 0;

  while (p) {
    prev = p;
    if (p->el < value)
      p = p->right;
    else
      p = p->left;
  }

  newNode->parent = prev;
  if (prev == 0)
    root = newNode;
  else if (prev->el < value)
    prev->right = newNode;
  else
    prev->left = newNode;

  fixInsertion(newNode);
}

/* Case 1: Root node is BLACK
 * Case 2: Parent of new node is BLACK -> Do nothing
 * Case 3: Parent of new node is RED
 *    1. Recolor parent and uncle to BLACK
 *    2. Recolor grandparent to RED
 *    3. Move up to grandparent and repeat check
 *       -> Loop till the root is met
 * Case 4: Parent of new node is RED, Uncle is NIL or BLACK
 *    4.a. Left Left (LL): The new node is the left child of
 *         the left parent
 *      a.1. Right rotation on grandparent
 *      a.2. Swap color of parent and grandparent
 *   4.b. Left Right (LR): The new node is the right child of
 *        the left parent
 *     b.1. Left rotation on parent
 *     b.2. Handle as 4.a
 *   4.c. Right Right (RR): The new node is the right child of
 *        the right parent
 *     c.1. Left rotation on grandparent
 *     c.2. Swap color of parent and grandparent
 *   4.d. Right Left (RL): The new node is the left child of
 *        the right parent
 *     d.1. Right rotation on parent
 *     d.2. Handle as 4.c
 *
 * Note:
 *    - Case 1 is handled at the end of function, as exist a case
 *      where the node is child of root, root does not have a parent
 *      hence grandparent is null -> exit loop and recolor root to BLACK
 *    - Case 4.b after the left rotation, the node becomes the parent
 *      and the parent becomes the child. We need to update the pointer
 *      inside the loop, since the rotateLeft function only updates the
 *      local copy of the pointer to manipulate the tree.4e-=9
 *
 * Abbreviations:
 *    RN: Right node
 *    LN: Left node
 * */
template <class T>
void RBT<T>::fixInsertion(RBNode<T> *&node) {
  RBNode<T> *gr = 0;   // Grandparent
  RBNode<T> *par = 0;  // Parent
  RBNode<T> *unc = 0;  // Uncle

  // Case 2
  while (node != root && node->parent->color == RED) {
    par = node->parent;
    gr = par->parent;
    if (!gr) break;  // no grandparent, child of root
    cout << "Node: " << node->el << " Parent: " << par->el
         << " Grandparent: " << gr->el << endl;

    if (par == gr->left) {  // Par is the LN of Gr
      unc = gr->right;      // Unc will be the RN of Gr
      if (unc && unc->color == RED) {
        par->color = BLACK;
        unc->color = BLACK;
        gr->color = RED;
        node = gr;
      } else {
        // Case 4.b
        if (node == par->right) {
          rotateLeft(par);
          node = par;  // After rotation, node becomes par as par now becomes ch
          par = node->parent;  // Change par to the parent of node
        }
        // Case 4.a
        rotateRight(gr);
        swapColor(par, gr);
      }
    } else {
      unc = gr->left;  // Par is the RN of GR
      if (unc && unc->color == RED) {
        par->color = BLACK;
        unc->color = BLACK;
        gr->color = RED;
        node = gr;
      } else {
        // Case 4.d
        if (node == par->left) {
          rotateRight(par);
          node = par;
          par = node->parent;
        }
        // Case 4.c
        rotateLeft(gr);
        swapColor(par, gr);
      }
    }
  }

  // Case 1
  root->color = BLACK;
}

template <class T>
void RBT<T>::printTree(RBNode<T> *root, int space, int height) {
  if (root == 0) return;

  space += height;

  printTree(root->right, space, height);

  cout << endl;
  for (int i = height; i < space; i++) cout << " ";
  cout << root->el << " " << (root->color == RED ? "R" : "B") << endl;

  printTree(root->left, space, height);
}

template <class T>
void RBT<T>::clearTree(RBNode<T> *node) {
  if (node) {
    clearTree(node->left);
    clearTree(node->right);
    delete node;
  }
}

template <class T>
void RBT<T>::swapColor(RBNode<T> *a, RBNode<T> *b) {
  color_t temp = a->color;
  a->color = b->color;
  b->color = temp;
}

/* rotateRight(Gr, Par, Ch)
 *       if Par is not the root of the tree // i.e., if Gr is not null
 *              grandparent Gr of child Ch becomes Ch's parent;
 *       right subtree of Ch become left subtree of Ch's parent Par;
 *       node Ch acquires Par as its right child;
 * */
template <class T>
void RBT<T>::rotateRight(RBNode<T> *&node) {
  RBNode<T> *ch = node->left;
  RBNode<T> *gr = node->parent;
  RBNode<T> *par = node;

  if (gr) {
    if (gr->left == par)  // if Par is the left child of Gr
      gr->left = ch;
    else
      gr->right = ch;
  } else
    root = ch;  // if Par is the root of the tree

  if (ch->right) {
    par->left = ch->right;    // Ch's right subtree become left subtree of Par
    ch->right->parent = par;  // Par becomes parent of Ch's right subtree
  } else
    par->left = 0;

  ch->right = par;  // node Ch acquires Par as its right child
  par->parent = ch;
  ch->parent = gr;
}

/* rotateLeft(Gr, Par, Ch)
 *       if Par is not the root of the tree // i.e., if Gr is not null
 *              grandparent Gr of child Ch becomes Ch's parent;
 *       left subtree of Ch become right subtree of Ch's parent Par;
 *       node Ch acquires Par as its left child;
 * */
template <class T>
void RBT<T>::rotateLeft(RBNode<T> *&node) {
  RBNode<T> *ch = node->right;
  RBNode<T> *gr = node->parent;
  RBNode<T> *par = node;

  if (gr) {
    if (gr->left == par)
      gr->left = ch;
    else
      gr->right = ch;
  } else
    root = ch;

  if (ch->left) {
    par->right = ch->left;
    ch->left->parent = par;
  } else
    par->right = 0;

  ch->left = par;
  par->parent = ch;
  ch->parent - gr;
}

#endif  // RED_BLACK_TREE_H

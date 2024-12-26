#include <iostream>

/* Linked list DST
 * 1. Create a node structure: next pointer, data
 * 2. Create a list structure to hold nodes, with operations follows:
 *  - Init
 *  - addToHead
 *  - addToTail
 *  - deleteFromHead
 *  - deleteFromTail
 *  - deleteNode
 *  - isInList
 *
 * */

using namespace std;

/* Structure for a node */
class IntSLLNode {
public:
  IntSLLNode() { next = 0; }

  IntSLLNode(int el, IntSLLNode *next = 0) {
    this->info = el;
    this->next = next;
  }

  int info;
  IntSLLNode *next;
};

class IntSLLList {
private:
  // Two constant pointer to head and tail
  IntSLLNode *tail;
  IntSLLNode *head;

public:
  IntSLLList() { head = tail = 0; }
  ~IntSLLList();
  int isEmpty() { return head == 0; }

  void addToHead(int);
  void addToTail(int);
  int deleteFromHead();
  int deleteFromTail();
  void deleteNode(int);
  bool isInList(int) const;
  void transverseFromHead();
};

IntSLLList::~IntSLLList() {
  for (IntSLLNode *p; !isEmpty();) {
    p = head->next;
    delete head;
    head = p;
  }
}

void IntSLLList::addToHead(int el) {
  // Create a new head, and the set the next pointer to the old head
  head = new IntSLLNode(el, head);
  if (tail == 0)
    tail = head;
}

void IntSLLList::addToTail(int el) {
  if (tail != 0) {
    // The old tail next is now the new node
    tail->next = new IntSLLNode(el);
    // new tail
    tail = tail->next;
  }
}

int IntSLLList::deleteFromHead() {
  int el = head->info;
  IntSLLNode *temp = head;
  if (head == tail) // only one node
    head = tail = 0;
  else
    head = head->next;
  delete temp;
  return el;
}

int IntSLLList::deleteFromTail() {
  int el = tail->info;
  if (head == tail) {
    delete head;
    head = tail = 0;
  } else {
    IntSLLNode *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next)
      ;
    delete tail;
    tail = tmp;
    tail->next = 0;
  }
  return el;
}

void IntSLLList::deleteNode(int el) {
  if (head != 0) {                          // not empty
    if (head == tail && el == head->info) { // only one node
      delete head;
      head = tail = 0;
    } else if (el == head->info) { // two node, head -> tail
      IntSLLNode *tmp = head;
      head = head->next;
      delete tmp;
    } else {
      IntSLLNode *pred, *tmp;
      /* pred: predecesor, tmp: temporary
       * pred is one node behind temp
       * transverse through the list using tmp to find the node to be deleted
       * make sure that we doesn't meet the end of the list also
       * */
      for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);
           pred = pred->next, tmp = tmp->next)
        ;
      if (tmp != 0) {
        pred->next = tmp->next;
        if (tmp == tail) // two node, head -> tail
          tail = pred;
        delete tmp;
      }
    }
  }
}

void IntSLLList::transverseFromHead() {
  IntSLLNode *temp = head;
  while (temp != tail->next) {
    cout << temp->info << " -> ";
    temp = temp->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  IntSLLList list;
  list.addToHead(1);
  list.addToTail(2);
  list.transverseFromHead();

  cout << "Remove from head: " << list.deleteFromHead() << endl;
  list.transverseFromHead();
  list.addToHead(3);
  list.addToHead(4);

  cout << "Remove from tail: " << list.deleteFromTail() << endl;
  list.transverseFromHead();

  return 0;
}

template <class T> class DLLNode {
public:
  DLLNode() { next = prev = 0; }
  DLLNode(const T &el, DLLNode *n = 0, DLLNode *p = 0) {
    info = el;
    next = n;
    prev = p;
  }

  T info;
  DLLNode *next, *prev;
};

template <class T> class DoublyLinkedList {
public:
  DoublyLinkedList() { head = tail = 0; }
  ~DoublyLinkedList();
  int isEmpty() { return head == 0; }
  void addToDLLHead(const T &);
  void addToDLLTail(const T &);
  T deleteFromDLLTail();
  T deleteFromDLLHead();
  void deleteDLLNode(const T &);
  bool isInList(const T &);

protected:
  int size;
  int capacity;
  DLLNode<T> *head, *tail;
};

template <class T> DoublyLinkedList<T>::~DoublyLinkedList() {
  for (DLLNode<T> *p; !isEmpty();) {
    p = head->next;
    delete head;
    head = p;
  }
}

template <class T> void DoublyLinkedList<T>::addToDLLTail(const T &el) {
  if (tail != 0) {
    tail = new DLLNode<T>(el, 0, tail);
    // The prev node of tail next is now the new tail
    tail->prev->next = tail;
  }
}

#ifndef __HEAP_H
#define __HEAP_H

template <typename T>
struct Node {
    T data;
    Node* l;
    Node* r;
    Node(T data) : data(data), l(nullptr), r(nullptr) {}
};

template <typename T>
class BST {
  private:
    Node<T>* root;
    bool isLeaf(Node<T>*) const;// finds if a node is a leaf
    void searchParent(Node<T>* arr[], const T&) const; // searches for a node and its parent
    int height(Node<T>*) const; // helper to height() and height(const t&)
    void preOrder(Node<T>*) const; // helper to preOrder()
    void inOrder(Node<T>*) const; // helper to inOrder()
    void postOrder(Node<T>*) const; // helper to postOrder

  public:
    BST(); // constructor
    void insert(const T&); // insert a new node
    Node<T>* search(const T&) const; // search for a node
    T largest() const; // find largest node
    T smallest() const; // find smallest node
    int height(const T&) const; // find height from a node
    int height() const; // find height from root
    void remove(const T&); // remove node
    void preOrder() const; // print preOrder notation
    void inOrder() const; // print inOrder notation
    void postOrder() const; // print postOrder notation
};
#endif
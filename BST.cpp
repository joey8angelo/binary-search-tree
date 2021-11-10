#include "BST.h"
#include <iostream>
#include <exception>

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
void BST<T>::insert(const T& data) {
    if (root == nullptr) { // insert as root
        root = new Node<T>(data);
    }
    else {
        Node<T>* curr = root;
        while (curr != nullptr) { // find next available opening that keeps BST rules
            if (curr->data > data) {
                if (curr->l == nullptr) {
                    curr->l = new Node<T>(data);
                    curr = nullptr;
                }
                else
                    curr = curr->l;
            }
            else {
                if (curr->r == nullptr) {
                    curr->r = new Node<T>(data);
                    curr = nullptr;
                }
                else
                    curr = curr->r;
            }
        }
    }
}

template <typename T>
Node<T>* BST<T>::search(const T& data) const {
    Node<T>* curr = root;
    while (curr != nullptr) {
        if (data == curr->data) {
            return curr;
        }
        else if (data < curr->data) {
            curr = curr->l;
        }
        else {
            curr = curr->r;
        }
    }
    return nullptr;
}

template <typename T>
void BST<T>::searchParent(Node<T>* arr[], const T& data) const {
    Node<T>* curr = root;
    Node<T>* par = nullptr;
    arr[0] = nullptr;
    arr[1] = nullptr;

    while (curr != nullptr) {
        if (data == curr->data) {
            arr[0] = curr;
            arr[1] = par;
            return;
        }
        else if (data < curr->data) {
            par = curr;
            curr = curr->l;
        }
        else {
            par = curr;
            curr = curr->r;
        }
    }
}

template <typename T>
T BST<T>::largest() const {
    Node<T>* curr = root;
    if (root == nullptr)
        throw std::out_of_range("Tree is empty");
    while (curr->r != nullptr) {
        curr = curr->r; // largest is the rightmost node
    }
    return curr->data;
}

template <typename T>
T BST<T>::smallest() const {
    Node<T>* curr = root;
    if (root == nullptr)
        throw std::out_of_range("Tree is empty");
    while (curr->l != nullptr) {
        curr = curr->l; // smallest is the leftmost node
    }
    return curr->data;
}

template <typename T>
int BST<T>::height(Node<T>* node) const {
    if (node == nullptr)
        return -1;
    else
    {
        //find depth of each subtree
        int lDepth = height(node->l);
        int rDepth = height(node->r);
     
        // return the larger one
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
template <typename T>
int BST<T>::height(const T& data) const {
    Node<T>* node = this->search(data); // starting at specified node
    return height(node);
}
template <typename T>
int BST<T>::height() const {
    return height(root); // starting at root
}

template <typename T>
void BST<T>::remove(const T& data) {
    Node<T>* arr[2];
    searchParent(arr, data);
    Node<T>* par = arr[1];
    Node<T>* curr = arr[0];

    while (curr != nullptr) {
        if (isLeaf(curr)) { // if the node is a leaf delete it and make its parent point to nullptr
            if (par == nullptr) { // root
                root = nullptr;
            }
            else if (par->r == curr) { // right
                par->r = nullptr;
            }
            else { // left
                par->l = nullptr;
            }
            delete curr;
            curr = nullptr;
        }
        else if (curr->r == nullptr) { // if node only has a left subtree everything in it is smaller than its parent
            if (par == nullptr) { // root
                root = curr->l;
            }
            else if (par->l == curr) { // right
                par->l = curr->l;
            }
            else { // left
                par->r = curr->l;
            }
            delete curr;
            curr = nullptr;
        }
        else if (curr->l == nullptr) { // is node only has a right subtree everything in it is larger than its parent
            if (par == nullptr) { // root
                root == curr->r;
            }
            else if (par->l == curr) { // right
                par->l = curr->r;
            }
            else { // left
                par->r = curr->r;
            }
            delete curr;
            curr = nullptr;
        }
        else {
            Node<T>* suc = curr->r;
            Node<T>* sucPar = curr;
            while (suc->l != nullptr) { // find the nodes successor, the leftmost node in the right subtree
                sucPar = suc;
                suc = suc->l;
            }
            T temp = suc->data; // save the successors data and delete it
            remove(suc->data);
            curr->data = temp; // make curr equal successor data
        }
        return;
    }
}

template <typename T>
void BST<T>::preOrder() const {
    preOrder(root);
}

template <typename T>
void BST<T>::preOrder(Node<T>* node) const {
    if (node == nullptr)
        return;
    else {
        std::cout << node->data << " ";
        preOrder(node->l);
        preOrder(node->r);
    }
}

template <typename T>
void BST<T>::inOrder() const {
    inOrder(root);
}

template <typename T>
void BST<T>::inOrder(Node<T>* node) const {
    if (node == nullptr)
        return;
    else {
        inOrder(node->l);
        std::cout << node->data << " ";
        inOrder(node->r);
    }
}

template <typename T>
void BST<T>::postOrder() const {
    postOrder(root);
}

template <typename T>
void BST<T>::postOrder(Node<T>* node) const {
    if (node == nullptr)
        return;
    else {
        postOrder(node->l);
        postOrder(node->r);
        std::cout << node->data << " ";
    }
}

template <typename T>
bool BST<T>::isLeaf(Node<T>* node) const {
    if (node == nullptr)
        throw std::out_of_range("Node is null");
    if (node->l == nullptr && node->r == nullptr)
        return true;
    else
        return false;
}
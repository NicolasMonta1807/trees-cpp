#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include "BinaryNode.h"

template <class T>
class Tree
{
protected:
  Node<T> *root;
  void preOrder(Node<T> *startNode);
  void postOrder(Node<T> *startNode);
  void inOrder(Node<T> *startNode);

public:
  Tree();
  Tree(T value);
  ~Tree();
  void setRoot(Node<T> *root);
  Node<T> *getRoot();
  bool isEmpty();
  int height();
  int height(Node<T> *startNode);
  unsigned int size();
  unsigned int size(Node<T> *startNode);
  bool insert(T value);
  bool insert(Node<T> *startNode, T value);
  bool remove(Node<T> *startNode, T value);
  Node<T> *find(T value);
  Node<T> *find(T value, Node<T> *startNode);
  void preOrder();
  void postOrder();
  void inOrder();
};

#include "BinaryTree.hxx"

#endif //__BINARY_TREE__
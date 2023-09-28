#ifndef _AVLTREE_H
#define _AVLTREE_H

#include "BinaryNode.h"

template <class T>
class AVLTree
{
private:
  Node<T> *root;

public:
  AVLTree();
  AVLTree(T value);
  ~AVLTree();
  void clear();
  bool isEmpty();
  int getSize();
  int getHeight();
  bool insert(T value);
  bool remove(T value);
  bool contains(T value);

private:
  int getSize(Node<T> *node);
  int getHeight(Node<T> *node);
  bool insert(Node<T> *node, T value);
  bool remove(Node<T> *node, T value);
  void balance();
  Node<T> *rotateLeft(Node<T> *node);
  Node<T> *rotateRight(Node<T> *node);
  bool contains(Node<T> *node, T value);
};

#include "AVLTree.hxx"

#endif // _AVLTREE_H

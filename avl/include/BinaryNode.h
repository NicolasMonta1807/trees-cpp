#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H

template <class T>
class Node
{
public:
  T value;
  Node<T> *parent;
  Node<T> *left;
  Node<T> *right;

public:
  Node();
  Node(T value);
  ~Node();
  T getValue();
  void setValue(T value);
  Node<T> *getParent();
  Node<T> *getLeft();
  Node<T> *getRight();
  void setParent(Node<T> *parent);
  void setLeft(Node<T> *left);
  void setRight(Node<T> *right);
};

#include "BinaryNode.hxx"

#endif // _BINARY_NODE_H

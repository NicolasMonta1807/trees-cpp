#ifndef __BINARY_NODE_H__
#define __BINARY_NODE_H__

template <class T>
class Node
{
protected:
  T value;
  Node<T> *father;
  Node<T> *left;
  Node<T> *right;

public:
  Node();
  Node(T value);
  ~Node();
  bool isLeaf();
  void setValue(T value);
  T getValue();
  void setFather(Node<T> *father);
  void setLeft(Node<T> *left);
  void setRight(Node<T> *right);
  Node<T> *getFather();
  Node<T> *getLeft();
  Node<T> *getRight();
};

#include "BinaryNode.hxx"

#endif //__BINARY_NODE_H__
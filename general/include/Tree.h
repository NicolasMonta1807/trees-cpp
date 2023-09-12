#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"

template <class T>
class Tree
{
protected:
  Node<T> *root;

public:
  Tree();
  Tree(T value);
  ~Tree();
  bool isEmpty();
  Node<T> *getRoot();
  void setRoot(Node<T> *root);
  bool addNode(T father, T value);
  bool addNode(Node<T> *startnode, T father, T value);
  bool removeNode(T value);
  bool removeNode(Node<T> *startNode, T value);
  bool findNode(T value);
  bool findNode(Node<T> *startNode, T value);
  unsigned int size();
  unsigned int size(Node<T> *startNode);
  int height();
  void preOrder();
  void preOrder(Node<T> *startNode);
  void postOrder();
  void postOrder(Node<T> *startNode);
};

#include "Tree.hxx"

#endif // __TREE_H__
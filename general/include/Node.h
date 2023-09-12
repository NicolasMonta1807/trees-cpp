#ifndef __NODE_H_
#define __NODE_H_

#include <list>

template <class T>
class Node
{
protected:
  T value;
  std::list<Node<T> *> children;

public:
  Node();
  Node(T value);
  ~Node();
  T &getValue();
  void setValue(T &value);
  void addChild(T &value);
  bool removeChild(T &value);
  void clearChildren();
  bool isLeaf();
  int height();
  typename std::list<Node<T> *>::iterator getChildrenBegin();
  typename std::list<Node<T> *>::iterator getChildrenEnd();
};

#include "Node.hxx"

#endif // __NODE_H_
#include "Node.h"

template <class T>
Node<T>::Node()
{
  this->children.clear();
}

template <class T>
Node<T>::Node(T value)
{
  this->value = value;
  this->children.clear();
}

template <class T>
Node<T>::~Node()
{
  typename std::list<Node<T> *>::iterator it;
  for (it = this->children.begin(); it != this->children.end(); it++)
  {
    delete *it;
  }
  this->children.clear();
}

template <class T>
T &Node<T>::getValue()
{
  return this->value;
}

template <class T>
void Node<T>::setValue(T &value)
{
  this->value = value;
}

template <class T>
void Node<T>::addChild(T &value)
{
  Node<T> *newNode = new Node<T>;
  newNode->setValue(value);
  this->children.push_back(newNode);
}

template <class T>
bool Node<T>::removeChild(T &value)
{
  typename std::list<Node<T> *>::iterator it;
  Node<T> *aux;
  for (it = this->children.begin(); it != this->children.end(); it++)
  {
    aux = *it;
    if (aux->getValue() == value)
      break;
  }

  if (it != this->children.end())
  {
    this->children.erase(it);
    delete *it;
    return true;
  }

  return false;
}

template <class T>
void Node<T>::clearChildren()
{
  this->children.clear();
}

template <class T>
bool Node<T>::isLeaf()
{
  return this->children.size() == 0;
}

template <class T>
int Node<T>::height()
{
  if (this->isLeaf())
  {
    return 0;
  }
  else
  {
    int height = 0;
    int childHeight = 0;
    typename std::list<Node<T> *>::iterator it;
    for (it = this->children.begin(); it != this->children.end(); it++)
    {
      childHeight = (*it)->height();
      if (height < childHeight + 1)
        height = childHeight + 1;
    }
    return height;
  }
}

template <class T>
typename std::list<Node<T> *>::iterator Node<T>::getChildrenBegin()
{
  return this->children.begin();
}

template <class T>
typename std::list<Node<T> *>::iterator Node<T>::getChildrenEnd()
{
  return this->children.end();
}
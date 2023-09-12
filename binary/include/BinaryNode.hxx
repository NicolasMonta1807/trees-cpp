#include "BinaryNode.h"

template <class T>
Node<T>::Node()
{
  this->father = nullptr;
  this->left = nullptr;
  this->right = nullptr;
}

template <class T>
Node<T>::Node(T value)
{
  this->value = value;
  this->father = nullptr;
  this->left = nullptr;
  this->right = nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
bool Node<T>::isLeaf()
{
  return (this->left == nullptr && this->right == nullptr);
}

template <class T>
void Node<T>::setValue(T value)
{
  this->value = value;
}

template <class T>
T Node<T>::getValue()
{
  return this->value;
}

template <class T>
void Node<T>::setFather(Node<T> *father)
{
  this->father = father;
}

template <class T>
void Node<T>::setLeft(Node<T> *left)
{
  this->left = left;
}

template <class T>
void Node<T>::setRight(Node<T> *right)
{
  this->right = right;
}

template <class T>
Node<T> *Node<T>::getFather()
{
  return this->father;
}

template <class T>
Node<T> *Node<T>::getLeft()
{
  return this->left;
}

template <class T>
Node<T> *Node<T>::getRight()
{
  return this->right;
}
#include <iostream>
#include "Tree.h"

template <class T>
Tree<T>::Tree()
{
  this->root = NULL;
}

template <class T>
Tree<T>::Tree(T value)
{
  this->root = new Node<T>(value);
}

template <class T>
Tree<T>::~Tree()
{
  delete this->root;
  this->root = NULL;
}

template <class T>
bool Tree<T>::isEmpty()
{
  return this->root == NULL;
}

template <class T>
Node<T> *Tree<T>::getRoot()
{
  return this->root;
}

template <class T>
void Tree<T>::setRoot(Node<T> *root)
{
  this->root = root;
}

template <class T>
bool Tree<T>::addNode(T father, T value)
{
  if (this->isEmpty())
  {
    Node<T> *root = new Node<T>(value);
    this->root = root;
    return true;
  }
  else if (this->root->getValue() == father)
  {
    this->root->addChild(value);
    return true;
  }
  else
  {
    return addNode(root, father, value);
  }
}

template <class T>
bool Tree<T>::addNode(Node<T> *startNode, T father, T value)
{
  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();

  for (; it != startNode->getChildrenEnd(); it++)
  {
    if ((*it)->getValue() == father)
    {
      (*it)->addChild(value);
      return true;
    }
    else
    {
      if (this->addNode((*it), father, value))
      {
        return true;
      }
    }
  }

  return false;
}

template <class T>
bool Tree<T>::removeNode(T value)
{
  if (this->isEmpty())
    return false;
  else
  {
    if (this->root->getValue() == value)
    {
      delete root;
      return true;
    }
    else
    {
      return this->removeNode(root, value);
    }
  }
}

template <class T>
bool Tree<T>::removeNode(Node<T> *startNode, T value)
{
  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();
  for (; it != startNode->getChildrenEnd(); it++)
  {
    if ((*it)->getValue() == value)
    {
      startNode->removeChild((*it)->getValue());
      return true;
    }
    else
    {
      if (this->removeNode((*it), value))
      {
        return true;
      }
    }
  }

  return false;
}

template <class T>
bool Tree<T>::findNode(T value)
{
  if (this->isEmpty())
  {
    return false;
  }

  return this->findNode(root, value);
}

template <class T>
bool Tree<T>::findNode(Node<T> *startNode, T value)
{
  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();
  for (; it != startNode->getChildrenEnd(); it++)
  {
    if ((*it)->getValue() == value)
    {
      return true;
    }
    else
    {
      if (this->findNode((*it), value))
      {
        return true;
      }
    }
  }

  return false;
}

template <class T>
unsigned int Tree<T>::size()
{
  if (this->isEmpty())
  {
    return 0;
  }
  return this->size(root) + 1;
}

template <class T>
unsigned int Tree<T>::size(Node<T> *startNode)
{
  unsigned int currentSize = 0;
  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();

  for (; it != startNode->getChildrenEnd(); it++)
  {
    if ((*it)->isLeaf())
    {
      currentSize += 1;
    }
    else
    {
      currentSize += this->size((*it)) + 1;
    }
  }

  return currentSize;
}

template <class T>
int Tree<T>::height()
{
  if (this->isEmpty())
  {
    return -1;
  }

  return this->root->height();
}

template <class T>
void Tree<T>::preOrder()
{
  if (!this->isEmpty())
    this->preOrder(this->root);
  std::cout << std::endl;
}

template <class T>
void Tree<T>::preOrder(Node<T> *startNode)
{
  std::cout << startNode->getValue() << " ";

  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();
  for (; it != startNode->getChildrenEnd(); it++)
    this->preOrder(*it);
}

template <class T>
void Tree<T>::postOrder()
{
  if (!this->isEmpty())
    this->postOrder(this->root);
  std::cout << this->root->getValue() << std::endl;
}

template <class T>
void Tree<T>::postOrder(Node<T> *startNode)
{
  typename std::list<Node<T> *>::iterator it = startNode->getChildrenBegin();

  for (; it != startNode->getChildrenEnd(); it++)
  {
    if ((*it)->isLeaf())
    {
      std::cout << (*it)->getValue() << " ";
    }
    else
    {
      this->postOrder(*it);
      std::cout << (*it)->getValue() << " ";
    }
  }
}
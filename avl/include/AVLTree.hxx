#include "AVLTree.h"

template <class T>
AVLTree<T>::AVLTree()
{
  this->root = NULL;
}

template <class T>
AVLTree<T>::AVLTree(T value)
{
  this->root = new Node<T>(value);
}

template <class T>
AVLTree<T>::~AVLTree()
{
  this->clear();
}

template <class T>
void AVLTree<T>::clear()
{
  while (this->root != NULL)
  {
    this->remove(this->root->getValue());
  }
}

template <class T>
bool AVLTree<T>::isEmpty()
{
  return this->root == NULL;
}

template <class T>
int AVLTree<T>::getSize()
{
  if (!this->isEmpty())
  {
    return this->getSize(this->root);
  }
  return 0;
}

template <class T>
int AVLTree<T>::getSize(Node<T> *node)
{
  if (node == NULL)
  {
    return 0;
  }
  return 1 + this->getSize(node->getLeft()) + this->getSize(node->getRight());
}

template <class T>
int AVLTree<T>::getHeight()
{
  if (!this->isEmpty())
  {
    return this->getHeight(this->root);
  }
  return 0;
}

template <class T>
int AVLTree<T>::getHeight(Node<T> *node)
{
  if (node == NULL)
  {
    return 0;
  }
  return 1 + std::max(this->getHeight(node->getLeft()), this->getHeight(node->getRight()));
}

template <class T>
bool AVLTree<T>::insert(T value)
{
  if (this->isEmpty())
  {
    this->root = new Node<T>(value);
    return true;
  }
  else
  {
    if (this->insert(this->root, value))
    {
      balance();
      return true;
    }
    return false;
  }
}

template <class T>
bool AVLTree<T>::insert(Node<T> *node, T value)
{
  if (node == nullptr)
  {
    node = new Node<T>(value);
    return true;
  }

  if (value < node->getValue())
  {
    if (node->getLeft() == nullptr)
    {
      node->setLeft(new Node<T>(value));
      node->getLeft()->setParent(node);
      return true;
    }
    else
    {
      return this->insert(node->getLeft(), value);
    }
  }
  else if (value > node->getValue())
  {
    if (node->getRight() == nullptr)
    {
      node->setRight(new Node<T>(value));
      node->getRight()->setParent(node);
      return true;
    }
    else
    {
      return this->insert(node->getRight(), value);
    }
  }
  else
  {
    return false;
  }
}

template <class T>
bool AVLTree<T>::remove(T value)
{
  if (!this->isEmpty())
  {
    if (this->remove(this->root, value))
    {
      balance();
      return true;
    }
    return false;
  }
  else
  {
    return false;
  }
}

template <class T>
bool AVLTree<T>::remove(Node<T> *node, T value)
{
  if (node == nullptr)
  {
    return false;
  }

  if (value > node->getValue())
  {
    return this->remove(node->getRight(), value);
  }
  else if (value < node->getValue())
  {
    return this->remove(node->getLeft(), value);
  }
  else
  {
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
      Node<T> *parent = node->getParent();
      if (parent != nullptr)
      {
        if (parent->getLeft() == node)
        {
          parent->setLeft(nullptr);
        }
        else
        {
          parent->setRight(nullptr);
        }
      }
      else
      {
        this->root = nullptr;
      }
      delete node;
      node = nullptr;
      return true;
    }
    else if (node->getLeft() == nullptr)
    {
      Node<T> *temp = node;
      node = node->getRight();
      node->setParent(temp->getParent());
      if (node->getParent() != nullptr)
      {
        if (node->getParent()->getLeft() == temp)
        {
          node->getParent()->setLeft(node);
        }
        else
        {
          node->getParent()->setRight(node);
        }
      }
      else
      {
        this->root = node;
      }
      delete temp;
      return true;
    }
    else if (node->getRight() == nullptr)
    {
      Node<T> *temp = node;
      node = node->getLeft();
      node->setParent(temp->getParent());
      if (node->getParent() != nullptr)
      {
        if (node->getParent()->getLeft() == temp)
        {
          node->getParent()->setLeft(node);
        }
        else
        {
          node->getParent()->setRight(node);
        }
      }
      else
      {
        this->root = node;
      }
      delete temp;
      return true;
    }
    else
    {
      Node<T> *temp = node->getRight();
      while (temp->getLeft() != nullptr)
      {
        temp = temp->getLeft();
      }
      node->setValue(temp->getValue());
      return this->remove(node->getRight(), temp->getValue());
    }
  }
}

template <class T>
void AVLTree<T>::balance()
{
  Node<T> **balanceNode = &(this->root);

  if ((*balanceNode) == nullptr)
  {
    return;
  }

  int balanceFactor = this->getHeight((*balanceNode)->getLeft()) - this->getHeight((*balanceNode)->getRight());

  switch (balanceFactor)
  {
  case 2:
    // If the balance factor is greater than 1, then the tree is unbalanced and the left subtree is heavier.

    /**
     * If the left subtree of the left subtree is heavier than the right subtree of the left subtree,
     * then the left subtree is heavier.
     * It performs a right rotation.
     */
    if (this->getHeight((*balanceNode)->getLeft()->getLeft()) >= this->getHeight((*balanceNode)->getLeft()->getRight()))
    {
      *balanceNode = this->rotateRight(*balanceNode);
    }
    /**
     * If the right subtree of the left subtree is heavier than the left subtree of the left subtree,
     * then the right subtree is heavier.
     * It performs a left rotation and then a right rotation.
     */
    else
    {
      (*balanceNode)->setLeft(this->rotateLeft((*balanceNode)->getLeft()));
      (*balanceNode) = this->rotateRight((*balanceNode));
    }
    break;

  case -2:
    // If the balance factor is less than -1, then the tree is unbalanced and the right subtree is heavier.

    /**
     * If the right subtree of the right subtree is heavier than the left subtree of the right subtree,
     * then the right subtree is heavier.
     * It performs a left rotation.
     */
    if (this->getHeight((*balanceNode)->getRight()->getRight()) >= this->getHeight((*balanceNode)->getRight()->getLeft()))
    {
      (*balanceNode) = this->rotateLeft((*balanceNode));
    }
    /**
     * If the left subtree of the right subtree is heavier than the right subtree of the right subtree,
     * then the left subtree is heavier.
     * It performs a right rotation and then a left rotation.
     */
    else
    {
      (*balanceNode)->setRight(this->rotateRight((*balanceNode)->getRight()));
      (*balanceNode) = this->rotateLeft((*balanceNode));
    }
    break;

  default:
    break;
  }
}

template <class T>
Node<T> *AVLTree<T>::rotateLeft(Node<T> *node)
{
  Node<T> *temp = node->getRight();
  node->setRight(temp->getLeft());
  temp->setLeft(node);
  return temp;
}

template <class T>
Node<T> *AVLTree<T>::rotateRight(Node<T> *node)
{
  Node<T> *temp = node->getLeft();
  node->setLeft(temp->getRight());
  temp->setRight(node);
  return temp;
}

template <class T>
bool AVLTree<T>::contains(T value)
{
  if (!this->isEmpty())
  {
    return this->contains(this->root, value);
  }
  return false;
}

template <class T>
bool AVLTree<T>::contains(Node<T> *node, T value)
{
  if (node == nullptr)
  {
    return false;
  }

  if (value > node->getValue())
  {
    return this->contains(node->getRight(), value);
  }
  else if (value < node->getValue())
  {
    return this->contains(node->getLeft(), value);
  }
  else
  {
    return true;
  }
}
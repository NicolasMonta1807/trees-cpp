#include "BinaryTree.h"

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
  this->root = nullptr;
}

template <class T>
void Tree<T>::setRoot(Node<T> *root)
{
  this->root = root;
}

template <class T>
Node<T> *Tree<T>::getRoot()
{
  return this->root;
}

template <class T>
bool Tree<T>::isEmpty()
{
  return this->root == NULL;
}

template <class T>
int Tree<T>::height()
{
  if (this->isEmpty())
  {
    return -1;
  }
  else
  {
    return this->height(root);
  }
}

template <class T>
int Tree<T>::height(Node<T> *startNode)
{
  if (startNode->isLeaf())
  {
    return 0;
  }
  else
  {
    int height = 0;
    int leftHeight = -1;
    if (startNode->getLeft() != nullptr)
    {
      leftHeight = this->height(startNode->getLeft());
    }
    int rightHeight = -1;
    if (startNode->getRight() != nullptr)
    {
      rightHeight = this->height(startNode->getRight());
    }
    return 1 + std::max(leftHeight, rightHeight);
  }
}

template <class T>
unsigned int Tree<T>::size()
{
  if (this->isEmpty())
  {
    return 0;
  }
  else
  {
    return this->size(root);
  }
}

template <class T>
unsigned int Tree<T>::size(Node<T> *startNode)
{
  if (startNode->isLeaf())
  {
    return 1;
  }
  else
  {
    int currentSize = 0;
    if (startNode->getLeft() != nullptr)
    {
      currentSize += this->size(startNode->getLeft());
    }
    if (startNode->getRight() != nullptr)
    {
      currentSize += this->size(startNode->getRight());
    }
    return currentSize + 1;
  }
}

template <class T>
bool Tree<T>::insert(T value)
{
  if (this->isEmpty())
  {
    this->root = new Node<T>(value);
    return true;
  }
  else
  {
    return this->insert(root, value);
  }
}

template <class T>
bool Tree<T>::insert(Node<T> *startNode, T value)
{

  if (startNode == nullptr)
  {
    return false;
  }

  if (value < startNode->getValue())
  {
    if (startNode->getLeft() == nullptr)
    {
      Node<T> *newNode = new Node<T>(value);
      newNode->setFather(startNode);
      startNode->setLeft(newNode);
      return true;
    }
    else
    {
      return this->insert(startNode->getLeft(), value);
    }
  }
  else if (value > startNode->getValue())
  {
    if (startNode->getRight() == nullptr)
    {
      Node<T> *newNode = new Node<T>(value);
      newNode->setFather(startNode);
      startNode->setRight(newNode);
      return true;
    }
    else
    {
      return this->insert(startNode->getRight(), value);
    }
  }
  else
  {
    return false;
  }
}

template <class T>
bool Tree<T>::remove(Node<T> *startNode, T value)
{
  if (startNode == nullptr)
  {
    return startNode;
  }

  if (startNode->getValue() > value)
  {
    return this->remove(startNode->getLeft(), value);
  }
  else if (startNode->getValue() < value)
  {
    return this->remove(startNode->getRight(), value);
  }
  else
  {
    // The node has no childs
    if (startNode->isLeaf())
    {
      delete startNode;
      return true;
    }
    // The node has exactly two childs
    else if (startNode->getRight() != nullptr && startNode->getLeft() != nullptr)
    {
      // Find the max of the left subtree
      Node<T> *maxRight = startNode->getRight();
      while (maxRight != nullptr)
      {
        if (maxRight->isLeaf())
        {
          break;
        }
        maxRight = maxRight->getRight();
      }
      // Copy the value of the found node and set it as the new subroot
      startNode->setValue(maxRight->getValue());
      if (maxRight->getFather() != nullptr)
      {
        maxRight->getFather()->setRight(nullptr);
      }
      delete maxRight;
      return true;
    }
    else
    {
      // The node has just one child
      Node<T> *childNode = (startNode->getRight() != nullptr) ? startNode->getRight() : startNode->getLeft();
      if (startNode->getValue() > startNode->getFather()->getValue())
      {
        startNode->getFather()->setRight(childNode);
      }
      else
      {
        startNode->getFather()->setLeft(childNode);
      }
      if (childNode)
      {
        childNode->setFather(startNode->getFather());
      }
      delete startNode;
      return true;
    }
  }
}

template <class T>
Node<T> *Tree<T>::find(T value)
{
  if (this->isEmpty())
  {
    return nullptr;
  }
  else
  {
    return this->find(value, root);
  }
}

template <class T>
Node<T> *Tree<T>::find(T value, Node<T> *startNode)
{
  if (startNode == nullptr)
  {
    return nullptr;
  }

  if (startNode->getValue() > value)
  {
    return this->find(value, startNode->getLeft());
  }
  else if (startNode->getValue() < value)
  {
    return this->find(value, startNode->getRight());
  }
  else
  {
    return startNode;
  }
}

template <class T>
void Tree<T>::preOrder()
{
  if (this->isEmpty())
  {
    std::cout << "Empty tree " << std::endl;
  }
  else
  {
    std::cout << root->getValue() << " ";
    this->preOrder(root->getLeft());
    this->preOrder(root->getRight());
    std::cout << std::endl;
  }
}

template <class T>
void Tree<T>::preOrder(Node<T> *startNode)
{
  std::cout << startNode->getValue() << " ";
  if (startNode->getLeft() != nullptr)
  {
    this->preOrder(startNode->getLeft());
  }

  if (startNode->getRight() != nullptr)
  {
    this->preOrder(startNode->getRight());
  }
}

template <class T>
void Tree<T>::postOrder()
{
  if (this->isEmpty())
  {
    std::cout << "Empty tree " << std::endl;
  }
  else
  {
    this->postOrder(root->getLeft());
    this->postOrder(root->getRight());
    std::cout << root->getValue() << " ";
    std::cout << std::endl;
  }
}

template <class T>
void Tree<T>::postOrder(Node<T> *startNode)
{
  if (startNode->getLeft() != nullptr)
  {
    this->postOrder(startNode->getLeft());
  }
  if (startNode->getRight() != nullptr)
  {
    this->postOrder(startNode->getRight());
  }
  std::cout << startNode->getValue() << " ";
}

template <class T>
void Tree<T>::inOrder()
{
  if (this->isEmpty())
  {
    std::cout << "Empty tree" << std::endl;
  }
  else
  {
    this->inOrder(root->getLeft());
    std::cout << root->getValue() << " ";
    this->inOrder(root->getRight());
    std::cout << std::endl;
  }
}

template <class T>
void Tree<T>::inOrder(Node<T> *startNode)
{
  if (startNode->getLeft() != nullptr)
  {
    this->inOrder(startNode->getLeft());
  }
  std::cout << startNode->getValue() << " ";
  if (startNode->getRight() != nullptr)
  {
    this->inOrder(startNode->getRight());
  }
}
#include "QuadTree.h"
#include <queue>
template <class T>
QuadTree<T>::QuadTree()
{
    this->root = new Node<T>();
}

template <class T>
void QuadTree<T>::setRoot(Node<T> *node)
{
    this->root = node;
}

template <class T>
Node<T> *QuadTree<T>::getRoot()
{
    return this->root;
}

template <class T>
void QuadTree<T>::fillTree(std::queue<int> *data)
{
    root->fillLeafs(data);
}

template <class T>
std::vector<T> *QuadTree<T>::preOrder()
{
    return preOrder(this->root);
}

template <class T>
std::vector<T> *QuadTree<T>::preOrder(Node<T> *node)
{
    std::vector<T> *result = new std::vector<T>();
    if (node != NULL)
    {
        result->push_back(node->getData());
        std::vector<T> *left = preOrder(node->getLeft());
        std::vector<T> *right = preOrder(node->getRight());
        result->insert(result->end(), left->begin(), left->end());
        result->insert(result->end(), right->begin(), right->end());
    }
    return result;
}

template <class T>
std::vector<T> *QuadTree<T>::posOrder()
{
    return posOrder(this->root);
}

template <class T>
std::vector<T> *QuadTree<T>::postOrder(Node<T> *node)
{
    std::vector<T> *result = new std::vector<T>();
    if (node != NULL)
    {
        std::vector<T> *left = posOrder(node->getLeft());
        std::vector<T> *right = posOrder(node->getRight());
        result->insert(result->end(), left->begin(), left->end());
        result->insert(result->end(), right->begin(), right->end());
        result->push_back(node->getData());
    }
    return result;
}

template <class T>
std::vector<T> *QuadTree<T>::inOrder()
{
    return inOrder(this->root);
}

template <class T>
std::vector<T> *QuadTree<T>::inOrder(Node<T> *node)
{
    std::vector<T> *result = new std::vector<T>();
    if (node != NULL)
    {
        std::vector<T> *left = inOrder(node->getLeft());
        std::vector<T> *right = inOrder(node->getRight());
        result->insert(result->end(), left->begin(), left->end());
        result->push_back(node->getData());
        result->insert(result->end(), right->begin(), right->end());
    }
    return result;
}
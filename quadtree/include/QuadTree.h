#ifndef _QUADTREE_H
#define _QUADTREE_H

#include <vector>
#include <queue>
#include "QuadNode.h"

template <class T>
class QuadTree
{
private:
    Node<T> *root;

public:
    QuadTree();
    void setRoot(Node<T> *node);
    Node<T> *getRoot();
    void fillTree(std::queue<int> *data);
    std::vector<T> *preOrder();
    std::vector<T> *posOrder();
    std::vector<T> *inOrder();

private:
    std::vector<T> *preOrder(Node<T> *node);
    std::vector<T> *postOrder(Node<T> *node);
    std::vector<T> *inOrder(Node<T> *node);
};

#include "QuadTree.hxx"
#endif // _QUADTREE_H

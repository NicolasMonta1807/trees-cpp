#ifndef _QUAD_NODE_H
#define _QUAD_NODE_H

#include <queue>

template <class T>
class Node
{
private:
    int color;
    Node<T> *FirstQuadrant;
    Node<T> *SecondQuadrant;
    Node<T> *ThirdQuadrant;
    Node<T> *FourthQuadrant;

public:
    Node();
    Node(int color);
    int getColor();
    void setColor(int color);
    void setFirstQuadrant(Node<T> *node);
    void setSecondQuadrant(Node<T> *node);
    void setThirdQuadrant(Node<T> *node);
    void setFourthQuadrant(Node<T> *node);
    Node<T> *getFirstQuadrant();
    Node<T> *getSecondQuadrant();
    Node<T> *getThirdQuadrant();
    Node<T> *getFourthQuadrant();
    void fillLeafs(std::queue<int> *data);
    void fillMatrix(int **matrix, int supx, int infx, int supy, int infy);
};

#include "QuadNode.hxx"

#endif // _QUAD_NODE_H
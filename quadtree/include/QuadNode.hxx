#include "QuadNode.h"

template <class T>
Node<T>::Node()
{
    this->FirstQuadrant = nullptr;
    this->SecondQuadrant = nullptr;
    this->ThirdQuadrant = nullptr;
    this->FourthQuadrant = nullptr;
}

template <class T>
Node<T>::Node(int color)
{
    this->color = color;
    this->FirstQuadrant = nullptr;
    this->SecondQuadrant = nullptr;
    this->ThirdQuadrant = nullptr;
    this->FourthQuadrant = nullptr;
}

template <class T>
int Node<T>::getColor()
{
    return this->color;
}

template <class T>
void Node<T>::setColor(int color)
{
    this->color = color;
}

template <class T>
Node<T> *Node<T>::getFirstQuadrant()
{
    return this->FirstQuadrant;
}

template <class T>
Node<T> *Node<T>::getSecondQuadrant()
{
    return this->SecondQuadrant;
}

template <class T>
Node<T> *Node<T>::getThirdQuadrant()
{
    return this->ThirdQuadrant;
}

template <class T>
Node<T> *Node<T>::getFourthQuadrant()
{
    return this->FourthQuadrant;
}

template <class T>
void Node<T>::setFirstQuadrant(Node<T> *node)
{
    this->FirstQuadrant = node;
}

template <class T>
void Node<T>::setSecondQuadrant(Node<T> *node)
{
    this->SecondQuadrant = node;
}

template <class T>
void Node<T>::setThirdQuadrant(Node<T> *node)
{
    this->ThirdQuadrant = node;
}

template <class T>
void Node<T>::setFourthQuadrant(Node<T> *node)
{
    this->FourthQuadrant = node;
}

template <class T>
void Node<T>::fillLeafs(std::queue<int> *data)
{
    if (data->empty())
        return;
    int aux = data->front();
    data->pop();
    this->setColor(aux);

    if (aux == 2)
    {
        this->FirstQuadrant = new Node<T>();
        this->SecondQuadrant = new Node<T>();
        this->ThirdQuadrant = new Node<T>();
        this->FourthQuadrant = new Node<T>();

        FirstQuadrant->fillLeafs(data);
        SecondQuadrant->fillLeafs(data);
        ThirdQuadrant->fillLeafs(data);
        FourthQuadrant->fillLeafs(data);
    }
}

template <class T>
void Node<T>::fillMatrix(int **matrix, int supx, int infx, int supy, int infy)
{
    if (this->color == 0)
    {
        for (int i = infx; i < supx; i++)
            for (int j = infy; j < supy; j++)
                matrix[i][j] = 0;
    }
    else if (this->color == 1)
    {
        for (int i = infx; i < supx; i++)
            for (int j = infy; j < supy; j++)
                matrix[i][j] = 1;
    }
    else
    {
        this->FirstQuadrant->fillMatrix(matrix, (supx + infx) / 2, infx, (supy + infy) / 2, infy);

        this->SecondQuadrant->fillMatrix(matrix, (supx + infx) / 2, infx, supy, (supy + infy) / 2);

        this->ThirdQuadrant->fillMatrix(matrix, supx, (supx + infx) / 2, supy, (supy + infy) / 2);

        this->FourthQuadrant->fillMatrix(matrix, supx, (supx + infx) / 2, (supy + infy) / 2, infy);
    }
}
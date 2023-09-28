#include <iostream>
#include "AVLTree.h"

int main()
{
  AVLTree<int> *tree = new AVLTree<int>();
  tree->insert(20);
  tree->insert(10);
  tree->insert(30);
  tree->insert(15);
  tree->insert(5);

  tree->remove(30);

  return 0;
}
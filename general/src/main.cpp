#include <iostream>
#include "Tree.h"

int main()
{
  Tree<int> *tree = new Tree<int>(5);
  tree->addNode(5, 6);
  tree->addNode(5, 8);
  tree->addNode(6, 3);
  tree->addNode(3, 10);
  tree->addNode(3, 15);
  tree->addNode(8, 7);
  tree->addNode(8, 9);

  std::cout << "All inserts: ";
  tree->postOrder();

  tree->removeNode(9);

  std::cout << "Removed Node(9): ";
  tree->postOrder();

  std::cout << "Looking for existing value: " << tree->findNode(7) << std::endl;
  std::cout << "Looking for non existing value: " << tree->findNode(9) << std::endl;

  std::cout << "The size of tree is: " << tree->size() << std::endl;

  return 0;
}
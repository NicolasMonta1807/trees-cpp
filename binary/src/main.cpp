#include <iostream>
#include "../include/BinaryTree.h"

int main()
{
  Tree<int> *tree = new Tree<int>(7);
  tree->insert(3);
  tree->insert(20);
  tree->insert(0);
  tree->insert(5);
  tree->insert(15);
  tree->insert(25);
  tree->insert(-3);
  tree->insert(1);
  tree->insert(4);
  tree->insert(6);
  tree->insert(30);

  std::cout << "PreOrder: ";
  tree->preOrder();

  std::cout << "PostOrder: ";
  tree->postOrder();

  std::cout << "InOrder: ";
  tree->inOrder();

  tree->remove(tree->getRoot(), 30);

  std::cout << "Height: " << tree->height() << std::endl;
  std::cout << "Size: " << tree->size() << std::endl;

  int lookUp = 3;
  Node<int> *result = tree->find(lookUp);

  if (result != nullptr)
  {
    std::cout << lookUp << " found at: " << result << std::endl;
  }
  else
  {
    std::cout << lookUp << " not found" << std::endl;
  }

  return 0;
}
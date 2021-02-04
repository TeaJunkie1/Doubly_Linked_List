#include <iostream>
#include "DLL.h"

//Tomas Soucek

int main() {
  List l;
  l.createNode(5);
  l.createNode(1);
  l.createNode(2);
  l.createNode(11);
  l.createNode(6);
  l.createNode(3);
  l.print();
  l.deleteFirst();
  l.print();
  l.insertPoistion(3, 3);
  l.print();
  l.deletePosition(3);
  l.print();
  l.length();
  

  

}
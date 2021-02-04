#include "DLL.h"
#include <iostream>
using namespace std;

//smaze prvni 
void List::deleteFirst(){
  Node* temp = head;
  head = head->next;
  delete temp;
}


//konstruktor
List::List(){ 
  head = nullptr;
  tail = nullptr;
}

//destruktor
List::~List(){
  while(head != tail){
    deleteFirst();
  }
}

void List::print(){
  Node* temp = new Node;
  temp = head;
  while(temp != nullptr){
    cout << temp->data<< " ";
    temp = temp->next;
  }
  cout<<"konec printu "<< endl;;
}

void List::createNode(int value){
  Node* temp = new Node;
  temp->data = value;
  temp->prev = nullptr;
  temp->next = nullptr;
  //pokudn je DLL prazdny, temp je jediny prvek
  if (head == nullptr){
    head = temp;
    tail = temp;
  }
  //DLL ma alespon jeden prvek
  else{
    tail->next = temp;
    temp ->prev = tail;
    tail = temp;
    tail->next = nullptr; //zarazka na tail
  }
}

void List::insertPoistion(int index, int value){
  //vytvorime novy prvek

  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  Node* temp = new Node; // pomocna do elsu

  if (index< 1){
    cout<<"\nindex musi byt > 1.";
  }
  else if(index == 1){
      // pokud je index = 1, vytvorime novy head
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    else{
      //pokud je index neco jineho
      temp = head;
      for (int i = 1; i < index-1; i++){
        temp = temp->next;
      };
      newNode->next = temp->next;
      temp->next = newNode;
      newNode->prev = temp;

      if (newNode->next == nullptr){
        tail = newNode;
      }
    }
  }


void List::deletePosition(int index){
  //jestli je index > 1
  if(index < 1) {
    cout<<"\nposition should be >= 1.";
  } 
  
  else if (index == 1 && head != NULL) {
      // pokud je index 1 a head neni null, vytvorit novy head a vymazat predchozi head
 
    Node* nodeToDelete = head;
    head = head->next;
    free(nodeToDelete);
    if(head != NULL){
      head->prev = NULL;
    }
  } 
  else {
    // else vytvorit temp* a posunout pred pozici, kterou mazeme
    Node* temp = head;
    for(int i = 1; i < index-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
    // pokud predchozi node  a dalsi neni null, posychrovat linky ve spojaku
  
    if(temp != NULL && temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete); 
    } else {

      //5. Else node je prazdna.
      cout<<"\nPrvek seznamu je jiz null";
    }       
  }
}

int List::length(){
  Node* temp = head;
  int i = 0;
  while(temp != nullptr){
    i++;
    temp = temp -> next;
  };
  cout << "Ve spojovem seznamu je " << i << " prvku." << endl;
  return i;
}


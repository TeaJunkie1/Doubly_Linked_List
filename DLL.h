struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

class List {

  private:

    Node* head;
    Node* tail;

  public:
    List(); // done
    ~List(); // done
    void print(); // done
    void createNode(int value); //done
    void deleteFirst(); //done
    void insertPoistion(int index, int value); // done
    void deletePosition(int index);  //done
    int length(); //  done
};
// LinkedList is a data structure that stores contiguous elements
// it can be increased or decrease
// but Linkedlist does not store the elements in contiguous locations
// so if 1 3 2 5 is stored and addess of 1 is 78675 then address of 3 is not 78676, this can be anything. 
// THEREFORE NOT IN CONTIGUOUS LOCATIONS
// we can store ints, doubles, lists, chars, etc
// size of a linkedlist can be increased at any moment, unlike array

// how to traverse to other elements?
// each node contains the pointer to its next node.
// starting point of the LL is called head of the LL
// head has the address of first node
// this node will have a variable next that stores the location of next data element
// the last node's next is NULL (nullptr)
// this nullptr identified end of linked list
// this is the tail of the linkedlist
// whenever a new node comes, the tail's next will be updated to the new node's memory location

// Linkedlist is used in stacks and queues
// in real life, it is used in browsers to store whereever we go

// in LL, in a node we have a data and a next pointer. so we need to define a datatype to store the pointers
struct Node{
    int data;
    Node* next;

    Node(data1, next1){
        data = data1;
        next = next1;
    }
};

// above is a selfdefined data type with a constructor
// How to initialize?
// Node x = Node(2, nullptr) <- a node with data 2 and next as nullptr
// Node* y = &x; gives the pointer to the node x

// But above way is confusing, so do like this:
// Node * y = new Node(2, nullptr)
// this automatically stores pointer to the memory location; y will point to the new node 2
// but with struct OOPS cannot work, so we use class instead of struct

class Node{
    int data;
    Node* next;

    Node(data1, next1){
        data = data1;
        next = next1;
    }

    Node(data1){
        data = data1;
        next = nullptr;
    }
};

// Memory?
// on a 32 bit system, int takes 4 bytes, pointer takes 4 bytes -> 8 bytes for one node
// on a 64 bit system, int takes 4 bytes, pointer takes 8 bytes -> 12 bytes for one node

// How to convert array to LL?
// say arr is 2 1 3 8
// initially define head
// store 2 at the head and point next to null
// head always points to this
// do not forget head
// take a variable mover
// iterate for next variables (here 1 3 8)
// create a node for the data 1
// its next is null
// mover is at head right now
// data 1 is at temp
// therefore make mover->next = temp
// and then move the mover to 1
// (TEMP is already a pointer since we did Node * temp = new Node (1, nullptr))
// similarly store 3 and make 1 point to 3
// in questions related to LL, we have to return the head. so do not forget the head.

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Traversal in a LL O(N)
// we have the head that points to the start of the linked list
// dont tamper the head
// take a temp variable at head itself
// print temp->data
// then move temp = temp->next
// continue this until it reaches null

Node* temp = head;
while(temp != NULL){
    cout << temp->data << endl;
    temp = temp->next;
}

// length of a LL O(N)
int lengthofLL(Node * head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

// Search in a LL O(N)
// given the head and an element, check
int checkIfPresent(Node * head, int val){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}


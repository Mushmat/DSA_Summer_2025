// Doubly linked list
// in singly linked list we used to store data and nextptr
// here in doubly linked list, we can also go backward
// so it stores data, nextptr, as well as backptr

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
}

// Array to DLL
// given an array 1 3 2 4
// define the head
// initially both ptrs null
// store prev as head also 

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(1, nullptr, nullptr);
    Node* prev = head;
    for(int i = 1; i < n-1; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

// DELETE A NODE
// 1) delete head
// If DLL is empty, then return nullptr or head, as nothing can be deleted
// if DLL has only one element, simply free it and return null
// now, other than the base cases. if we delete head, the head must move to the next element
// when head moves, the new head's previous must be null
// previous head's next must be null
// now free prev head

Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    if(head->next == nullptr) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

// 2) delete tail
// again if head empty return null
// if single element return null
// to delete the tail, tail's back should point to null
// tail's back's next should point to null
// then free tail
// simply reach to the tail

Node* deleteTail(Node* head){
    if(head == nullptr) return head;
    if(head->next == nullptr) return NULL;

    Node* tail = head;
    while(tail->next != nullptr){
        tail -> tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    free(tail);

    return head;
}


// 3) delete kth node
// K can be from 1 to N
// If k is 1, deleting head
// if K is N, deleting tail
// if it is a single element, then delete if K is 1
// otherwise a middle element
// for kth node,
// come to the kth node, reach it

Node* deleteK(Node* head, int k){
    if(head == NULL) return head;

    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == NULL && front == NULL){
        free(temp);
        return nullptr;
    }
    else if(prev == NULL){
        deleteHead(head);
    }
    else if(front == NULL){
        deleteTail(head);
    }

    temp->back = nullptr;
    temp->next = nullptr;
    prev->next = front;
    front->back = prev;
    free(temp);

    return head;

}

// 4) Delete a specific node, using the data
// Given that node which needs to be deleted, cannot be the head.

void deleteNode(Node * temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    free(temp);
}

// INSERTION NODE
// 1) before the head
// the new node's next will point to head
// head's back will point to new node

Node* insertBeforeHead(Node * head, int val){
    Node* newhead = new Node(val, head, nullptr);
    head->back = newhead;

    return newhead;
}

// 2) before the tail
// new node's head will point to tail
// new node's back will point to tail's previous back element
// previous back's element's next will point to new node
// tail's back will point to new node

Node* insertBeforeTail(Node* head, int val){

    if(head->next == NULL){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(10, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;

}

// 3) insert at kth position
// if k is 1 or n, insert before head or tail
// otherwise go to that node
Node* insertK(Node * head, int val, int k){
    if(k == 1) return insertBeforeHead(head, val);

    Node * temp = head;
    int cnt = 0;
    while(temp){
        cnt = cnt + 1;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

// 4) Insert before a given node (which is never a head)

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}
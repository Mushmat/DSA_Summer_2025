    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
    }

// DELETION OF A NODE
// 1) Delete the head of the LL
// To delete the head, we first need a new head
// move the head from the next element first
Node* DeleteHead(Node* head){
    if(head == NULL) return head;

    // keep a temp point to start
    Node* temp = head;
    // move head to next
    head = head->next;
    // free the temp memory
    free(temp);
    return head;
}

// 2) Delete the tail of the LL
// head points to start, we need to go to the last. the second last element must point to a nullptr
// we need to stop before the last element, but if LL only has 1 element, then that needs to be deleted itself

Node* deleteTail(Node * head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return nullptr; // no LL left after deleting single element

    // stop at second last 
    // temp.next.next will point to NULL at second last element
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp->next;
    }

    // now temp is standing at the second last element
    free(temp->next);
    temp->next = nullptr;
    return head;
}

// 3) Given K, delete kth element of the linked list
// if length is 4, and given k = 5, cant delete
// if k = 1, delete head
// if k = 4, delete tail
// otherwise delete kth element

Node* deleteK(Node* head, int k){
    if(head == nullptr) return head;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // if k is > size -> return;

    // to delete a middle element in the LL, we need that element's previous, and the next pointer. because prev and next will join
    // prev -> next = prev -> next -> next
    // basically the element's previous has been pointed to the element's next
    // but we need to stop at the eleemnt we need to delete, so initialize temp and counter

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;

        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// 4) given the value (data itself), delete. 
// here simply we can compare data in the while loop, similar to part 3

Node* deleteElement(Node* head, int el){
    if(head == nullptr) return head;
    if(head->data == el) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // if k is > size -> return;

    // to delete a middle element in the LL, we need that element's previous, and the next pointer. because prev and next will join
    // prev -> next = prev -> next -> next
    // basically the element's previous has been pointed to the element's next
    // but we need to stop at the eleemnt we need to delete, so initialize temp and counter


    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){

        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// INSERTION
// 1) at head
// if LL was 2 3 1 8, and we need to insert 5 at head, it should become 5 2 3 1 8
// simply insert node before head storing 5 and point it to the head

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

// 2) Insert at the last
// we need 2 3 1 8 5 here
// move to the last element
// then add

Node* insertTail(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;

}

// 3) insert at K element, where K is from 1 to n + 1
// if length is 4, K can be from 1 to 5, otherwise error
// k = 1 means insert at head, k = 5 means insert after tail
// if LL is empty, then we can only insert at first posn. 

Node* insertK(Node * head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else return NULL;
    }

    if(k == 1){
        Node* temp = new Node(el, head);
        return temp;
    }

    // for middle elements, we need to make prev point to new, and new->next point to prev
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k - 1){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }

    return head;
}

// 4) insert before the value x


Node* insertBeforeValue(Node * head, int el, int val){
    if(head == NULL){
        return NULL;
    }

    if(head->data == val){
        Node* temp = new Node(el, head);
        return temp;
    }

    // for middle elements, we need to make prev point to new, and new->next point to prev
    Node* temp = head;
    while(temp != NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }

    return head;
}
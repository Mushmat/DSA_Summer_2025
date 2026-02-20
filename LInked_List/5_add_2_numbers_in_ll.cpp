// given l1 and l2
// l1 is given in a reversed order
// similarly given l2 in a reversed order
// we have to sum (add) these two numbers
// so basically there is linked list 1: L1 -> 2 4 6
// whose number is read as 642 (reversed)
// and linked list L2 -> 3 8 7,
// whose number is 783.
// add these two, 642 + 783 = 1425
// now we have to make a linkedlist, and make 1425 in reversed order: 5 -> 2 -> 4 -> 1 and return head of this which is at 5

// since the number is in reversed order, the head node is the unit's place in the sum
// so while summing itself we can make the LL

// so we have head1 head2
// assign a dummy node (initially -1), and take a variable current.
// temp1 temp2 to traverse l1 l2
// a variable 'carry'
// add temp1 temp2, put the unit's place of this value to a new node and point curr to it
// move curr
// add temp1 temp2 again, put the unit's place to a new node
// keep doing this, and make carry = 1 when the sum >= 10
// after eveything is done, dummynode's next is the head

Node* addTwoNumbers(Node* num1, Node* num2){
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1 && temp2){
        int sum = carry;
        if(temp1) sum += temp1 -> data;
        if(temp2) sum += temp2 -> data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr -> next = newNode;
        curr = curr -> next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyNode -> next;
}
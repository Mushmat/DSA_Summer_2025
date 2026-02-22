// given a Linked list
// every node represents a digit
// the whole list represents a number
// say 1 -> 5 -> 9 represents 159
// if we add here, result is 160
// ll becomes 1 -> 6 -> 0
// if we have 9999, then if we add 1 then it becomes 10000 that means we will have to add a new node as the new head of the linked list

// so, we will start with the last node, then traverse back ward adding 1 and carrying the carry
// but since there is no backward link, we cannot traverse directly
// hence, we can simply reverse the linked list
// after reversing, start from the head
// and start with the carry as 1
// now keep moving and adding 1 the carry
// if carry becomes 0, break out then n there
// again reverse the list and return the head

// if a number is like 9999, then
// reverse it
// start the same process
// if temp has reached NULL but there is still a carry = 1 left, then we have to make a new node
// but not yet,
// first call the reverse function
// and then create a new node with the carry, and point this node to the head of the linked list
// and then return the new head

fun(head){
    head = reverse(head);
    temp = head;
    carry = 1;
    while(temp != NULL){
        temp.data = temp.data + carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    head = reverse(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}
// TC is O(3N) and SC:O(1)

// so here the TC is very high
// hence we will use recursion
// again the maths is of carry, moving backwards
// in recursion since we can backtrack, we will do it
// start with the head, and call recursion for the NEXT NODE
// keep going to the end,
// once you reach null, this is the base case
// at base case, we will add 1, called as the carry
// add the carry to the node now, if > 10 keep carry, else let it be
// this adds via backtrackking instead of a back pointer
// again if at the last, carry is still 1, make a new node

int helper(temp){

    if(temp == NULL) return 1;
    carry = helper(temp->next);
    temp->data = temp->data + 1;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1; // since data is > 10
    
}

fun(head){
    carry = helper(head);
    // this above is the final carry after the end
    if(carry == 1){
        newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}
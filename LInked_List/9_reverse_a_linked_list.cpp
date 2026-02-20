// Reverse a linked list

// brute is to put all data in the stack 
// then pick out data from stack and change the data in the LL

// better:
// change the links
// for each node, we need to point its next to its prev
// for any node temp, there is its front and prev
// we need that temp->next = prev
// but if we do this, we lost connection to front
// so before replacing this, store the front node as temp.next
// then do temp->next = prev;
// move prev as prev = temp
// and then temp = front
// repeat

temp = head;
prev = NULL;
while(temp != NULL){
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
}

return prev;

// TC : O(N) and SC: O(1)
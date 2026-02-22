// delete the middle node of the linked list
// for odd LL, delete middle
// for even LL, delete second middle

// even if we reach the node before the middle node, we can change the link and return the head

// better:
// again use toirtoise and hare to find the middle node, lecture 13
// get the middle node, in the slow, and change the links
// otherwise, what we can do is, we can one skip part for slow pointer, by this way the slow pointer reaches one node before middle
// anything works

if(head == NULL && head->next == NULL) return NULL;
fast = slow = head;
fast = fast.next.next;
while(fast != nullptr && fast -> next != nullptr){
    slow = slow.next;
    fast = fast.next.next;
}
middle = slow.next;
slow->next = slow.next.next;
free(middle);
return head;
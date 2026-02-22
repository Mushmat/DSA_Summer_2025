// detect a loop in a given LINKED LIST

// defn in LL: minimum of one node happens where you start and reach back

// brute:
// remember which nodes have been seen, once a node count increases to 2, theres a cycle

// better: the tortoise & hare algorithm again (slow and fast pointers)
// again take slow and fast pointers
// slow by 1 step, fast by 2 steps
// if fast and slow pointers meet, theres a loop
// if we have a LL which doesnt have a cycle, then
// if the LL is odd, it will stop when fast->next is NULL, if the LL is even, it will stop when fast is NULL

slow = head; fast = head;
while(fast != NULL && fast -> next != NULL){
    slow = slow.next;
    fast = fast.next.next;
    if(slow == fast) return true;
}

return false;
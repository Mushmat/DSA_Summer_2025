//return the middle of the linked list
// for odd length linked list, middle is easy to determine
// however for even length linked list, return the second middle

// brute:
// if we know the number of nodes, then the middle node is N/2 + 1
// so we can just run a loop to find the length of the linked list
// after finding the length, move the pointer again till we move that much nodes
// and return

// better:
// use slow and fast pointers
// take a slow pointer and a fast pointer
// move slow by 1 step, fast by 2 steps
// do this
// the moment the fast pointer reaches the last node, stop then ; or fast pointer becomes itself null (which happens in even length LL)
// at which momemnt, slow pointer will point to the middle node

slow = head, fast = head;
while(fast != NULL || fast->next != NULL){
    slow = slow.next;
    fast = fast.next.next;
}
return slow; 
// TC: O(n/2)
// SC: O(1)
// find the length of the loop in the LL
// in case of no loops, return 0

// brute: use hashing
// remember the nodes
// and keep a timer
// then traverse
// when we visit a node twice, subtract the time of first visit and next visit
// that is the length of the loop

// better:
// tortoise and hare
// slow and fast pointers
// slow by 1, fast by 2
// keep a counter at 0, and move it when slow and fast come at the same point at the same time
// when slow comes back to the same node, the value of counter is the length of the loop


findlength(slow, fast){
    cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast.next;
    }

    return cnt;
}

slow = fast = head;
while(fast != NULL && fast->next != NULL){
    slow = slow.next;
    fast = fast.next.next;
    if(slow == fast){
        return findlength(slow, fast);
    }
}
return 0;
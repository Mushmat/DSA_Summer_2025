// find the start of the loop
// return NULL if no loop

// for brute, maintain a hash map, store the entire nodes
// traverse using a temp, when we reach a node that is already there, that node is the first occurence
// return that node

// for better solution again, we will use tortoise and hare
// slow by 1, fast by 2
// once the slow and fast pointers collide, we detected that theres a loop
// now we need to find the starting point
// to find the start point, take any of fast or slow, and place it to the head. say we take slow and make it head, and fast is still at its old posn
// no move both slow and fast by one step
// the moment they collide again, that is the point of the starting point yayayyayayyay

slow = fast = head;
while(fast != NULL && fast -> next != NULL){
    slow = slow.next;
    fast = fast.next.next;
    if(slow == fast){
        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}

return null;
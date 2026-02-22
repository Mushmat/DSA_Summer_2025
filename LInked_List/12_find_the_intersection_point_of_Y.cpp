// given two linked lists with some common nodes, we need to return the first node where they are common
// they might not have any common nodes, so return null
// if they collide, return first node which is common

// brute:
// we are looking for a node which is in both linked lists
// so we can memorize the nodes in first LL
// and traverse second LL, if any node exists that is in first as well, then the first one is the common one
// to memorize, use hashing
// declare a map for <node, int>
// initialize temp1 and temp2 for both LL
// traverse the first LL using temp1
// put the node in map and move, say node is 3,1 where 3 is node data and 1 is linked list number
// now look for those nodes in the second LL

// better: 
// need to solve without using other DS
// we can directly compare both temp1 and temp2, but for that we need to make sure both temp1 temp2 are at the same level.
// the link sizes can be different, so the temp in the longer linked list must move ahead to the level of the shorter temp
// say L2 is longer
// then, use a counter to compute length of the shorter linked list
// and a counter to compute length of longer linked list
// then, if both are equal start comparing
// but if not equal, take the difference of the lengths, and move the larger temp by the difference. say if diff was 2, temp2 moves 2 steps
// now keep checking and move ahead

Node* collisionPoint(headsmaller, headlarger, difference){
    while(difference){
        difference--;
        t2 = t2 -> next;
    }
    while(t1 != t2){
        t1 = t1 -> next;
        t2 = t2 -> next;
    }

    return t1;
}

t1 = head1, n1 = 0
t2 = head2, n2 = 0
while(t1 != NULL){
    n1++;
    t1 = t1 -> next;
}
while(t2 != NULL){
    n2++;
    t2 = t2 -> next;
}
if(n1 < n2){
    return collisionPoint(head1, head2, n2-n1);
}
else return collisionPoint(head2, head1, n1-n2);
// TC: O(N1 + N2 + N2-N1 + N1) = (N1 + 2N2)
// SC: O(1)

// the time complexity is very much
// Optimal solution:
// take temp1 and temp2
// move them simultaneously
// when one pointer reaches NULL, take this pointer to the opposite list's head
// and move other pointer as normal
// keep repeating this, when other pointer reaches NULL, take it to the opposite of the list
// and then, both the temps will get aligned on the same level
// once both pointers have switched lists and yet reached last node to reach null, this means there is no collision point

if(head1 == NULL || head2 == NULL) return NULL;
t1 = head1; t2 = head2;
while(t1 != t2)
{
    t1 = t1 -> next;
    t2 = t2 -> next;

    if(t1 == t2) return t1;
    if(t1 == NULL) t1 = head2;
    if(t2 == NULL) t2 = head1;
}

return t1;
// given two sorted linked lists
// merge them, return head of the new LL

// brute: 
// go to all elements of L1 and L2 and put it in a container
// sort the container
// make a linkedlist out of it
// O(N1 + N2 + NlogN + N) very high where N = N1 + N2
// and an external space of O(N)

// better:
// optimization is using two pointers
// just compare the two pointers, whichever is less, put it, and move the pointer
// we also need not create a new list, we can just change the existing links
// take a dummy node -1 first
// compare the pointers, whichever is smaller, point -1 node to that smaller node
// this is not a creation of new node, its the prev node itself
// again compare and keep changing the links
// once one of the lists exhaust, just add left over elements
// head of the LL will be dummyNode->next

t1 = head1, t2 = head2;
dNode = new Node(-1);
temp = dNode;
while(t1 != null || t2 != null){
    if(t1.data < t2.data){
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    }
    else{
        temp->next = t2;
        temp = t2;
        t2 = t2 -> next;
    }
}

if(t1){
    temp -> next = t1;
}
else if(t2) {
    temp -> next = t2;
}

return dNode -> next;

// O(N1 + N2)
// Space is O(1)
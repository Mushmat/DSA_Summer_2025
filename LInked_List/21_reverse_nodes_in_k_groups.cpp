// given LL, given k
// figure out the groups of k size and reverse them individually
// for eg in a LL of 1 2 3 4 5 6 7 8 9 10, and k = 3
// first group is 1 2 3, reverse them
// ll becomes 3 2 1 4 5 6 7 8 9 10
// then next group is 456, reverse
// ll becomes 3 2 1 6 5 4 7 8 9 10
// next group is 7 8 9, reverse
// 3 2 1 6 5 4 9 8 7 10
// now there is no group of size 3, so it is not reversed
// therefore updated head points to 3

// take a temp at the head
// get the kth node
// send this part of the linked list (headed at temp and tail at kth node), and send it to reverse() function
// make sure kth node points to null, so that we pass a proper LL to reverse, not a part of it
// reverse will return the head of the reverse linked list
// after reversal, kth node and newHead will be at the same node, and old head and temp will be at the same node (the tail in the reverse)
// update the head to kth node
// before breaking the link while passing to reverse function, preserve the nextNode
// now temp = nextNode

findkthNode(temp,k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

temp = head; prevNode = NULL, nextNode = NULL;
while(temp != nullptr){
    kthNode = findkthNode(temp, k);
    if(kthNode == nullptr){
        if(prevNode) prevNode->next = temp;
        break;
    }
    nextNode = kthNode -> next;
    kthNode->next = nullptr;
    reverse(temp);
    if(temp == head){
        head = kthNode; // this happens only when this is the first k group
    }
    else{
        // otherwise dont update head
        prevNode->next = kthNode

    }
    prevNode = temp;
    temp = nextNode;
}

return head;
// O(2N) TC
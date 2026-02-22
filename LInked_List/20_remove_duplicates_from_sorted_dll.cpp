// given a sorted DLL, remove the duplicate data
// since the linked list is sorted, duplicates are contagious

// so we can do one traversal
// keep temp at head
// if theres a duplicate, it will be next to the temp
// check if nextNode == temp, then move nextNode ahead to check if there are more duplicates
// get all the duplicates, at this point nextNode starts pointing to the first NOT DUPLICATE, so point temp to nextNode, and nextNode to temp
// continue this

temp = head;
while(temp != NULL && temp -> next != NULL){
    nextNode = temp->next;
    while(nextNode != nullptr && nextNode->val == temp->val){
        // do free space here
        nextNode = nextNode -> next;
    }
    temp->next = nextNode;
    if(nextNode) nextNode->prev = temp;
    temp = temp -> next;
}
return head;
// TC: in the complete traversal, the temp reaches the first occurence of new elements, and newHead checks the repeated elements
// so in total TC is O(n) 
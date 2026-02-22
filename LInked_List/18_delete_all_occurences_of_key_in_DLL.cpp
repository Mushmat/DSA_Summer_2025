// given a DLL
// given a key
// delete all the occurences of this key from the list and return the new DLL

// a single traversal should do it
// keep a temp
// whenever temp is the key, then
// if temp is the head itself, then shift the head to next
// take nextNode and prevNode, if temp is not head, point prevNode to nextNode
// if temp and data match at the tail, then only point prevNode to null

temp = head;
while(temp != NULL){
    if(temp->val == key){
        if(temp == head){
            head = head.next;
        }
        nextNode = temp.next;
        prevNode = temp.prev;
        if(nextNode) nextNode->prev = prevNode;
        if(prevNode) prevNode->next = nextNode;
        free(temp);
        temp = nextNode;
    }

    else{
        temp = temp.next;
    }

    return head;
}
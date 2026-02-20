// remove nth node from the end
// given n
// count n from backwards and remove that node, say n = 2, remove second last node
// n can be anything, it may even point to the head or the tail

// brute: temp at head, and count the length of the linked list
// after getting the length of the linked list, then, 
// reach the node at count - n, which is one node previous to the node we intend to delete
// then reach that node from the head
// store the delNode as temp->next;
// and then temp.next = temp.next.next, res = res = cnt - N

// better:
// we tried reaching the previous node of the delete node
// which want n steps to the end
// so from front, if we traverse n steps less, then we will reach the node which is just before the delete node
// take a pointer known as fast pointer, move it n steps
// take a slow pointer, and move now both fast and slow pointers simulatenously
// fast goes ahead slow goes ahead, and so on
// stop the moment fast is at the last node
// and the slow now will point to the node just before the delete node
// and then now do the same thing as done above, change links

Node* fast = head;
for(int i = 0; i < n; i++){
    fast = fast->next;
}
Node* slow = head;
while(fast->next != NULL){
    slow = slow->next;
    fast = fast->next;
}
if(fast == NULL) // you have asked to delete head, so delete head
{
    return head->next;
}

Node* delNode = slow->next;
slow->next = delNode->next;
free(delNode);
return head;


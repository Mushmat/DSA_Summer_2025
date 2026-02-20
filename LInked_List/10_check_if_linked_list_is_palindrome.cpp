// given a LL, check if it is palindrome

// brute: 
// take a stack, again put all elements
// traverse again and check if its the same as what comes from stack

// better: 
// we need to compare the first and second half (in case of even length)
// if we can reverse the second half of the LL, then we can keep one pointer at start and one at end, and check if both are equal
// but for that we need to recognize second half
// reach to the middle using slow and fast pointer
// for an even length, move to middle 1 (not middle 2)
// stop when fast reaches second last node
// slow's next points to the first node of second half
// now reverse the links
// for odd length LL, perform same thing, find out the first and second half
// stop when fast->next != NULL

if(head == NULL || head->next == NULL) return true;
slow = head;
fast = head;
// slow moves by 1, fast by 2
while(fast -> next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
Node * newHead = reverse(slow->next); // use reverse function of last lecture
first = head;
second = newHead;
while(second != NULL){
    if(first->data != second->data){
        reverse(newHead);
        return false;
    }
    first = first->next;
    second = second->next;
}

reverse(newHead);
return true;

// TC: O(2N) and SC:O(1)
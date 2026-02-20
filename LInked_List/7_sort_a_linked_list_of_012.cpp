// given a LL with only 0s 1s 2s.
// sort it

// for bruting: we can get the counts of 0s 1s 2s in one traversal
// then, do another traversal and change the values
// this is O(2N)

// better solution: 
// the only option again is to change the existing links
// we make three segregated lists to make lists for 0s 1s 2s
// so make three dummyNodes, one each for 0 1 2
// zeroHead, oneHead, twoHead (initialy all -1)
// point one pointer each to all three dummy heads
// now traverse the original list
// if it is 0 attach to zeroHead list
// similarly for 1 and 2
// after this, all three dummyHeads have their individual lists
// all three pointers now point to last node of each lists
// the last of zero will point to start of 1 (only if there are 1s), similarly for last of 2s

// PSUEDO CODE
if(head == NULL || head->next == NULL) return head;

zeroHead, oneHead, twoHead = new Node (-1);
zero = zeroHead, one = oneHead, two = twoHead;

temp = head;
while(temp){
    if(temp->data == 0){
        zero->next = temp;
        zero = zero -> next;
    }
    else if(temp -> data == 1){
        one -> next = temp;
        one = one->next;
    }
    else{
        two -> next = temp;
        two = two -> next;
    }

    temp = temp -> next;

    // if we do not have a 1, then 0 will have to be connected to 2
}

zero->next = (oneHead->next) ? oneHead->next : twoHead->next; // if oneHead->next exist, connect zero's next to oneHead's next, otherwise connect to twoHead's next
// if 2s are also not there, twoHead will point to NULL, so zero Head will eventually point to NULL which is ok!

one->next = twoHead->next; 
two->next = nullptr;

newHead = zeroHead->next;
free(zeroHead), free(oneHead), free(twoHead); // free memory  
return newHead;
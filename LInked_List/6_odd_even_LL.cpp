// given the head of the linked list, group the odd index nodes (indexing starts from 1), and the even indexed nodes together
// so in a LL of 1 3 4 2 5 6
// group 1 4 5 and 3 2 6
// 1 -> 4 -> 5 -> 3 -> 2 -> 6 and return this
// so first odd -> then even

// brute: data replacement
// take the odd data and place it in the first half, then the even data in the next half
// take a list, and start at the head.
// jump by 2 places and add the data in the last
// do this until temp is null, once it is null, the list now contains odd data
// now start temp from 2nd element (to get even index nodes now)
// traverse even until temp->next is null. 
// now we have the array with odd and even index data
// now traverse the LL again and replace the data

// Better solution:
// we should change the links such that odd1 is connected to odd2 is connected to odd3 etc, and evens are connected to events
// so link changes is what we must do for odd and even index nodes
// take odd variable at head, and even at head->next
// for odd, do odd->next = odd->next->next
// now move odd, odd = off->next
// similarly for even, even->next = even->next->next
// and move even, even = even->next
// stop when no more left
// at last, point last odd to first even
// therefore keep an access evenHead to the first even node, and after traversals, odd->next = evenHead (odd is already at the last odd node)

if(head == NULL || head->next == NULL) return head;
odd = head, even = head->next; evenHead = head->next;
while(even != NULL && even->next != NULL){
    odd.next = odd.next.next;
    even.next = even.next.next;

    odd = odd.next;
    even = even.next;
}

odd.next = evenHead;
return head;
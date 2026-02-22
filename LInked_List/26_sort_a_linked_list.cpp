// sort any given any linked list
// return the head of the sorted list

// brute:
// take all the elements
// put it into an array
// sort the elements
// go through the list and change the data
// wont do as TC is high

// better:
// since we wont like to use any other space
// we know two good sorting algorithms: merge sort and quick sort
// lets implement merge sort within the linked list
// first step is to break the list from the middle
// for odd length, say 5, take 3 from left, 2 from right
// say the list is 3 4 2 1 5
// so after breaking, left list is 3 4 2 null
// right list is 1 5 null
// again break both lists
// left list breaks into 3 4 null, 2 null
// right list breaks into 1 null, 5 null
// at the end of this breaking, we have, 3 null, 4 null, 2 null, 1 null, 5 null
// whenever we have single element, its the base case
// now sort back
// while going back, we will be sorting 2 sorted lists
// keep merging 2 sorted lists and go back
// old ms function:
ms(arr, low, high){ 
    if(low == high){
        return;
    }
    mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

// code:
ms(head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // find the middle of the list using the tortoise and hare, to get the first middle
    middle = findMiddle(head);
    // now head denotes left linkedlist
    // midle.next denotes right linkedlist
    leftHead = head;
    rightHead = middle.next;
    middle->next = nullptr; // separating left LL
    leftHead = ms(leftHead);
    rightHead = ms(rightHead);
    return merge2Lists(leftHead, rightHead);
}
// TC: O(NlogN)
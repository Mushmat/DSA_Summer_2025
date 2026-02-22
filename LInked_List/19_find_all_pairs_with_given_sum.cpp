// given the head of a SORTED DLL
// find the pairs that give a given sum
// note that it is a sorted doubly linked list

// brute: keep two pointers temp1 temp2 at head and head+1
// and traverse and compare
// stop when the sum gets exceeded, since the list is sorted, we wont find any other pair afterwards
// but this TC is O(near about n^2), space is O(1)

// better:
// since we have a sorted dll, then
// take a left pointer at the head,
// take a right pointer at the tail
// add both, if the value is greater than the sum, then reduce right to right.back
// if the value is less, then increase left, as in move left to left.next
// when they are equal, move both left and right (so it is given that DLL doesnt have any duplicates)
// when right < left, come out

left = head;
right = tail;
ds = [];
while(left->val < right->val){
    if(left->val + right->val = sum){
        ds.add(left->val, right->val);
        left = left->next;
        right = right->prev;
    }
    else if(left->val + right->val < sum){
        left = left->next;
    }
    else{
        right = right->prev;
    }
}

return ds;
// O(N) + O(N) : O(2N)
// SC IS STILL O(1) as the array that we use IS TO GIVE THE ANSWER, not to SOLVE

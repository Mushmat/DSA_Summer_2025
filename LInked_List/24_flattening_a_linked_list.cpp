// flatten a linked list
// this linkedlist is little different
// given the head
// head will have a next pointer as usual
// but this time, each node also has a child pointer
// this child pointer points to another node, that might or might not have more children
// therefore each node has two pointers: next and child, which might or not might point to NULL
// every node and its children are sorted
// so basically it is sorted vertically, but NO GUARANTEE OF SORTED IN HORIZONTAL LEVEL
// task is to flatten this into one child linked list, 
// which means start the head with 1 (data 1) whose child points to next sorted element, whose child to next, and so on
// THE NEXT POINTER OF EVERY NODE POINTS TO NULL AND CHILD POINTER TO THE NEXT SORTED ELEMENT, IN THE VERITCAL ORDER

// brute:
// declare a list to hold all integers
// place temp at head
// store data in list
// if there is no child node, move to next
// if there is a child node, traverse in the bottom direction using temp2
// by this, we store every integer to the array
// now sort this
// and convert it to a VERTICAL LINKED LIST, not a normal LL

convert(arr){
    // simple change of pointers from next to child
    if(arr.size == 0) return nullptr;
    head = new Node(arr[0]);
    temp = head;
    for(i = 1 to n-1){
        newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp.child;
    }

    return head;
}

arr = [];
temp = head;
while(temp != NULL){
    t2 = temp;
    while(t2 != NULL){
        arr.add(t2.data);
        t2 = t2 -> child;
    }
    temp = temp.next;
}

sort(arr);
head = convert(arr);
return head;
// The brute force time complexity is:
// say horizontal length is N, and vertical length is M
// O(NxM) + O((NxM) log (NxM)) + O(NxM)
// Space is O(N*M) x 2

// better:
// now we will consider that the vertical linked list is already sorted
// also we will use the same list's links to make the vertically sorted list, this saves space
// a two pointer approach using a dummy node
// whichever is small, put it as the child of the dummy node and carry on
// using the same nodes, just change links
// lets first write for merging 2 lists

merge2lists(list1, list2){
    dummyNode = new Node(-1);
    res = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1.val  < list2.val){
            res->child = list1;
            res = list1;
            list1 = list1.child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2.child;
        }
        res.next = nullptr;
    }

    if(list1) res->child = list1;
    else if(list2) res->child = list2;
    return dummyNode.child;
}

// this above code is only for two lists, we can have any number of lists
// assume we merge 2 lists into one
// now we can take this merged list and another list
// by this we can merge 2 2 list at once and complete it
// use recursion to do this

f(head){
    if(head == NULL || head -> next == nullptr){
        return head;
    }
    mergedHead = f(head -> next);
    return merge2lists(head, mergedHead);
}
// TC is 2MN
// SC is N, the recursion stack space
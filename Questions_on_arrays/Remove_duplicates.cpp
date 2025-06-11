// Remove duplicates from a sorted array

/*
    Brute Force:
    Define a set Data Structure
    Traverse the array and put elements in the set. Since set only adds unique elements, no duplicates will be there
    After one traversal, set contains unique elements
    Our goal now is to put the unique elements in the starting of the array that we recieved as input
    Keep a pointer at the 0th index
    Go to the first element of the set and place it into the 0th index
    Move the index one step ahead
    Take next element of the set and place it there.
    Repeat
    Once set is empty, there are no other insertions needed.
    Therefore, whereever the index stops, is the size of the array having unique elements

    TC: Set takes logn to insert. Therefore in one pass it takes nlogn time. This is the asymptotic TC for this algo. 
*/

/*
    Optimal:
    Apply two pointers to get unique elements and store them in the array
    Keep a pointer at the first guy and go right to find a guy who is different to the first guy. If yes, keep the first pointer now at that guy and repeat
*/
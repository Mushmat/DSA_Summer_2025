// Find the union and intersection of TWO SORTED arrays
// Union first

// BRUTE
// Take a set. (ordered set)
// Iterate the first array, put elements in the set
// Iterate the second array, put elements in the set
// After the iteration, set contains the union.
// Take a union array with size of the set. 
// Put elements from the set to the array and get the union. 
// TC: nlogn

// Optimal
// Use two pointers
// Keep an i pointer on the first element of the first array
// Keep a j pointer on the first element of the second array
// define a union list (empty initially)
// keep the element that is smallest among (i and j) (no other element is smallest since both the arrays are sorted).
// say element at i is the smallest, keep that in the union list, and move i
// Again check for smallest among i and j, dont take the element if it is already in the union list. 
// Repeat until one of the pointers exhaust. When one of the iterations end, take unique elements from the other pointer's iterations and store them in the union array
// TC: O(n1 + n2)
// SC: O(n1 + n2) only used to return the answer. Not used to solve the question

// Intersection

// Optimal
// Again apply two pointers
// Keep i at the first element of the first array
// Keep j at the first element of the second array
// initialize ans
// if i is not equal to j, and assuming i < j, we can say there is no occurence of i in the second array since both arrays are sorted
// move i, again compare, if equal, store it in the ans. move both i and j.
// repeat.
// once one of i or j exceeds, no one else can be compared with. Therefore its over. 
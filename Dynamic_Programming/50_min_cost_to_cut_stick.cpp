// given an array and length of the stick
// say arr is 1 3 4 5 and length of stick is 7
// you can cut the length at 1 or 3 or 4 or 5
// find the minimal cost to cut
// cost = length of the stick we cut
// if we cut at 1, we now have a stick of length 1 and a stick of length 6
// if we NOW cut at 3, we now have a stick of length 1, stick of length 2 and of length 4
// the first cut cost us 7 as length of stick was 7
// next cut took 6
// next cut will take 4 cost
// after which we have 4 sticks of length 1 2 1 3 
// now we will cut at 5, and will have sticks of lengths 1 2 1 1 2 (cost is 3 since we cut the 3 length stick)
// and the total cost = 7 + 6 + 4 + 3 = 20
// we need to minimize the cost
// cuts can be made in any order

// if we treat the entire cuts array as a partition i & j, we can start with any element
// we can then make cuts in any order since the array of cuts is sorted
// LEFT IN BETWEEN
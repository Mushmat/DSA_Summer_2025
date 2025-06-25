// find nth root of given integer m. eg integer given is 27, and n is 3, then third root of 27 is 3 
// integer is 69, and 4th root is asked, then it doesnt exists then -1
// assign low as 1, high as integer m
// get mid
// check if mid * mid * mid... for n times, is greater than integer m. then any number to its right cant be an answer, therefore eliminate the right space
// again get mid, and again check. keep eliminating rights
// if mid * mid * mid = integer m, return
// but what if the nth root of m doesnt exist, that means we'll have to return -1. how to identify that
// if you get mid * mid * mid ... < m, then there might lie a potential answer to the right side
// therefore eliminate left and check again
// if high < low that means no integer was the answer, return -1
// overflow happens in this question when the number is too big that its multiplication cannot be stored
// therefore check for the case when the multiplication crosses m, multiplication > m, eliminate the right half straightaway without computing the exact mid

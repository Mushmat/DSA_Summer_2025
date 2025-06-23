// given a sorted array
// and a target
// return the pair of the first and last occuring index of the target element
// if number is not there in the array, return {-1 -1}
// we can use lower bound and upper bound to get the solution
// lowerbound(target) would give the first occurrence 
// upperbound(target) - 1 would give the last occurrence
// but you must check that
// lowerbound(target) must point to the target itself. it might happen if the target isnt there in the array, then ans is wrong
// also if lowerbound points to the size of array (meaning it is pointing to hypothetical index, its wrong)
// if any one of the above condn is violated, the target is not there
// if everything is correct then {lowerbound, upperbound - 1} is the answer

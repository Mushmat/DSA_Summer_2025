// Find the square root of an integer
// Return floor value if the square root is not an integer
// to do using BS
// keep low as 1, high as the number whose square root we need to find
// find mid
// check if mid is the square root. if mid * mid > number given, then anything right to mid is not the answer, and vice versa
// and repeat
// once a mid fulfills the condition that mid * mid <= number, it might be an answer. then you need to check to the right as well
// to check for other numbers that also fulfill the condition
// once done, return
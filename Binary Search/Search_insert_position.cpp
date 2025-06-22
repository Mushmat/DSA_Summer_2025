// Given a sorted array with distinct values and target value m
// If the value is present in the array, return index
// if the value is not present in the array, then return the index at which the element can be inserted maintaining its sortedness
// we need to find an index that has element >= our target
// which is nothing but finding out the lower bound
// therefore find the lower bound and easy. 
// refer to lower_and_upper_bound.cpp
// Given an array containing number of pages of n books
// given a number of students
// allocate these books among these students such that
// each student must atleast get one book
// each book should be allocated to one student only
// book allocation should be in a contiguos manner
// allocate the books to m students such that maximum number of pages assigned to any student is minimum possible
// otherwise return -1

// if number of students > number of books -> allocation not possible
// start from the highest number of pages
// this is the max number of pages that can be assigned to someone
// try allocating the books such that no student gets books with greater than this number of pages
// if allocation is not possible, keep increasing the max number of books by 1 and keep allocating
// the maximum possible answer can be when there is only 1 student, and hence you sum the number of pages of all books
// therefore you have the range now
// therefore low is max(arr)
// high is sum(arr)
// to the right of mid, number of students requried will be lesser
// left to mid, number of students required are higher
// find the mid, if number of students with this mid is < our students, eliminate right. because we need to decrease the barrier so that more students can get books
// if number of students > our students, eliminate left because we need to increase barrier so that our number of students suffice
// if mid satisfies with our number of students, eliminate right to try out for a better answer in the left half
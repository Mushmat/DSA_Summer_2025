// return the kth smallest element in the BST
// given the root of the BST

// if we write the inorder of the binary search tree, 
// we will get the sorted BST as an array
// the inorder of any given BST is always in sorted order
// this will eliminate the need to sort the list after doing any other traversal

// tc: o(n) and sc: o(n)
// we still use O(n) space to store the BST
// we will therefore
// to save space
// we will keep a counter = 0
// when we visit a node (left node right), do a counter++
// when counter == k, answer is the node that we are on currently

// if recursive traversal is done, TC: O(n) and stack space o(n)
// if iterative is done, again tc and sc is same
// if we do morris traversal, we get tc as o(n) and sc as o(1)

// in all these traversal, keep the counter and solve

// to get the kth largest node, count the number of nodes in the tree say N. 
// return (N - kth) smallest node
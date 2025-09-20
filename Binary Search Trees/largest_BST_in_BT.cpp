// given a BT, find the largest BST in that

// brute:
// since we have the validate BST function, just pass the node to it, and it will return whether that node as the root, is a valid BST or not
// but this is a O(n^2) solution

// better:
// if there is a node, no matter how many nodes are, if we can figure out the largest among them, if our node is greater than the largest then
// all nodes on left follow BST property
// smrly we can do for the right part

// for any node, we need largest on the left, smallest on the right. 
// therefore both needs to be computed
// therefore we need postorder traversal (left, right, node)
// for leaf nodes (a single node is always a BST) return size as 1, itself as largest and itself as smallest
// if either right or left is null, pass a dummy node with size 0, largest as INT MIN, and smallest as INT MAX
// for a node now, above leaf, we now have its left tuple, and its right tupe of (size, smallest, largest)
// the node to be a best, it should be greatet than left's largest, and smaller than right's smallest
// if it is, the node forms a size++ node


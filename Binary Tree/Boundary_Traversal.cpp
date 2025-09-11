// boundary traversal of the tree (anticlockwise in this code)

// first take the left boundary excluding leaf nodes
// then take the leaf nodes
// then take the right boundary in the reversed direction

// to get left boundary excluding leaf nodes, take a DS to store it
// put the root in it
// after that, start from the root's left and put it in DS. if there exists a left, put it on. keep checking for existence of left. if doesnt, check for right
// put it, and again check for left. 
// if the node is a leaf node, dont put it in the DS

// to get the leaf nodes, do a preorder traversal
// if we do this, we will get the leaf nodes in the correct order, and at once
// add the leaf nodes to the DS

// for the right boundary in reverse, excl leaves
// start from root's right, use a stack 
// put it in the stack, go to the right, put in stack.
// if there doesnt exist a right, go to left, put it in stack
// exclude leafs


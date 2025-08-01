// for every node in the binary tree, the difference of height(left) and height(right) must be less than or equal to 1, for it to be a balanced binary tree
// one solution is to check for every node, wehther the difference is less than or equal to 1 or not.
// simply find the left and right height until leaf node is reached, and check the difference for every node
// return false if absolute difference > 1, else return true if no node returns false
// but this solution takes O(n^2)

// since we are writing a boolean function to return true if balanced, false if not balanced, then:
// we already know how to find the height of a tree in O(N)
// say check(node) is the function that returns the height of the tree rooted at node
// in the same function, we just check if absolute of left height and right height is > 1, simply return -1 (indicating a non-balanced BT)
// else return the height of the tree indicating it is the balanced tree
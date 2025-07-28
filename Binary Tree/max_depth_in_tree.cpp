// find the max depth of any given BT (height)
// we cab use level order traversal or a recursive traversal to find it
// level order might end up taking O(n) space (because of queue data structure) while recursive method might take auxilliary space O(height)
// In most cases height is logn
// if we stand at the root node, the hieght would be 1 + max(height on left, height on right)
// it gives us a hint to use recursion.
// if we use recursion, at first we move to the left side of the root and get the height using recursion.
// then go to the right and get the height using recursion
// in the recursion method, we traverse ultimately every node to check for the height

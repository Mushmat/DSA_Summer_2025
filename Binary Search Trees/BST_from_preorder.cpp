// given the preorder traversal of a BST, make the BST and return the root

// brute:
// preorder is root left right
// first element of traversal is henceforth root
// and keep inserting elements from the traversal, following the BST property
// TC O(n x n)

// Better:
// We know that inorder traversal is always sorted
// if we sort the preorder, we will get the inorder 
// once we have the inorder and the preorder
// we can easily create a binary tree
// and since this binary tree has to be unique, it will be a BST
// TC: nlogn for sorting + n
// SC: n to store inorder

// Optimal:
// All nodes will belong to a range 
// We can carry the upper bound only to find the result
// start and keep upper bound (ub) as INT MAX
// reach the root
// since upper bound is INT MAX, and root is inside the range, put the root to the node
// since preorder is root left right, there might be left to the root
// if there is a left, but not sure how many elements are there, then we know that everything to the left is smaller than root
// hence we know what all are on left
// therefore go left, choose upperbound as root and then
// check whether the next element in traversal can be a node (i.e. it is less than upper bound)
// keep doing this
// once the element is greater than upper bound, return null from that node
// and put the element on the right considering it follows upper bound of parent
// TC here is O(3N) therefore O(N)
// SC O(1) recursion uses only stack space

TreeNode* bstFromPreorder(vector<int>& A){
    int i = 0;
    return build(A, i, INT_MAX);
}

TreeNode* build(vector<int> &A, int& i, int bound){
    if(i == A.size() || A[i] > bound) return NULL;
    TreeNode* root = newTreeNode(A[i++]);
    root->left = build(A, i, root -> val);
    root->right = build(A, i, bound);
}

// given a binary tree tell whether it is a bst or not

// if we provide a range to every node (for the node's value to be)
// and if the node lies in that range
// for every node if this is true, then it is a BST

// assume initially elements are between [-int min, int max]
// root lies in the range, hence valid
// go to left, go to right, both should return true (recursive)
// left range is [-int min, root], right range is [root, int max]
// keep doing this
// return true if both recursions return true

bool isValidBST(TreeNode* root){
    return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
}

bool isValidBST(TreeNode * root, long minVal, long maxVal){
    if(root == null) return true;
    if(root->val >= maxVal || root.val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

// O(n)
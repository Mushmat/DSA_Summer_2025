// is the BT symmetric?
// a BT is said to be symmetric if it forms a mirror of itself around the center

// to get the answer, we need to observe that the left part and the right part to the root must be the same
// the root of the left part is the original root -> left
// the root of the right part is the original root -> right
// if we compute the preorder traversal of the left part
// and if we compute the reverse preorder traversal of the right part
// they should be same

// therefore at every traversal, compare both left part and right 

bool isSymmetric(TreeNode* root){
    return root == NULL || isSymmetricHelp(root -> left, root -> right);
}

bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left == NULL || right == NULL) return left == right;
    if(left.val != right.val) return false;
    return isSymmetricHelp(left.left, right.right) && isSymmetricHelp(left.right, right.left);
}
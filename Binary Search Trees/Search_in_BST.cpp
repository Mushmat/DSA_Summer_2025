// given a target node and the BST, return the address of the target
// if the value doesnt exist, return NULL
// we can simply use the property that Left < Node < Right
// we will simply be on the node, if node > target, go to left
// if node < target, go to right
// if node == target, accept
// if both left and right are null, return null indicating node not there

// this only takes logn time.

TreeNode* searchBST(TreeNode* root, int val){
    while(root != NULL && root->val != val){
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}
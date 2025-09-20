// given a node, insert it into BST such that BST remains BST
// there can be multiple possible trees
// return any one tree's root

// try to figure out where the node can be put if the node is to be put as a LEAF node
// go there and insert the node as a leaf
// therefore find where the node can be, and insert it

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);
    TreeNode* cur = root;
    while(true){
        if(cur->val <= val){
            if(cur->right != NULL) cur = cur->right;
            else{
                cur->right = new TreeNode(val);
                break;
            }
        } else {
            if(cur->left != NULL) cur = cur->left;
            else{
                cur -> left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}
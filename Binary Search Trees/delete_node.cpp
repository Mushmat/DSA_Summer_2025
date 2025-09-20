// delete a node in BST
// given the BST, delete the given node

// deleting a node means we have to rearrange its children
// henceforth there can be multiple answers, return one such answer

// search for the node
// we can delete that node but we need to rearrange children
// one way to do this is to join right child to left child and then join this tree to the original tree
// other way is to do the opposite

TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL) return NULL;

    if(root -> val  == key){
        return helper(root);
    }
    TreeNode *dummy = root;
    while(root != NULL){
        if(root -> val > key){
            if(root->left != NULL && root->left->val == key){
                root->left = helper(root->left);
                break;
            } else{
                root = root -> left;
            }
        }
    }
    return dummy;
}

TreeNode* helper(TreeNode * root){
    if(root -> left == NULL) return root->right;
    else if(root -> right == NULL) return root->right;

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* findLastRight(TreeNode* root){
    if(root -> right == NULL) return root;
    findLastRight(root->right);
}
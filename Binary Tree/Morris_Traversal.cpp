// how to find inorder and preorder using morris traversals
// morris traversal does not consume any space, hence SC is O(1) unlike recursive traversal that has O(n)
// it uses Threaded Binary Tree to achieve this

// Inorder is left root right
// we cannot have parent pointers but we need something to tell us the backward arrows 
// from the last node of any subtree, we go back to the root (observation)

vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode *cur = root;
    while(cur != NULL){
        if(cur -> left == NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode * prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev ->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}


vector<int> getPreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode *cur = root;
    while(cur != NULL){
        if(cur -> left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode * prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev ->right == NULL){
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
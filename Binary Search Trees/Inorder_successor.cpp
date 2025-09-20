// find the inorder successor in a bst, given a value 
// when we write the inorder of the bst, the inorder that we get, has the given value
// inorder successor is the node just next (right of) the value given to us

// brute way is to just store the inorder and, then find the first value that is greater than the given value
// if no successor exists, return null
// time and space is O(n)

// better would be to perform an inorder traversal. find value that we encounter that is greater than the given value is the answer
// t(n) would be o(n) and SC would O(1) if we do morris traversal and only stack space (internal space) is used

// optimal would be to solve the solution in TC: O(logn)
// we can store a variable successor = null initially
// start from root and go towards the given value.
// store successor when the root's value become greater than the given value
// when we get a value which is greater than value, we move left because we have a value greater than our value, so we need a value now that is less than the value we got now, and greater than given
// that is, find a better successor
// TC: O(Height of tree)

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;

    while(root != NULL){
        if(p->val >= root->val){
            root = root->right;
        } else {
            successor = root;
            root = root -> left;
        }
    }
    
    return successor;
}
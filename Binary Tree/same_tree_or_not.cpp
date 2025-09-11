// given two trees, are they identical
// any traversal of both the trees should be same
// say preorder -> root left right
// preorder traversal of both the trees should be same

bool isSameTree (TreeNode* p, TreeNode* q){
    if(p == NULL || q == NULL){
        return (p==q);
    }
    return (p-> val == q-> val) && isSameTree(p->left, q->left) && isSameTree(p->right, q-> right);
}
// find the least common ancestor in the BST given two nodes

// when the two nodes lie on left side and right side (WLOG) respectively, then the root itself is the LCA
// therefore if one node is less than root, and other greater than root, then the root is LCA
// if both of them do not lie on left, and both of them do not lie on right, then that node is itself the LCA

TreeNode lowestCommonAncestor(TreeNode * root, TreeNode* p, TreeNode* q){
    if(root == null) return null;
    int curr = root.val;
    if(curr < p.val && curr < q.val){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p.val && curr > q.val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}
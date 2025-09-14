// LCA in a binary tree

// lowest common ancestor of two nodes is the node common to both but at the last of the path
// lowest common ancestor of a grand parent and a child is the grandparent itself
// therefore ancestor that exists at the deepest level is the answer

// BRUTE:
// for the lca of node 1 and node 2
// get the path from root to node 1 say P1
// get the path from root to node 2 say P2
// match for the elements in their path. the last element that matches is the lowest common ancestor of both
// but we use more space in this solution since we are storing two paths

// lets do a recursive traversal
// we will do the DFS traversal from root
// it has to go to left and then to the right
// the moment we reach a node which is either node 1 or node 2; dont go further left and right, return that node
// if both left and right return null, you also return null from that node
// when we reach the second node, return that node
// say if node x got first node from right, null from left. take the first node and return it
// say if node y got first node from left, and second node from right. that means this node is the lowest common ancestor.

// IT DOES NOT MATTER WHETHER NODE IS COMING FROM LEFT OR FROM RIGHT
// IT IS THAT BOTH SHOULD RETURN THE NODE 1 AND NODE 2 IRRESPECTIVE OF DIRECTION
// BOTH THE NODES ARE UNDER YOU, YOU ARE THE LOWEST COMMON ANCESTOR

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else{ // both are not null
        return root;    
    }
}

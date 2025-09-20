// given the root of a BST that represents the complete BST
// there are two nodes that are swapped in the given tree
// we have to fix this to make the BST correct
// there will always be two nodes that are swapped

// brute
// if we do the BST inorder, we will not get a sorted traversal since the BST has swapped nodes
// if we sort the traversal, we will get the correct inorder BST traversal
// once we have the correct inorder, simply traverse and make the BST from inorder

// better solution
// if we write inorder of the incorrect BST
// there are two cases for swapping: one is where swapped nodes are not adjacent, second is where swapped nodes are adjacent
// while visiting the incorrect inorder we can identify where the violation is. we can store the first violation and second violation
// swap the violations

TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;

void inorder(TreeNode* root){
    if(root == null) return;

    inorder(root->left);
    if(prev != null && (root ->val < prev->val)){
        if(first == null){
            first = prev;
            middle = root;
        }
        else last = root;
    }
    prev = root;
    inorder(root -> right);
    
}

void recoverTree(TreeNode* root){
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val, last->val);
    else if(first && middle) swap (first->val, middle->val);
}
// count complete tree nodes
// given a root of a complete binary tree 
// design algo that runs in less than O(n)

// we can simply do an inorder traversal but that will count the nodes in O(n) time

// since the tree is complete binary tree, we can use its property
// if the hieght of the tree (say 3 for example), then the number of nodes are 2^3-1 = 7
// therefore if we can somehow compute the height of the tree, we'll get the max number of nodes by the above formula
// leaf nodes might not be there (read complete tree defn)

// we will check for every subtree
// if any subtree is a full binary tree (has all nodes) we will get the number of nodes by 2^n-1 and then at last, sum all these to get the total

// start traversal from root
// get to left and find left height (incl root)
// get to right and find right height
// if they are equal use 2^n-1
// if they are not equal, then this is not a full binary tree, therefore we cannot apply formula directly
// therefore we will go to the left and again check, go to the right and again check
// get the number of nodes by formula 

// 1 + (left subtree) + (right subtree)

int countNodes(TreeNode * root){
    if(root == NULL) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh == rh) return (1<<lh) - 1;
    return 1 + countNodes (root->left) + countNodes(root -> right);
}

int findHeightLeft(TreeNode * node){
    int hght = 0;
    while(node){
        hght++;
        node = node->left;
    }
    return hght;
}

int findHeightRight(TreeNode * node){
    int hght = 0;
    while(node){
        hght++;
        node = node->right;
    }
    return hght;
}
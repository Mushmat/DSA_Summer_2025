// given a binary tree, maintain the children sum property
// for any node, the value of node = left node value + right node value
// if it does not follow, you can increment value of any node by 1 any number of times
// basically we want to make every node follow the property

// however there are cases when the it doesnt work. 

// question is to convert the binary tree to any binary tree that follows the property
// we will do a recursive traversal by moving to left and then moving to right
// go to node's left and node's right, sum their values. if the value is less then the parent's value, take the parent's value and give it to BOTH left and right child
// now go to the child's left and right, and again reassign values
// once a node has NO LEFT and NO RIGHT, come back
// while coming back, whatever left and right has, add them and give that value to their parent. now parent = left + right
// if the child's node and right has a sum > parent, then change the value of the parent to the sum of its children

// we are doing this because we can increase the value of nodes however we cannot decrease. so by this method, we will not have a shortage of values

void changeTree(BinaryTreeNode <int> * root){
    if(root == NULL) return;
    int child = 0;
    if(root -> left){
        child += root->left->data
    }
    if(root -> right){
        child += root->right->data
    }

    if(child >= root->data) root->data  = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root -> right) root->right->data = root -> data;
    }

    changeTree(root -> left)
    changeTree(root -> right)

    int tot = 0;
    if(root -> left) tot += root->left->data;
    if(root -> right) tot += root -> right -> data;
    if(root -> left or root -> right) root -> data = tot;
}
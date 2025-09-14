// Flatten a binary tree to a linked list

// the preorder of the binary tree has to be represented as a linked list
// we dont have to create a new linked list, we have to rearrange the binary tree to the linked list
// all rights should point to the next node, all lefts point to NULL

// 1st approach is to break node links wherever we need to change. in a right left root fashion (reveresed postorder)
prev = nullptr
flatten(node){
    if(node == x) return;
    flatten(node->right);
    flatten(node->left);
    node->right = prev;
    node->left = null;
    prev = node;
}


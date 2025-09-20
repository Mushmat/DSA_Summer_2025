// find the ceiling in a BST
// assume a key is given
// find the lowest val greater than or equal to key

// this is very simple
// start at root, if root greater than key store it as a potential answer
// look for a better answer on the left (since root is greater)

// if root is lesser, then go to right for a potential answer
// if root is equal to key, return
// if both left and right null, not possible to move further
// a better answer is an answer less than current answer but greater than or equal to key

int findCeil(BinaryTreeNode<int> * root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root -> data;
            return ceil;
        }
        if(root -> data > key){
            ceil = root -> data;
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return floor;
}
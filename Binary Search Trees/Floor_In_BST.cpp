// get the floor of the key given a BST
// greatest value that is smaller than or equal to key

// be at root , if root < key, it is a potential answer but look at right for better
// if root > key, go to left for ptential answer

int findFloor(BinaryTreeNode<int>* root, int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(root->data > key){
            root = root->left;
        }
        else{
            floor = root -> data;
            root = root->right;
        }
    }
    return floor;
}
// A struct node is created which has a left and right pointer
// left pointer points to the left child, it will again be a node.
// right pointer points to the right child, again a node
// the children will again point to their children, again nodes
// leaf nodes will point to NULL

/*

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
}

*/

// Above is the structure of the tree. For each node there is the data, their pointers to left and right
// Initially the data is set to val and both pointers to NULL
// Call in main:
/*

    main(){
        struct Node * root = new Node(1) // Creates the root node with value 1
        root->left = new Node(2) //left child of root is a node with value 2
        root->right = new Node(3) // right child of root is a node with value 3
        root->left->right = new Node(5) // root's left child's right is a node of value 5
    }
*/
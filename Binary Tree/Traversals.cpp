// DFS: Depth First Search
// Three types:
// 1) Inorder Traversal: Go to the extreme left subtree and apply left root right, then go to root then right
// 2) Preorder Traversal: root left right (after root, go the left most subtree and apply the logic root left right) then right
// 3) Postorder Traversal: left right root (go to the left most subtree and apply left right root) then go to right, then root

// BFS: Breadth First Search
// Search and return the layers
// Each level one by one

// Codes:

/*
Preorder_Traversal: (root left right) O(N)

void preorder(node){
    if(node == null) return
    print(node->data)
    preorder(node->left)
    preorder(node->right)
}

*/

/*
Inorder_Traversal: (left root right) O(N)

void inorder(node){
    if(node == NULL) return
    inorder(node -> left);
    print(node -> data)
    inorder(node -> right);
}

*/

/*
Postorder_Traversal: (left right root) O(N)

void postorder(node){
    if(node == NULL) return
    postorder(node->left)
    postorder(node->right)
    print(node->data)
}

*/

// Level Order Traversal (BFS)
// To do this, we need a queue DS
// and a vector of vector to store the traversal level wise
// place the root in the queue
// and start iterating
// take the root out, and put the left element of the root in queue, and the right element of the root in the queue (if they exist)
// once this is done, put the root in the vector of vector 
// then in the next iteration, pick the next element in the queue and repeat

/*

vector<vector<int>> levelOrder(Node * root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root)
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            Node * node = q.front()
            q.pop()
            if(node -> left != NULL) q.push(node-> left)
            if(node -> right != NULL) q.push(node -> right)
            level.push_back(node->val);
        }
        ans.push_back(level)
    }
    return ans;
}

*/
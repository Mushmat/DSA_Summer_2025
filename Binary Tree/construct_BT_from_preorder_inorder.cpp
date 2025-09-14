// construct a unique binary tree given both preorder and inorder traversal

// say inorder = 40 20 50 10 60 30
// say preorder = 10 20 40 50 30 60

// binary tree that we will create will always be a unique BT
// seeing the preorder, since preorder is root left right, we can say that 10 will be the root of the tree
// hence root = 10
// seeing inorder, since left is left of root. and 10 exists in between. then, all nodes 40 20 50 will be part of left subtree (left to root)
// and smrly, other two nodes 60 30 will be part of right subtree

// and the left subtree and right subtree again solves themselves
// for left subtree 40 20 50, we need inorder and preorder to get these solved as well. the inorder for them is 40 20 50 only
// the preorder will be 20 40 50, as seen in the preorder array
// smrly for right subtree, 60 30 is inorder, 30 60 is preorder

// with this info we can create the trees again having the root of both
// recursively this will create a binary tree which will be unique

TreeNode* buildTree(vector<int>& preorder, vector<int> & inorder){
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, intpreStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, map<int, int> inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart +numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, inMap);
    return root;

}
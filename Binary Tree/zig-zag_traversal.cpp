// return the zig zag traversal of the tree
// zig zag traversal is like, on first level go from left to righ
// on second level go from right to left
// on third level go from left to right
// and so on

// lets introduce a flag variable which will tell us whether we have to go from left to right, or from right to left
// once the traversal of one level is complete, change the flag
// maintain two data structures, in one of the strucutres, start with the node and push the node
// push node's left and node's right in that ds
// once the traversal is complete, check flag. if flag is 0, push the element in the second data structure as left to right
// if flag is 1, push it right to left in 2nd data structurr

// first structure is queue
// second structure stores the zig zag traversal we want

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;

    if(root == NULL) return result;

    queue<TreeNode*> nodesQueue;

    nodesQueue.push(root);
    bool leftToRight = true;

    while( !nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);

        for(int i =0 ; i < size ; i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if(node -> left) {
                nodesQueue.push(node -> left);
            }
            if(node -> right){
                nodesQueue.push(node -> right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
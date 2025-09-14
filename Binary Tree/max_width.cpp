// return the maximum width of the binary tree

// width is -> max no of nodes, in a level, between any two nodes
// there must be nodes on the left and right side. we can assume nodes in between these, but the corners must be there

// width is henceforth dependent on the level
// it is the nodes between first node and last node on that level

// we will index all the nodes from left to right in all the levels
// then the answer will be last index - first index + 1 (for that level)

// for 0 based indexing, left node has index 2*i + 1, and right has 2*i + 2
// for 1 based indexing, left node has index 2*i, right has 2*i + 1
// where i is the index of the parent

// but we cannot use these index values because this will lead to overflow
// we have to prevent this overflow
// for each level, what we will do is, we will start indexing from 0 again. for all levels, the first node has the index 0

int widthOfBinaryTree(TreeNode * root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode* root, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second();
        int first,last;
        for(int i = 0; i < size; i++){
            int cur_id = q.front().second - mmin;
            TreeNode * node = q.front().first;
            q.pop();
            if(i == 0) first = cur_id;
            if(i == size - 1) last = cur_id;
            if(node -> left) q.push({node->left, cur_id*2+1});
            if(node -> right) q.push({node->right, cur_id*2+1});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
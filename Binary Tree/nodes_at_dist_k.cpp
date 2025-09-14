// nodes at a distance K from any given target node

// given will be a target node. and given a distance. print all the nodes at a distance of k from the given node
// do a BFS traversal
// keep a queue and the root in it
// pick root out and put the left and right of it
// map the parents also for these nodes
// keep doing iterations and keep mapping the parents
// once the traversal is done, we have all the parent pointers

// now we might have the address of the target node given to us, or we might only have the target value
// if we have only target value, then do any traversal to get the address of the target

// lets assume we have the address
// lets do a dfs traversal to move upwards and downwards
// while moving we will count the distance till k

// have a queue to put node, have a visited hash to keep track of visited nodes, and have a int dist variable
// target node dist is 0, visited true
// go to the upward node of targer node, downward node, left node, and right node. all these are at a dist of 1, increase dist to 1, add them to visited, 
// and add them to the queue
// in the next step, take all the nodes of queue together
// and move radially outwards of all the nodes, so that dist can increase
// once dist = k, dont move radially outwards anymore. return the elements left in queue as the answer

void markParents(TreeNode * root, unordered_map<TreeNode*, TreeNode*>, &parent_track, TreeNode* target){
    queue<TreeNode *> queue;
    queue.push(root);
    while(!q.empty()){
        TreeNode* current = queue.front();
        queue.pop();
        if(current->left){
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!queue.empty()){
        int size = queue.size();
        if(curr_level++ == k) break;
        for(int i = 0; i < size; i++){
            TreeNode * current = queue.front(); queue.pop();
            if(current->left && !visited[current->left]){
                queue.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                queue.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while(!queue.empty()){
        TreeNode* current = queue.front(); queue.pop();
        result.push_back(current->val);
    }
    return result;
}
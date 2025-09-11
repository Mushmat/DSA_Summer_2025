// look from the bottom
// in case of overlap, take the right one 
// we will again use verticals and level order traversal

// make the lines (root is on line 0, left decreases line by 1, right increases line by 1)
// take the last node on each line and return
// therefore a vertical order traversal can be done and the last node on every vertical can be returned

// have a queue and add (root, line = 0)
// keep a map with the (line, node)
// keeping a map stores the lines in sorted order
// start with the root, insert the root at line 0 in the map
// go to left, decrease line. insert in queue. add to the map 
// smrly go right, increase line, insert in queue, add to the map
// if in the map, there already exists a node on a particular line, and we are working with another node that we popped out from the queue
// that line's node is replaced by the new node (UNLIKE IN TOP VIEW IN WHICH WE DO NOT REPLACE)
// walk until queue empty

vector<int> bottomView(Node* root){
    vector<int> ans;

    if(root == NULL) return ans;
    queue<pair<Node*, int>> q;
    map<int,int> mpp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first();
        int line = it.second();
        mpp[line] = node->data;

        if(node -> left != NULL){
            q.push({node -> left, line - 1});
        }
        if(node -> right != NULL){
            q.push({node -> right, line +1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
// top view of the binary tree
// we will not see some of the nodes when we see it from top, considering it a 1d plane

// again we will define verticals 
// the first node in every vertical (every line) will come in the top view

// have a queue, in which (initial node, initial line) is stored
// have a map that stores (line, node) is stored (map stores everything in sorted fashion)
// in the map say we have (0, 1) where 0 is 0th line and 1 is the root, so we have the first node on line 0
// now we pop the node from the queue and go to its left. when we go left, line decreases by 1 and say the node value is 2. so the queue gets (2, -1)
// similarly for right we store (3, +1)
// now pick out (2, -1), store in the map that at line -1 we have 2
// first node at -1 is 2, we have seen a node at this line. move left to find an element on line -2
// move right to find line 0 which is not needed
// pick then the next pair from the queue and check for that

// once the queue is empty, the map stores the top view
// to get the top view from left to right, first element will be that value whose line is the most negative (say -2)
// smrly move ahead and get values for every line

vector<int> topView(Node * root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<Node*, int>> q;
    map<int, int> mpp;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end()) mpp[line] = node-> data;
        if(node -> left != NULL){
            q.push({node -> left, line-1});
        }
        if(node -> right != NULL){
            q.push({node -> right, line + 1});
        }
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
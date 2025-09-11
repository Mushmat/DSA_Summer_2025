// return the traversal we would get if we draw vertical lines over the tree
// for overlapping values return the smaller ones

// return the vector of vectors

// we can consider the vertical lines as lines on a number line
// the line passing through the root is the 0th line
// we can also consider the horizontal levels as level 0, level 1 etc
// by this we defined a two coordinate system where root is at vertical 0 level 0, ie 0,0
// the number to root's left is at vertical -1, level 1, ie -1,1
// multiple nodes can be at same coordinate (overlap)
// print elements by level of vertical
// print the vertical (say -2) all elements of this vertical. then of vertical -1 then 0 then 1 and so on
// so we iterate from the ascending order of the verticals (say x)
// and we iterate from the ascending order of the levels (say y)

// so we need to assign verticals and levels to every node and then print

// keep a queue
// store (node,vertical,level)
// keep a map (map<int, map<int, multiset<int>>>) this stores overlapping values correctly in a level for each vertical
// basically in the map defined above, first is the vertical, then in a vertical there can be many levels, then in a level there can be multiple nodes

vector<vector<int>> verticalTraversal(TreeNode * root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int,int>>> todo;
    todo.push({root, {0,0}});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode * node = p.first();
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node -> val);
        if(node -> left){
            todo.push({node -> left, {x + 1, y + 1}});
        }
        if(node -> right){
            todo.push({node -> right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;

}

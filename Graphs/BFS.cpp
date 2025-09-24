// Breadth first search
// level wise traversal basically

// a graph can be 0 or 1 based indexing, let us assume 1 based indexing WLOG
// We have the starting node. Therefore we assume it to be at level 0
// the children of this node are at level 1. grandchildren at level 2 and so on
// therefore levels increase by 1 as we go down
// If the starting node changes to some other node in the tree. then
// only the starting node will be on level 0, no else
// the nodes at a distance 1 of the starting node, will be on level 1
// those at dist 2 will be level 2
// therefore all nodes at equivalent distance will be at same level

// Take a queue DS
// input the starting node
// Take a visited array
// Put starting node as visited
// Whatever now is in the queue, take it out, perform. Keep taking out, performing, till the queue is not empty
// Therefore take out from queue, print it. Whatever you take out, add its neighbors to the queue (from adjacency list)
// mark them visited, and repeat

class Solution{
    public: 
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        int vis[n] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while(!q.empty()){
            int node = q.front();
            q.pop();    
            bfs.push(node);
            for(auto it: adj[node]){
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

// SC: O(3N) 
// TC: the for loop runs for all degrees, and queue itself runs for N times, therefore the total time complex is O(N + E)
// Depth first search
// Go as low (as deep - depth) for node, as possible
// Given the graph and starting node

// go to left of starting node, then keep going from the left to its left and its right
// so we keep traversing down (in depth)

// to go in depth, we will use recursion

// Create a visited array (based on what indexing the graph is)
// mark the starting node as visited
// whatever the starting node is, call a recursive dfs function in which 
// make node as visited
// add that node in the traversal (the one which is the output)
// pick up the adjacency list for that node
// and run a for loop for each node (for auto it: adj[node]) and then go to depth for each node

class Solution{
    private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        int vis[V] = {0}; //for 0 based indexing
        int start = 0;
        vector<int> ls;

        dfs(start, adj, vis, ls);
        return ls;
    }
}

// SC: O(N) + O(N) for vis array + O(N) for recursion stack space ~ O(N)
// TC: function is always called for a single node, and for any node it is called once. O(N + E) for directed graph
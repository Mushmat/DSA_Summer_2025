// detect cycle in a directed graph using DFS

// the simple dfs using visited array will not work here as this is a directed graph
// in a directed graph, on the same path we have to check if we are visiting a node again
// if a node is VISITED AGAIN ON THE SAME PATH, then there is a cycle

// keep a visited array and a path visited array
// start the dfs from any node, mark it visited and path visited
// call dfs for all its neighbors
// while coming back from a dfs call, mark the node as not path visited
// you can come back from a dfs call only when all its neighbors are visited
// if you find a neighbor which is already path visited and visited, then there is a cycle

class Solution{
    private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1; // mark visited
        pathVis[node] = 1; // mark path visited

        for(auto it: adj[node]){
            if(!vis[it]){ // not visited yet
                if(dfs(it, adj, vis, pathVis)) return true; // cycle found
            }
            else if(pathVis[it]) return true; // cycle found
        }

        pathVis[node] = 0; // backtracking, mark not path visited
        return false; // no cycle found
    }
    public:
    bool isCyclic(int V, vector<int> adj[]){
        int vis[V] = {0}; // visited array
        int pathVis[V] = {0}; // path visited array

        for(int i = 0; i < V; i++){
            if(!vis[i]){ // not visited yet
                if(dfs(i, adj, vis, pathVis)) return true; // cycle found
            }
        }
    }
}

// Time complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space complexity: O(V) for visited and path visited arrays and O(V) for recursion stack in worst case
// Overall space complexity: O(V)
// number of provinces
// given an undirected graph with V vertices
// two vertices u and v are said to belong to a single province if there is a path from u to v or v to u. find the number of provinces

// just return the number of connected components
// for this, we need to run dfs for all starting nodes
// the number of starting points are the number of provinces

// take a visited array
// for the first node till all V, if that node is not visited, then
// call dfs from the node
// it will mark all nodes in a connected component
// next dfs will start from the next unvisited node and hence the next province

class Solution{

    private:
    void dfs(int node, vector<int> &adjLs, int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
    public:
    int numProvinces(vector<vector<int>> adj, int V){
        // given is the adj matrix
        // we'll create a adj list from it

        vector<int> adjLs[V];
        for(int i = 0; i < V; i++){
            for(j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = 0;
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
    }
};


// SC: lets forget creating of adj list; hence, vis array takes O(n) and recursion stack space takes O(n)
// TC: DFS calls are made for all connected components; for each connected component, it is called for all nodes
// therefore it is called for all nodes in graph, hence O(V + E) asymptotically
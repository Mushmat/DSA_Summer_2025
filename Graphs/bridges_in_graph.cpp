// DID NOT UNDERSTAND PROPERLY

// A bridge is an edge, when removed, breaks a component into two or more separate components.

// maintain two arrays, one for DFS time of insertion, and one for the lowest time of insertion of all adjacent nodes apart from parent

// the step at which we reach the nodwe will be the time of insertion. 
// the lowest time of insertion finds the lowest amount

// visit nodes, mark them visited, and insert their times
// if for a node both times are not same, that means it can be removed. as this is not a bridge. it can be reached from other side as well

// nodes, once visited, pick their adjancent lower times in the second array, lowest time of insertion

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it: adj[node]){
        if(it == parent) continue;
        if(vis[it] == 0){
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            // node --- it, is this a bridge?
            if(low[it] > tin[node]){
                bridges.push_back({it, node});
            }

        }
        else{  
            low[node] = min(low[node], low[it]);

        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    vector<int> adj[n];
    for(auto it: connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;

    dfs(0, -1, vis, adj, tin, low, bridges);

    return bridges;

}
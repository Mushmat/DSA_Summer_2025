// DID NOT UNDERSTAND PROPERLY

// articulation point: nodes on whose removal the graph breaks into multiple components

// just as in the question where we removed bridges, there are two arrays
// one for time of insertion
// one for lowest time of insertion, but this time, apart from parent, and also APART FROM VISITED NODES

// if(low[it] >= tin [node]) && parent != -1, this is the updated condition for articulation point, different from bridges

int timer = 0;
void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
        }
        else{
            low[node] = min(low[node], tin[node]);
        }
    }
}

vector<int> articulationPoints(int n, vector<int> adj[]){
    vector<int> vis(n,0);

    int tin[n];
    int low[n];

    vector<int> mark(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(mark[i] == 1){
            ans.push_back(i);
        }
    }

    if(ans.size() == 0) return {-1};
    return ans;
}
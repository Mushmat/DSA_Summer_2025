// given a DAG, find the shortest path from the source (0) to all the vertices
// there can be weights (if no weights are there, default is 1)
// source will always be 0
// till n-1 nodes, find the shortest dist to travel

// we'll applying topo sort + relaxation of edges

// in adjacency list, we will store pair of (adjancent node, weight of that edge)
// let us try to solve this problem for any source (not just 0)

// step 1 is to do the topo sorting 
// say using the DFS method
// once we have a valid topo sort
// step 2 is to take out nodes from the stack one by one, and relax the edges
// WHAT DOES RELAXING MEAN? 
// declare a distance array and mark everything as infinity 
// go to the source node, and make its distance as 0
// whatever is on the stack's top, take it out.
// node = stack top
// check its distance
// find the adjacent nodes of this node
// try to go there. 
// store the better dist required to go to that node
// repeat this until stack is empty

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<int> edges[]){
    vector<pair<int,int>> adj[N];
    for(int i =0; i < M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
    }

    int vis[N] = {0};
    stack<int> st;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }

    // do the distance thing

    vector<int> dist(N);
    for(int i = 0; i < N; i++){
        dist[i] = INT_MAX;   
    }
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}
// given an undirected graph having unit weights, find the shortest distance from source to all the points, if not there, return -1

// apply BFS
// declare a queue and store {source, dist} eg {0,0}
// keep a dist array init to infinity
// assign the dist of source as 0
// pick out from the queue
// for this node, go to its adjancent nodes
// add a distance 1 to go to these adjancent nodes
// and add these adjacent nodes to the queue
// continue this
// keep adding the distance +1 to reach to each level 
// keep updating the best distances in the distance array
// once queue is empty, if any node was unreachable, that node's dist would have been INT MAX
// return the dist arr by replacing INT MAX by -1

vector<int> shortestParth(vector<vector<int>> &edges, int N, int M, int src){
    vector<int> adj[N];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[N];
    for(int i = 0; i < N; i++){
        dist[i] = 1e9;
    }

    dist[src] = 0;

    // in queue we are storing just the node, dist we can take from dist[] array

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(N,-1);
    for(int i = 0; i < M; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }

    return ans;
}
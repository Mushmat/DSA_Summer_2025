// another algorithm for shortest path
// shortst path from src to all the other nodes
// it is here because dijkstra cannot determine shortest path for negative edges
// also for negative cycles dijkstra cannot detect
// Bellman ford is used only in DIRECTED GRAPH
// you can easily convert an undirected graph to a directed one
// bellman ford can also be used to detect negative cycles
// given is source, and the edges u v with their weights wt

// relax all the edges n-1 times, sequentially
// relax: if there is a dist array, and if(dist[u] + wt < dist[v]) then dist[v] = dist[u] + wt
// initialize a dist array with inf, and source as 0
// for n = 6, we need to do 5 relaxations
// for first iteration, go across all the edges, and relax
// and so on for 5 iterations
// after all 5 iterations, the dist array will store the shortest distances

// why n-1? how to detect negative cycles?
// iterations are n-1, because the edges can be in any order, it might be possible that in every iteration, we relax the edges only at the end. so we need minimum n-1 iterations
// to relax every edge, otherwise it might be possible that some edges are not relaxed
// to detect negative cycles: run the nth iteration, if on this nth iteration, the distance array gets updated, then a negative cycle exists
// because we only need n-1 iterations to get the shortest distances, so there should be no reductions on nth iteration

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i = 0; i < V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // nth iteration to check negative cycles, return -1 as an array if neg cycle exists
    for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }

    return dist;
}
// number of ways to arrive at destination
// a city consists of n intersections numbered from 0 to n-1
// it has bidirectional roads between some intersections
// inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections
// given an integer n and a 2d integer array roads where roads[i] = ui, vi, timei means there is a road between intersections ui and vi that tkaes timei minutes to travel. 
// in how manyw ays can we travel from intersection 0 to n-1 in shortest amount of time

// return the number of ways 

// keep a ways array initialized to 0, mark the source as 1 because only 1 way to start from the source
// keep a dist array marked to inf, mark the source as 0
// keep a min heap with {dist, node}
// input {0,0} to the PQ
// update the dist array when you travel to another node with lesser dist
// update the ways array accordingly

int countPaths(int n, vector<vector<int>> &roads){
    vector<pair<int,int>> adj[n];
    for(auto it: roads){
        adj[it[0]].push_back(it[1],it[2]);
        adj[it[1]].push_back(it[0],it[2]);
    }

    priority_queue<pair<int,int>,vector<pair,int,int> >, greater<pair<int,int>>> pq;
    vector<int> dist(n, 1e9), ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    int mod = (int)(1e9 + 7);
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edW == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1] % mod;
}
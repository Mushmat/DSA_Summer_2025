// there are n cities and m edges connected by some number of flights. 
// given an array flights where flights[i] = [fromi, toi, pricei], indicates a flight from and to with price
// given three integers src, dst, k, return the cheapest price from src to dst with at most k stops. if no such route, return -1

// the graph is directed
// a simple dijkstra fails here
// because priority queue will always look for the better dist and hence we might ignore possibility of a cheapest flight in future
// therefore we cannot store everytthing in terms of dist
// soln: store everything in terms of stops
// first priority of judgement is the number of stops, not the distance

// use PQ as {stops, node, dist}
// we can also use a queue because the increment of stops is constant 

int cheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K){
    vector<pair<int,int>> adj[n];
    for(auto it: flights){
        adjpit[0]].push_back({it[1], it[2]});
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > K) continue;
        for(auto iter: adj[node]){
            int adjNode = iter.first;
            int edW = iter.second;

            if(cost + edW < dist[adjNode] && stops <= K){
                dist[adjNode] = cost + edWl
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}

// since no PQ is used, log V is dropped in the TC
// TC = size of flights

// there are n cities numbered from 0 to n-1
// given array edges where edges[i] represent a biredectional and weighted edge between cities fromi and toi, and given integer distance threshold
// yo need to find out a city with the smallest number of cities that are rechable through some path and whose distance is at most THRESHOLD DISTANCE
// if there are multiple such cities, out answer will be the city with the greatest number

// we can distance from any source to all the cities using floydd warshal (or dijkstra as well if there are no negative cycles)
// so simply get the floyd warshall matrix for each city
// keep a counter = 0 and counterMax = cities + 1, keep city = -1 (the answer)
// update counterMax and city when we get a better accetable answer

 int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold){
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    for(auto it: edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int k = 0;k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for(int city = 0; city < n; city++){
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++){
            if(dist[city][adjCity] <= distanceThreshold) cnt++;
        }

        if(cnt <= cntCIty){
            cntCity = cnt;
            cityNo = city;
        }
    }

    return cityNo;
 }
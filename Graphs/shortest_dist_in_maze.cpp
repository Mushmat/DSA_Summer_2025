// Shortest distance in a binary maze
// given an n x m matrix where each element is either 0 or 1
// find shortest dist between a given source to a destination cell
// you can only move through 1s
// if not possible, return -1
// from one cell to other cell, dist taken is 1
// only move in up down left right
// since this is a shortest path problem, lets try dijkstra's algorithm

// take a distance array of 2d size initally empty and a priority queue to store {dist, {row, col}}
// mark all nodes in dist as infinity other than source, mark the source as 0
// put the source in the Priority queue and start dijkstra
// traverse using the source node, go to up down left right and update their distance and put in the PQ
// as done in dijkstra, only update distance if the new distace is better (lesser than the previous one)
// since the nodes are travelling through their adjacent nodes, which is a distance of 1. then, when we are storing in the PQ, their distances are incrementing by 1 only
// so we do not need a PQ, because everyone is increasing by a constant unit distance, so it is by default being stored correctly
// therefore we can simply convert the PQ to a simple Queue
// this omits the additional log N time

// then, take the next guy out, and continue travelling
// do not go to neighbors which are 0

// to travel up down left right efficiently, without adj list, 
// create it
// dr[] = {-1, 0,1,0}
// dc[] = {0,1,0,-1} this way we can iterate

// eg row - 1, col
// row, col + 1
// and so on

public:
    int shortestPath(vector<vector<int>> &grid, pair<int,int> source, pair<int, int> destination){
        queue<pair<Int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i  = 0; i < 4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < n && newc >=0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1 + dis;
                    if(newr == destination.first && newc = destination.second) return dis + 1;
                    q.push({1+dis, {newr, newc}});
                }
            }
        }

        return -1;
    }
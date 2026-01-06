// you are a hiker
// given heights which is a  2d array where heights[row][col] represents the height of the cell. 
// you are at (0,0)
// you hope to travel to the botton right cell ( rows - 1, columns - 1)
// move up down left right
// give the route that minimises efforts (return the minimum effort)

// a route's effort is the maximum asbsolute difference in heights between two consecutive cells of the route
// so for us, out of all the differences, we need to minimize the maximum difference. the max difference is the effort
// eg is we go via 1->2->2->2->5, the diff is 3
// however if we go via, 1 3 8 2 5, the diff is 6. so the first route is more viable and the ans will be 3

// lets use dijkstra
// take the PQ with {diff, row, col} as minimum heap
// take a diff grid, mark everything as inf, apart from source which is marked 0
// put the source in the PQ
// for one path, the effort is max of all differences
// now traverse up down right left 
// add the node to the min heap and update the diff in the diff grid
// do not conclude the first time you reach the destinaiton because there might be someone better

int minimumEffort(vector<vector<int<< &heights){
    // {diff, {row, col}}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> >, greater<pair,Int,pair<int,int>>>> pq;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push(0,{0,0});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first();
        int row = it.second.first;
        int col = it.second.second;

        if(row ==  n-1 && col == m-1) return diff;

        for(Int i = 0; i < 4; i++){
            int newr = row + dr[i];
            int newc = col + dr[i];
            if(newr >= 0 && newc >= 0 && newr < n && newc < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[newr][newc], diff));
                if(newEffort < dist[newr][newc]){
                    dist[newr][newc] = newEffort;
                    pq.push({newEffort, {newr, newc}});
                }
            }
        }
    }

    return 0;
}   
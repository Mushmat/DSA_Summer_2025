// this is an online query problem
// given a query, tell the answer
// 0 is sea, 1 is island
// if someone gives (0,0) means create island at (0,0)
// if there is an island already, dont place another one
// a group of island includes islands that share a side (up down left right, NOT DIAGONAL)
// an island included in a group once is then the part of the group

// since it is a dynamic connection at each point, let us use DISJOINT SET
// represent every cell as a node here
// for a matrix, start with (0,0) as 0th cell and mark all cells. for eg a 5x4 matrix, cells will be marked from 0 to 19
// to compute the total nodes therefore: (row, col) = (row x m) + (col) [this is the node number for each column]
// keep a counter to track number of groups
// for every island, look to its up down left right to find out whether there is a sharing or not
// when there is a sharing, connect those islands in the disjoint set and decrease the count
// do not connect the islands when the ultimate parent is same, because then they are already connected

class DisjointSet{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;

        }
    }

    int findUPar(int node){ // path compression
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u = ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    
    void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u = ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] == ulp_v;
                size[ulp_v] += size[ulp_u];

            }

            else{
                parent[ulp_v] == ulp_u;
                size[ulp_u] += size[ulp_v];
            }
    }

};

class Solution{

    boolean isValid(int adjr, int adjc, int n, int m){
        if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m) return true;
        else return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;

        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            // row -1, col
            // row, col + 1
            // row + 1, col
            // ro1, col -1

            int dr[] = {-1, 0, +1, 0};
            int dc[] = {0, 1, 0, -1};

            for(int ind = 0; ind < 4; ind++){
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];

                if(isValid(adjr, adjc, n, m)){
                    if(vis[adjr][adjc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }

                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }

};
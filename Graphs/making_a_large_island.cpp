// given an n x n binary grid. A grid is said to be binary if every valye in the grid is either 1 or 0
// you can change at most one cell n grid from 0 to 1
// you need to find the largest group of connected 1s
// two cells are said to be connected if both are adjacent to each other and have same value

// connections allowed only from up down left right
// we have components in the adj matrix
// so it is just like a graph where when we convert 0 to 1, we dynamically change the graph
// so we'll use disjoint set

// we have n x n matrix
// as we have matrix, we need to map the cells to individual nodes
// each node will be represented as 0,1,2....2n-1
// so convert n x n matrix to cell numbers first using row*m + col

// naive way is to convert each 0 to 1 and check their left right up down for connected component and get the size of the complete component
// but when you connect to a component, how to determine that component's size?

// therefore draw the disjoint set for the given matrix
// use union by size to have the size of each component stored in the size array
// so that we can get the size easily

// now, stand at the first zero. look at the right for valid components, figure its size and add that size. look to the left and if ultimate parent is not same, add that size. 
// if the ultimate parent is same, dont add that size
// look up and down and repeat the same
// repeat this for all 0s and ultimately return the max size

// to compare for ultimate parent, maintain a set to store the ultimate parents
// while comparing left right up down for any 0, check in the set for repeat ultimate parents
// the set will not accept duplicate ultimate parents, so only unique components are counted.

    #include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    

public:
    vector<int> rank, parent, size;
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

    // union by size
    // we have a size array of nodes size
    // and a parent array
    // initially size array is marked as 1 for all nodes as each node is itself a component
    // repeat similar process as in union by rank
    // size increases when number of nodes increases in the component

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

class SOlution{

    boolean isValid(int newr, int newc, int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

    int maxConnection(vector<vector<int>> &grid){
        int n = grid.size();
        DisjointSet ds(n * n);
        // connecting component
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};

                for(int ind = 0; ind < 4; ind++){
                    int newr = row + dr[ind];
                    int newc = row + dc[ind];

                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);

                    }
                }
            }
        }
        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                set<int> components;
                for(int ind = 0; ind < 4; ind++){
                    int newr = row + dr[ind];
                    int newc = row + dc[ind];

                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }

                int sizeTotal = 0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        // below is a safety check for the case where everything is 1
        for(int cellNo = 0; cellNo < n * n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }

};
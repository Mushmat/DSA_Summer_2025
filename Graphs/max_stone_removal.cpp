// there are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone
// You need to remove some stones
// a stone can be removed if it shares either the same row or the same column as another stone that has not been removed
// given an array stones of length n where stones[i] = xi,yi represents the location of ith stone, return the max possile number of stones u can remove

// we can maybe try connecting those stones which lie in the same row, or same column to each other
// a stone that has no connections (no other stones in the row or col) would act as a single node
// from a connection of nodes, we cannot remove the last stone, as last stone does not have any matching neighbor stone

// therefore whatever component size is there, say it is z, then we can remove z - 1 stones
// and we can sum it over all components to get the number of stones we can remove
// if we matheatically look, the answer will be n -  no of components (these many stones can be removed)
// so our goal is to figure out number of components
// let us use disjoint set to make the components and connect them

// convert the rows and columns to nodes in disjoint set
// say there are 5 rows, so nodes in DS are 0 1 2 3 4, each representing a row
// say there are 4 columns, so nodes in DS are now, 5 6 7 8 (shifted), each reprsenting a column. 5 represents 0th column... and so on

// start with 0th row 0th column, if there is a stone, then take everyone on 0th row and 0th column and combine them
// so if there is a stone at (0,0), connect 0 and 5 in the disjoint set (0 -> 0th row, 5 -> 0th column)
// if there is a stone at (0,2), connect 0 and 7
// and similarly continue for all stones
// after connecting all nodes in the disjoint set, the nodes that are single (not connected to any other node) can be discarded
// only those nodes that have children, will be valid
// and the number of ultimate parents in the disjoint set = the number of components in the graph

#include <bits/stdc++.h>
using namespace std;

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

class Solution{

    int maxRemove(vector<vector<int>> &stones, int n){
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it: stoneNodes){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }

        return n - cnt;
        

    }

};
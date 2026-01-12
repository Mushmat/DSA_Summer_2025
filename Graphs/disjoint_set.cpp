// does two nodes belong to the same component?
// disjoint set gives the answer for this question in CONSTANT time
// usually used in dynamic graphs
// Disjoint set gives two options: findParent(), or union()
// union() can be done by rank or by size

// initially all nodes are single, connected to none
// union() will do the connections. eg if there is an edge between 1 and 2, then union connects 1 and 2

// lets do union by rank first
// we need two arrays: rank array and parent array
// initially, rank of all nodes are 0
// parent of all nodes are themselves

// rank means number of nodes beneath the node (height basically)
// union(u,v) happens like:
// -> find ultimate parent of u & v, let them be pu and pv
// -> find rank of those ultimate parents pu and pv
// -> connect smaller rank to larger rank
// -> if ranks are equal, connect anyone to anyone
// after connecting two nodes, update the rank and parent array

// when the ultimate parent of two nodes are  same, they belong to the same component
// findParent() returns the ultimate parent of the node 

// we do path compression to just keep the ultimate parents of all nodes
// link all nodes to its ultimate parent so that we get the ultimate parents, when needed, fast
// we do not shrink the rank while path compressin

// works in time O(4 alpha) where alpha is almost 1

// PATH COMPRESSION:
// findParent will return findParent(parent(u)).
// basically recursing until u == parent(u)

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

// union by size
// we have a size array of nodes size
// and a parent array
// initially size array is marked as 1 for all nodes as each node is itself a component
// repeat similar process as in union by rank
// size increases when number of nodes increases in the component

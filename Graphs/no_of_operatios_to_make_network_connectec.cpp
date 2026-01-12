// given a graph with n vertices and m edges
// you can remove one edge from anywhere and add that edge between any two vertices in one operations
// find the minimum number of operation that will be required to make the graph connected

// two disjoint components can be connected by connecting any of the two nodes from both components
// if there are 5 components, then we need 4 edges to connect all these to make a single connected graph
// therefore for n components, we need n-1 edges
// 1 component therefore requires no edges to be connected

// therefore we can first figure out number of connected components
// then we will need number - 1
// this is the minimum number of edges needed to connect this
// so simply, get the number of connected components and subtract 1

// which edges can be taken out to make two components connected?
// we can take those edges which does NOT disconnect the graph after taken out
// therefore extra edges can be used

// so
// count the extra edges
// after doing that, since the ans is number of connected components - 1, then if the extra edges is greater than this, then we can do it
// else we cannot, because we dont have those many exxtra edges to connect every component

// make the disjoint set for the graph
// whenever the ultimate parent is same but we have an edge to connect, then that edge is an exxtra edge as both nodes already have the same ultimate parent
// by this means we'll get the number of extra edges as well

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

}

class Solution{
    int solve(int n, vector<vector<int>> &edges){
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) ==  ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int cntC = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) cntC++;
        }

        int ans = cntC - 1;
        if(cntExtras >= ans) return ans;
        else return -1;
    }
}
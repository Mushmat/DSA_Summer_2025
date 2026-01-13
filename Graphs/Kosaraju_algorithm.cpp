// find strongly connected components (SCC) using Kosaraju Algorithm
// no of SCC can be asked
// print SCC can also be asked

// SCC are only valid for DIRECTED GRAPHS
// a strongly connected component is a component where any two pair of vertices can reach both ways. if a can reach to b, then b can also reach to a
// a single node is also an SCC

// just reverse the bridge edges and then DFS only visits each component
// but since we do not know the bridges, simply reverse all the edges. as SCC will remain SCC no matter what, and bridges wil get reversed

// so first step, sort all the edges according to their finishing time
// second step, reverse the graph
// third step, do the dfs

// so start the dfs from 0, do the dfs
// once a node finishes (no further nodes to traverse in the dfs), store that somewhere
//store it in a stack so that the top guy finishes at the last.

// now reverse the graph

// first SCC will have the top most element of the stack as it finished last
// so take the first element out of the stack and do dfs
// store the dfs traversal (this is one SCC)
// dont do dfs for visited nodes in the stack
// repeat

// after dfs is done, the number of dfs calls are the number of SCCs
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs3(int node, vector<int> &vis, vector<int> adjT[]){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs3(it, vis, adjT);
        }
    }
}
int kosaraju(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }

    vector<int> adjT[V]; // stores reversed graph
    for(int i = 0; i < V; i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node, vis, adjT);
        }
    }

    return scc;
}

// TC: O(V+E)
// SC: O(V+E)
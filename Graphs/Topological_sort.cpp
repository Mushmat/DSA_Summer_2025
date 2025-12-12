// Topological sorting using DFS
// Can only be applied to Directed Acyclic Graphs (DAGs)
// A linear ordering of vertices such that if there is an edge between u & v, u appears before v in the ordering
// why only in DAGs? in an undirected graph, if there is an edge between u and v, u can appear before v or vice versa
// in a directed graph, if there is a cycle, there is no way to order the vertices such that for every directed edge u -> v, u appears before v

// Given a DAG and its adjacency list
// declare a visited array, initialize all vertices as not visited
// start the dfs call from 0 and declare a stack and mark 0 visited
// if it has no adjacent nodes, come back and put the 0 in the stack
// if it has adjacent nodes, call dfs for all its adjacent nodes
// once a node comes where there are adjacent nodes, call dfs for the adjacent nodes
// dont call for nodes already visited
// once all adjacent nodes are visited, push the node in the stack
// finally, pop all elements from the stack and print them

class Solution{

    private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V] = {0};
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
}

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space Complexity: O(V) for the visited array and the stack
// Auxiliary Space: O(V) for the stack space used in recursion
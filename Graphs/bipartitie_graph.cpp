// BFS first
// A bipartite graph is a graph such that when we color the graph with 2 colors, no two adjacent nodes have the same color
// if I am able to color the graph acc to the above definition, then the graph is bipartite
// if I am not able to color the graph acc to the above definition, then the graph is not bipartite
// a graph that does not have a cycle, that is A LINEAR GRAPH, can always be colored with 2 colors, so it is always bipartite
// a graph that has a cycle, but the cycle is of even length, can always be colored with 2 colors, so it is always bipartite
// a graph that has a cycle, but the cycle is of odd length, cannot be colored with 2 colors, so it is not bipartite

// let us do this with BFS
// take a queue, take a color array with all nodes and initialized to -1 indicating not colored yet
// color it with color 0 or color 1
// start with any node and put that in the queue
// assign it a color, WLOG, color 0
// iterate the queue and pick the topmost element out
// check all its neighbors using the adjacency list
// if the neighbor is not colored, color it with the opposite color and push it in the queue
// again get the next guy from the queue, check its neighbors, if the neighbor is already colored (a parent) and is of opposite color, leave, color other neighbors with opposite color and push in queue
// if the neighbor is already colored, and is of same color, then return false, since it is not bipartite
// continue this until the queue is empty and if we have not returned false, return true

class Solution{
    // colors a component of the graph
    private:
    bool check(int start, int V, vector<int> adj[], int col[]){
        queue<int> q;
        q.push(start);
        
        color[start] = 0; // color with 0 or 1
        while(!q.empty()){
            int node = q.front;
            q.pop();

            for(auto it: adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node]; // color with opposite color
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }

        return true;
    }
    public:
    bool isBipartite(int V, vector<int> adj[]){
        int color[V];
        for(int i = 0; i < V; i++) color[i] = -1; // not colored yet
        for(int i = 0; i < V; i++){
            if(color[i] == -1){ // not colored yet
                if(!check(i, V, adj, color)) return false;
            }
        }
        return true;
    }
}

// DFS approach
// lets solve it for one component
// take a color array with all nodes and initialized to -1 indicating not colored yet
// color it with color 0 or color 1
// call dfs from start node, color it with color 0
// mark it visited
// call dfs for all its neighbors
// if the neighbor is not colored, color it with opposite color and call dfs for it
// if the neighbor is already colored, and is of same color, then return false, since it is not bipartite

class Solution{

    private:
    bool dfs(int node, int col, int color[], vector<int> adj[]){
        color[node] = col;
        for(auto it: adj[node]){
            if(color[it] == -1){
                if(!dfs(it, !col, color, adj)) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }
    public:
    bool isBipartite(int V, vector<int> adj[]){
        int color[V];
        for(int i = 0; i < V; i++) color[i] = -1; // not colored yet
        for(int i = 0; i < V; i++){
            if(color[i] == -1){ // not colored yet
                if(!dfs(i, 0, adj, color)) return false;
            }
        }
        return true;
    }
}

// TC: O(V + E) for both BFS and DFS
// SC: O(V) for both BFS and DFS
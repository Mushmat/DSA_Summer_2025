// detect a cycle in an undirected graph using BFS
// a cycle is when you start from a node and comeback to the same node

// create an adjacency list first
// if we collide at a place during traversal there is a cycle. because we had started at two diff parts

// take a queue and push the starting node and its parent
// create a vis array and mark start at 1
// take the node out 
// this node can go to its neighbors
// push the neighbors with the parent in the queue
// mark visited
// again get next guy and visit neighbors 
// continue this until
// you reach a node who has already been visited but the node from which you visited it is not the parent
// thereby there is a cycle since someone has already visited this node and now we are visiting it again

class Solution{
    private:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V] = {0};
        for(int i = 0; i < V; i++){ // check for all components
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
}

// TC: O(V + 2E)
// SC: O(N)

// --------------------------------------------------------------------------------------------------------------------------------------
// Now let us do the same question by DFS
// again carry the parent
// start the dfs from the starting node 
// mark visited
// the logic is again same here, if you visit a node that was already visited but now the parent is different that means its a repeat
// hence a cycle is present
// return true if a cycle present

class Solution{

    private:
    bool dfs(int node, int parent, vector<int> vis[], vector<int> adj[]){
        vis[node] = 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adj) == true) return true;
            }
            else if(adjacentNode != parent) return false;
        }
        return false;
    }

    public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V] = {0};
        for(int i = 0; i < V; i++){ // check for all components
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
}


// TC: O(V + 2E)
// SC: O(N)

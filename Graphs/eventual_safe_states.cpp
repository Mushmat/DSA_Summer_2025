// eventual safe states
// given a directed graph of V vertices and E edges
// Each node is labelled with a distinct integer in the range 0 to V-1
// A node is a terminal node if there are no outgoing edges
// A node is a safe node, if every possible path starting from that node leads to a terminal node
// return an array containing all the safe nodes of the graph

// safe node must not come back to itself
// so if there is a cycle, then all nodes in that cycle are not safe nodes
// all paths from a safe node must lead to a terminal node
// anyone who is a part of a cycle is not a safe node
// anyone who can reach a cycle is also not a safe node

// create the visited array and path visited array
// initialize all to 0
// if a dfs call is completed then only it is a safe node, otherwise it is not
// if a dfs call is not completed, it indicated that it is part of a cycle or can reach to the cycle
// start dfs call and mark visited and path visited
// call dfs for all its neighbors
// if there is no cycle, all the nodes in that dfs call are safe nodes
// if there is a cycle, all the nodes in that dfs call are not safe nodes
// while coming back from a dfs call, mark the node as not path visited

private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]){
        vis[node] = 1; // mark visited
        pathVis[node] = 1; // mark path visited

        for(auto it: adj[node]){
            if(!vis[it]){ // not visited yet
                if(dfs(it, adj, vis, pathVis)){
                    check[node] = 0; // if cycle found, then it is not a safe node
                    return true; // cycle found
                } // cycle found
            }
            else if(pathVis[it]){
                check[node] = 0; // if cycle found, then it is not a safe node
                return true; // cycle found
            } // cycle found
        }
        check[node] = 1; // if we are able to come out of dfs call, then it is a safe node
        pathVis[node] = 0; // backtracking, mark not path visited
        return false; // no cycle found
    }
public:
vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    int vis[V] = {0}; // visited array
        int pathVis[V] = {0}; // path visited array
        vector<int> safeNodes;
        int check[V] = {0}; // to check if a node is safe or not
        for(int i = 0; i < V; i++){
            if(!vis[i]){ // not visited yet
                dfs(i, adj, vis, pathVis, check);
            }
        }
        for(int i = 0; i < V; i++){
            if(check[i] == 1) safeNodes.push_back(i); // if pathVis is 0, then it is a safe node
        }
        return safeNodes;
    }

// Time complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space complexity: O(V) for visited and path visited arrays and O(V) for recursion stack in worst case


// USING BFS -- TOPO SORT

// again safe nodes are those nodes who are not a part of a cycle and cannot reach a cycle
// count the outdegrees
// the node with outdegree as 0 is a terminal node and hence is a safe node
// since topo sort deals with indegrees
// lets reverse the edges
// therefore reverse all the edges
// now, get all the nodes with indegree 0 and remove the edges on neighbors (topo sort algo)
// in the reversed graph, the nodes that had outdegree as 0 will not have indegree as 0
// the nodes with indegree 0 is a terminal node
// define a queue and put the terminal node
// now do the bfs
// pull out the first node from queue
// its a safe node
// the nodes that are connected this node, remove the path. if the indegree of that node becomes 0 add to queue
// repeat
// only put in the queue when indegree is 1
// once queue is empty, you have the safe nodes. the nodes that are not safe, are never executed

vector<int> eventualSafeNode(int V, vector<int> adj[]){

    vector<int> adjRev[];
    int indegree[V] = {0};
    for(int i = 0; i < V; i++){
        for(auto it: adj[i]){ //edge is from i to it
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]){
            indegree[it]--;
            if(indegree[it]== 0) q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;

}


// MINIMUM SPANNING TREE 
// what is a spanning tree? Given an undirected weighted graph, with n nodes and m edges
// then a spanning tree is a tree with n nodes and N-1 edges such that all nodes are reachable from each other
// a minimum spanning tree is one of the spanning trees where the sum of weights is minimum
// any tree has only one minimum spanning tree

// Prim's Algorithm:

// prim's algorithm gives the min sum as well as the MST
// need a PQ and a visited array
// mark vis as 0 for all nodes
// keep a variable sum = 0
// keep a MST list to store MSt

// start with any node
// insert in priority queue with {wt, node, parent}, if starting with 0, then {0,0,-1}
// dont mark the source visited
// start the iteration and pick out from the PQ
// whenever parent is -1, this is the first node. so dont add in the MST
// now mark it as visited
// standing at this node, look at the adjacent nodes
// go to the unvisited nodes and put it in the PQ
// DO NOT MARK THE NODES VISITED WHILE PUTTING IN THE PQ
// MARK THEM VISITED WHEN YOU PICK THEM OUT FROM THE PQ
// npw from the PQ, pick out the next element
// if parent is not -1, put it in the MST. since we pick the minimum weight edge first (because it is a PQ), we will get the correct answer)
// continue this
// if a node is already visited when you pick it out from the PQ, then dont add that weight to our sum, and dont run our algo on that. just pick the next PQ element
// once the PQ is empty, the algo is over. you have the answers now

int spanningTree(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    vector<int< vis(V,0);
    pq.push({0,0});  // we are not carrying the parent here as we do not need to return the MST itself in the ques
    sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        for(auto it: adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }

    return sum;
}

// TC: ElogE
// SC: E
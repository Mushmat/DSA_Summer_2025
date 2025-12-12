// Topological sorting using Kahn's Algorithm (BFS approach)

// declare a queue
// declare an indegree array
// indegree is the number of incoming edges to node i
// insert all nodes with indegree 0 into the queue
// take the first element out, all those elements which are connected to it, reduce their indegree by 1
// pick the next element and do the same
// if the indegree of any of those elements becomes 0, insert them into the queue
// repeat until the queue is empty
// how to figure out indegree? By adjacency list
// is u has a directed edge to v, then indegree[v]++

class Solution{
    public:
    
    vector<int> topoSort(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in the topo sort, so remove from indegree
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }
}
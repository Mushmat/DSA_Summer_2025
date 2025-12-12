// detect a cycle in a directed graph using BFS algorithm
// we know that Topo Sorts are only applicable on a DAG

// since a topo sort is not possible for cyclic graphs, still apply Topo Sort
// find the topo sort for the graph
// write the indegrees of the nodes
// start with the queue DS and do the kahns algorithm
// if we do not produce the topo sort ordering of size N where N is the number of nodes, then there is a cycle
// if the topo sort has exactly N elements then it is a DAG
// if anything less or more, then it has a cycle

bool isCyclic(int V, vector<int> adj[]){
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
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            // node is in the topo sort, so remove from indegree
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(cnt == V) return false;
        return true;
}
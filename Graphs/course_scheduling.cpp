// Course Scheduling I and II
// Given a total of N tasks, labeled from 0 to N - 1. Some tasks may have prerequisites, to do task 0 you might have to first complete task 1
// this is expressed as [0,1]
// given the total number of tasks N, and a list pf prerequisite tasks P, find if it possible to finish all tasks

// basically if [a,b] is a pair, b needs to be done before a, then there must be an edge from b to a in the adjacency list
// in this question, we will assume that if [a,b] is given, a needs to be done before b

// return yes or no if the tasks can be perfomed

// We should use the topological sorting
// if there is an edge between u -> v, meaning u should be before v, then we can say that in the linear ordering, u will be performed before v
// to solve this, either detect if graph has a cycle (since topo sort works on DAG), using BFS Topo Sort

// if it does not have, then a linear ordering is possible

bool isPossible(int V, vector<pair<int,int>> & prerequisite){
    vector<int> adj[V];
    for(auto it: prerequisite){
        adj[it.first].push_back(it.second);
    }

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

        if(topo.size() == V) return true; // no cycle
        return false;
}

// now the second variant 
// here the ordering has been reversed [0,1], do 1 to do 0
// in this we need the order also
// return one correct answer, return [] if not possible

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites){
    vector<int> adj[V];
    for(auto it: prerequisite){
        adj[it[1]].push_back(it[0]); // order reversed
    }

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

        if(topo.size() == V) return topo; // no cycle return order
        return {};
}
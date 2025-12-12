// Dijkstra's Algorithm Using Priority Queues
// given a source node (maybe 0), find the shortest path to reach all other nodes

// WILL NOT WORK FOR GRAPHS THAT HAS A NEGATIVE WEIGHT CYCLE, OR NEGATIVE WEIGHT

// represent the graph as an adj list, with pairs, such that {node, weight} is stored.
// eg 0 -> {1,4}
// have a minimum heap data structure that will store {dist, node}
// the shorter dist will be at the top in the ds
// if the dist is equal, the shorter node will be at the top
// have a distance to keep track of the dist
// source node cna be anything say it is 0
// first step: dist of source node is 0
// assign infinity to rest nodes
// add {0,0} to the min heap
// start the iteration, take the top most from the priority queue (min heap)
// we have a dist of 0, to reach 0
// check where can 0 go. say it can go to node 2 with wt 4, and node 1 with wt 4
// therefore i can go to node 1, at a distance 0 + 4
// therefore i can go to node 2, at a distance 0 + 4
// these distances are better than previous dist (previously inf)
// therefore update the dist array, and put the {dist, node} it in the priority queue
// next, on the top of the min heap there will be {4,1}
// pick that out, and go to its neighbors. neighbors say are 0 and 2
// going to 0 now takes dist 4 + 4 = 8, not considerable
// going to 2 takes dist 4 + 2 = 6, not considerable
// now pick out {4,2} and work ahead
// only add in the prio queue when the node's dist is updated in the array

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for(int i = 0; i < V; i++) dist[i] = 1e9;

    dist[S] = 0;
    pq.qush({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// TC: O(E log V)

// Dijkstra's Algorithm using a SET

// a set stores the unique value, that too in ascending order
// its similar to hence, a priority queue
// the topmost element, hence, will always be the minimum guy
// put the source dist to 0, and everything else inf
// push {0,0} to the set
// and take it out, and pop
// follow the similar algorithm as when using the PQ
// if we follow our algo, there will be a point when the algo reaches the node 5 with a distance 8. checks the dist array
// finds that the node 5 has been ALREADY reached with a distance of 10
// meaning that {10,5} would be in the set
// if this is sure, and since 8 is better. we'll put {8,5} in the set, but here, we will delete {10,5} as well
// set can erase that pair, PQ cannot
// therefore we save time
// THEREFORE, FOR A BETTER ALTERNATIVE, ERASE THE PREVIOUS PAIR, and ADD THE NEW BETTER PAIR
// this will improve the TC but very minor change

// st.erase will take logn time. hence we save future iteration time (which might not be there), but we take logn time to do so
// hence, it depends on size of graph
// therefore, TC will improve is not compulsory

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0,S});

    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode = it[0];
            int edgW = it[1];
            if(dis + edjW < dist[adjNode]){
                //erase if it existed
                if(dist[adj] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}


// why PQ and not Q?
// in queue, since no sorting is done, there are unnecesarry occurences of {dist, node} values
// many values, (that would not have been considered if using PQ), are found in the queue


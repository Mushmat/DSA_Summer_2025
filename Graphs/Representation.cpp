// Representation of a graph in cpp

// we have Input and the DS to store
// We will have always n and m and also whether it is directed or undirected
// n is the number of nodes
// m is the number of edges

// In the next line, we have m lines representing the edges. Eg 1,2 indicating 1-2. it can also be 2,1 indicating 2-1
// for undirected graph 1,2 means 1-2 exists, and 2-1 also exists
// therefore first line gives n and m
// next lines gives the edges

// How to store?
// One is Matrix, second is List

// Matrix
// use adjacency matrix
// defined adj[n+1][m+1] for 1 based indexing.
// if there is an edge between 1-2, mark adj[1][2] as one. if it is undirected graph, mark adj[2][1] as one also
// this uses NxN space
// This is costly

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}


// Adjacency List
// Use an array
// for a 1-based graph with size n nodes, create array of n+1 size
// Every index will be a vector
// vector<int> adj[n+1]
// therefore, every index contains a vector (empty)
// the motivation of having a vector is to store all the neighbors of a node in a vector in any order
// go to each node and store its neighbors in its vectors
// Space that we take is 2 x Edges
// O (2E) ~ O(E)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// If graph is directed graph, only store the edge between u and v, dont store the edge between v and u
// Therefore for a directed graph, eliminate the second pushback line.
// By which, the space complexity also decreases to O(E)

// To store a weighted graph:
// In a matrix, when we write 1 in the matrix cell where the edge is there, instead of writing 1, just write the edge weight
// therefore adj[u][v] = wt

// In a list, For a node, vector has its neighbors only
// instead of that, use pairs. a vector therefore if has (2,1) then it indicates node 2 is neighbor with wieght 1, and hence (4,2) says 4 neighbor with weight 2
// (neighbour, weight)
// vector<pair<int, int>> adj[n+1];


// floydd warshall shortest path algorithm
// dijkstra and bellman ford had single source
// in floydd warshall, we need shortest path from every node to every other node
// therefore it is a multi source shortest path algorithm

// go via every vertex/node, and get the shortest path
// eg if we want to go from 0 to 1, we can go directly 0 -> 1, or we can go via 0 -> 2 -> 1 and add their individual path costs,
// or we can go 0 -> 3 -> 1 adding their individual path costs
// similarly we need to explore all routes and give out the route that has the least cost
// so best path is min (d[i][k] + d[k][j]])
// create adj matrix

//floydd warshall can be applied on directed graphs only so convert undirected graphs to directed
// unreachable nodes in the graph are marked as inf in the adj matrix
// compute the distance matrices via each node. eg to compute 0 -> 2 via 1, compute 0 -> 1 and 1 -> 2, and so on for each node and each source n destination
// the last matrix obtained after computing matrices via each node, stores the shortest distance from everynode to every node
// this is an n^3 algorithm

// what if a graph has a negative cycle? the costing of a node to itself will be -ve if there is a neg cycle, so if cost from i to i is < 0 then there is a neg cycle


void shortest_distance(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i == j) matrix[i][j] = 0;
        }
    }


    for(int k = 0;k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(matrix[i][i] < 0){
            // negative cycle exists, just print NEGATIVE or whatever needed
        }
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}

// SC: n^2 as we are using the matrix given to us
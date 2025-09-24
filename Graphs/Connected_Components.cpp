// A graph might have different connected components
// A graph can be given with the edges to tell how many connected components are there
// Any traversal that we do will have a visited array
// In the visited array, we have array of n+1 size
// Run a loop from 1 to N ( 1 based indexing assumed), if node is not visited, call traversal algo from that node
// Initially everyone is unvisited (0)

for(i -> 1 to N){
    if(!vis[i]){
        traversal[i];
    }
}

// mark every node traversed as 1

// minimum time taken to burn a binary tree from any given node
// one node takes 1 second to burn its neighbours, 2 seconds to burn neighbour's neighbours
// return the minimum time

// we can do a bfs to solve this but we need parent pointers
// hence first do a level order traversal to get the parent pointers
// store the parents in a hash map
// now keep a visited map
// and start the bfs traversal from the given node, time = 0
// pick the node out from the queue
// this node can burn his parent, his left, and his right. burn them and increment time
// whoever is being burned, put them in queue and mark them visited
// in the next traversal, pick all the nodes present in queue at once
// burn their neighbours and increment time, dont burn visited
// (by burn we simply mean time increment for all the neighbors and keeping them in the queue)

// this problem is very similar to nodes_at_dist_k.cpp problem
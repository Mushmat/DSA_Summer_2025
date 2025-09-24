// Introduction to graphs

// An undirected graph is a graph where two nodes can be reached bidirectionally. There are no directed arrows to a node. 
// A directed graph is a graph where if connected, two nodes have directed arrows between them. If A -> B, you can go to B from A but not A from B
// vertices = nodes / V = N
// the arrows that connect two nodes is called an edge E
// There a graph has vertices V and edges E

// A cycle in a graph is said to exist when you start from a node and you reach back (end) to that node itself
// There can be multiple cycles in a graph
// There can be no cycles also. (Just in a directed ACYCLIC graph)

// Path: Contains a lot of vertices, each of them are reachable, however any node cannot appear twice in a path
// In a path, the adjacent nodes must be connected

// Degree: A degree of a node is the number of edges that go inside/outside to it (for an undirected graph)
//         The total degree of a graph is 2 * Edges
//         For a directed graph, we have Indegree of a node and OutDegree of a node
//         Indegree is the number of incoming edges whereas OutDegree is the number of outgoing edges

// Edge weights: Every edge has a weight. If weights are not assigned, all weights are assumed to be 1.

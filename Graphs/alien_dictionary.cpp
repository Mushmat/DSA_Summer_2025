// given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language
// Many order may be possible for a particular test case, thus return any valid order and output will be 1 is the order of string returned by the function is correct else 0

// basically, given a dictionary having N strings
// give the sequence of the words
// in standard dictionary, sequence is a b c d e....
// however we need to find the alien order
// we need to check the given dictionary, to find out the alien sequence in every string
// return the alien sequence, eg b d a c

// again this is a question of Topo Sort
// if k = 4, we know that sequence will contain a b c d
// mark a as 0, b as 1, c as 2, d as 3
// express all alphabets as numbers
// pick the first two strings from the dictioanry
// figure out why is the first string appearing before second string
// create a directed graph such that if b appears before a, create b -> a in the graph
// now leave the first string, and compare second and third string
// keep doing this and keep adding edges in the graph
// once done, we will have a directed graph
// if k was 5, there would have been an 'e' also. but if no string has e, then put e as a single node in the directed graph with in and out degree as 0

// once we have the DG, and the single nodes
// run topo sort
// instead of storing characters in graph, store their respective numbers
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


string findOrder(string dict[], int N, int K){
    vector<int> adj[k];
    for(int i = 0; i < N-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());
        for(int ptr = 0; ptr < len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); //convert to numbers and store the directed edge
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for(auto it: topo){
        ans = ans + char(it + 'a');
    }
    return ans;
}


// when will the order be not possible?
// one is when string 1 is abcd, string 2 is abc. 
// the first three match, comparision finished. no differentiator. then shorter string should have been before longer string
// therefore if everything matches and larger is before smaller, then NOT POSSIBLE
// second case is when there is a cyclic dependency
// eg abc, bat, ade. here a < b and b < a
// therefore NOT POSSIBLE
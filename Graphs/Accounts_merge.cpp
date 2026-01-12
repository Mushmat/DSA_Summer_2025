// given a lot of arrays
// each array contains a name, followed by their email accounts
// questions wants us to merge the similar accounts
// two Johns with different email ids are different people
// two Johns with same email ids are same people, so merge the email ids that are different in both arrays as they belong to same people

// all email ids should be in the sorted order for each person
// there must not be therefore any two people who have overlapping email ids in the final answer
// same people's email ids must be merged

// minimum of 1 email ids must be same to merge

// for each person, we can think of this as a component of that person and its email ids
// then we can use disjoint set

// assign indexes to each array
// each person will be represented by one index
// each name will be the root of their component
// make the disjoint set with this
// have a map that maps each email id to its parent
// j1@com -> 0
// j2@com -> 0
// r1@com -> 2
// etc
// j1@com -> ideally must belong to 3 if theres a repeat, but we see it is already mapped to 0, so we connect the parents of these 2 using union
// because they have the same ultimate parent
// only keep those email ids in the map that are not a repeat. for repeat emails, merge the parents simply using disjoint set
// after mapping all email ids, attach email ids to their ultimate parents

class DisjointSet{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;

        }
    }

    int findUPar(int node){ // path compression
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u = ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    
    void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u = ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] == ulp_v;
                size[ulp_v] += size[ulp_u];

            }

            else{
                parent[ulp_v] == ulp_u;
                size[ulp_u] += size[ulp_v];
            }
    }

};

class Solution{

    vector<vector<string>> mergeDetails(vector<vector<string>> &details){
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < details[i].size(); j++){
                string mail = details[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){ // the mail is yet to be added to the map, NOT SEEN TILL NOW
                    mapMailNode[mail] = i;

                }
                else{ // the mail is already there, so merge the two parens
                    ds.unionBySize(i, mapMailNode[mail];)
                }
            }
        }

        // merge mail acc to ultimate parent
        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }


        // form the answer
        vector<vector<string>> ans; 
        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail.end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }

};
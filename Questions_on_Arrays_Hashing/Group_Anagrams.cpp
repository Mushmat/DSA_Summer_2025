class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string& s: strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            hash[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : hash) {
            result.push_back(pair.second);
        }
    
        return result;
        }
};

//sort the array and store the sorted key in the hash map. 
/*
hash = {
  "aet": ["eat", "tea", "ate"],
  "ant": ["tan", "nat"],
  "abt": ["bat"]
}

This is how an example hash table looks like. For each sorted string there is the corresponding vector of all strings that originate from it.
  */
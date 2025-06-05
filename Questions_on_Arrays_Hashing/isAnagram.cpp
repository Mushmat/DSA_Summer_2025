class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashs(26,0);
        vector<int> hasht(26,0);

        for(int i = 0 ; i < s.size(); i++){
            hashs[s[i] - 'a'] += 1;
        }

        for(int i = 0; i < t.size(); i++){
            hasht[t[i] - 'a'] += 1;
        }

        for(int i = 0; i < hashs.size(); i++){
            if(hashs[i] != hasht[i]){
                return false;
            }
        }
        return true;
    }
};

//Simply use hashes for characters and if the strings are anagrams, simply compare. The number of times a letter appears in string s should be the same to appear in string t.
//Then only iy will be an anagram.

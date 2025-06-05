//Return true if the array has duplicate elements

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
            if (hash[num] > 1) return true;
        }
        return false;
    }
};

/*
Done in O(n) time using a unordered map. Simply hash the numbers according to their indices. Unordered map is used as it can handle both negative and positive values.
*/
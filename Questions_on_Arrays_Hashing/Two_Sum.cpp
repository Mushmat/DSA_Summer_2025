class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) { //Make the hash map for value with index
            int complement = target - nums[i]; 
            if (hash.find(complement) != hash.end()) { //if there is a complement
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        return {0,0};
    }
};
//For a given array we need to return indices of the two elements that sum to a target
//For eg for array 2 7 11 15 and target 9, 2+7 = 9, so return [0,1] that is the indices of 2 and 7
//Used unordered map for value to index mapping and then checked if the complement exists.

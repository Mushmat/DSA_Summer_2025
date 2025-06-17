// Given an array of integers, find the element that appears more than n/2 times.
// Brute Force: pick an element, scan through the entire array and do count++. 
// If count is > n/2 for any element, that appears more than n/2 times
// O(n^2)

// Better Solution:
// Use hashing to track the count of all elements
// Then throw out the answer whose count is > n/2
// Hash map: ELement is the key, count is the value
// O(nlogn) and space O(n)

// Optimal Solution:
// Moore's Voting Algorithm
// Initially count is 0 and element is not initialized
// Start iterating, if the count is 0, that means no element is taken. Take the first element and assume it to be the answer
// Element = first element, count = 1
// Iterate, if next candidate is equal to the candidate stored in the 'element' variable, increase count. 
// If not, reduce the count.
// when count becomes 0, change the assumtion of the majority element to the element where the pointer points to now.
// again iterate and check
// Once you finish the iteration and have an element whose count > 0, that element is the majority element
// Everyone else got cancelled within itself.
// If there exists a majority element, it will be the element that we got.
// therefore, verify the element that we got, is the majority. 

/*
    int majorityElement(vector <int> v){
        int cnt =0;
        int el;
        for(int i = 0; i < v.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = v[i];
            }
            else if(v[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int count1 = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == el){
                count1++;
            }
        }
        if(count1 > v.size()/2){
            return el;
        }
        return -1;
    }


    //TC: O(n)
*/


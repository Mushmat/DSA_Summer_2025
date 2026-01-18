// similar to last lecture
// houses arranged in a circle
// cant rob adjacent houses
// each house has some money
// return max amount of money robber can rob without robbing adjacent houses

// in last ques we needed to return max sum of subsequence
// here we just need to take care that last house is neighbor of first as this is a circle

// is a new logic needed?
// NO
// we know that, whatever our answer will be, it cannot contain both first and last
// therefore we can:
// leave the last house and apply lecture 5 to rest array
// leave the first house and apply lecture 5 to rest array
// return the max of both the results

// L5 space optimizied solution
long long int maximumNoAdjacentSum(vector<long long int> &nums){
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;
    for(long long int i = 1; i < n; i++){
        long long int take = nums[i];
        if(i > 1) take += prev2;
        long long int nontake = 0 + prev;

        curi = max(take, nontake);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

long long int houseRobber(vector<long long int> & valueInHouse)
{
    vector<long long int> temp1, temp2; // temp 1 does not contain first house
    long long int n = valueInHouse.size();
    
    // if array has single element
    if(n == 1) return valueInHouse[0];

    for(long long int i = 0; i < n; i++){
        if( i != 0) temp1.push_back(valueInHouse[i]);
        if( i != n-1) temp2.push_back(valueInHouse[i]);
    }    

    return max(maximumNoAdjacentSum(temp1), maximumNoAdjacentSum(temp2));
}
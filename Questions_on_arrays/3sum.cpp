// Given an array of integers
// Find out all the triplets that sum up to 0
// Cant take same elements more than once
// return only unique triplets

// Brute:
// Try out all the triplets and return the unique triplets that sum 0
// we have three elements to fill. say we pick a[0] as first, a[1] as second, then we have many possibilities for third element
// Try out all the combinations
// Next round keep a[1] as first, a[2] as second and so on, try all
// Clearly it requires three loops and a time complexity of roughly O(n^3)
// Store the triplets in a set so that unique are stored (sort and store)
// Then return the answer

// Better:
// We should try to do it in n^2
// Therefore look to get rid of the third loop
// we can say that arr[i] + arr[j] + arr[k] = 0
// therefore arr[k] = - (arr[i] + arr[j])
// Therefore we can deduce the third element that we are looking for, to complete the triplet
// If there is a third element in the array, we can say yes
// To lookup for the third element without traversal, we must use hashing
// Take a hash set
// start i and j (a[0] & a[1])
// compute the third element, if this is not in the hash set, include j (a[1] in the hash set), and move j ahead
// if it is in the hash set, include it as a triplet
// once j reaches at the end, all triplets with i are done
// now move i ahead and omit the hash set
// TC: O(n^2 x log(size of set))


// Optimal:
// array is sorted
// implement a two pointer approach
// fix i to the first element
// keep j at the second element
// keep k at the end
// add these three elements, if you get something < 0, you need to increase someone's value. (i is constant)
// since the array is sorted, we need to move j ahead to find a greater element
// keep moving j till the sum becomes 0
// once a triplet is obtained, move k to an element that is not the same as the element where k was before (for eg if k was at 2, move it to an element which is not equal to 2)
// similarly move j
/*

        #include<bits/stdc++.h>
        vector<vector<int>> triplet(int n, vector<int> &num)
        {
            vector<vector<int>> ans;
            sort(num.begin(), num.end());
            for(int i = 0; i < n; i++) {
                if(i > 0 && num[i] == num[i-1]) continue;
                int j = i + 1;
                int k = n - 1;
                while(j < k) {
                    int sum = num[i] + num[j] + num[k];
                    if(sum < 0) {
                        j++;
                    }
                    else if(sum > 0) {
                        k--;
                    }
                    else {
                        vector<int> temp = {num[i], num[j], num[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j < k && num[j] == num[j-1]) j++;
                        while(j < k && num[k] == num[k+1]) k--;
                    }
                }
            }
            return ans;
        }


*/
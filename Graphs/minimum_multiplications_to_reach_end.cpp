// given start, start, and an array of n numbers. At each step, start is multiplied with any number in the array and then mod operations with 100000 is done to get the new start
// find the minimum steps in which end can be achieved starting from start. 
// if not possible, return -1

// basically we mod with 10^5 if the number is greater than 10^5 to get back to the range of 0 to 10^5

// say the start is 3, arr = [2,5,7] 
// assume there is no end
// so we have 3, we can multiply it with 2, or 5, or 7
// by 2, we get 6 (1 multiplications till now)
// by 5, we get 15 (1 multiplicatins)
// by 7, we get 21 (1 multiplications)
//then we can multiply 6 with 2 5 7, with 2 mulitiplications
// and so on, this creates a tree for us

// we can use dijkstra to keep multiplying and get to the end in the shortest steps
// we can store as (node, dist) by keeping source as (3, 0), our nodes will always be in the range 0 to 99999

// therefore keep a min heap that stores {steps, num}
// keep a dist array with inf initially
// keep the source in the min heap (0, 3)
// take the point out from the heap, multiply it with 2, and add (1, 6) to the heap, and so on
// repeat

int minimumMultiplications(vector<int> &arr, int start, int end){

    queue<pair<int,int>> q;
    q.psuh({start,0});
    vector<int> dist(100000, 1e9);

    dist[start] = 0;
    int mod = 100000;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it: arr){
            int num = (it * node) % mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if(num == end) return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}
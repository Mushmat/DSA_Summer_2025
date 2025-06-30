// given an array having n integers representing coordinates of n gas stations
// place k new gas stations 
// such that max distance between any two gas stations is minimised
// you cannot change the coordinates of existing gas stations
// can place new gas stations on decimal coordinates eg 1.5

// start by placing one station at a time and place it in between those two stations who are at maximum dist initially
// repeat this by decreasing the max distance between any two stations, whenever u add a new station
// this is the brute force
/*
    long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    for(int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxSection = -1;
        int maxInd = -1;
        for(int i = 0; i < n - 1; i++) {
            long double diff = (arr[i + 1] - arr[i]);
            long double sectionLengthj = diff / (long double)(howMany[i] + 1);
            if(sectionLengthj > maxSection) {
                maxSection = sectionLengthj;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns = -1;
    for(int i = 0; i < n - 1; i++) {
        long double diff = (arr[i + 1] - arr[i]);
        long double sectionLengthj = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLengthj);
    }
    return maxAns;
}

*/

// BS:
// the answer here is in long double, therefore we cannot go the general BS
// therefore, instead of comparing low <= high, we try to match the answer respecting the problem statement
// while(high - low > 10e-6) we break
// also rather than doing low = mid + 1, do low = mid, and instead of high = mid - 1, high = mid
// lets find the range of answer
// the answer can start from 0 (it can be 0 also)
// the answer cannot lie outside the scope
// the answer will be less than the max distance initially between any two stations

/*
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if((arr[i] - arr[i - 1]) / dist == numberInBetween * dist) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for(int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if(cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

*/
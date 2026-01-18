// subsequence: a contagious or a non contagious sequence that follows the order of the array
// an empty set is also a subsequence
// given the array and n therefore, print all subsequences

// we can do a take/nontake on indices to pick some and leave some
// we can repeat this for all numbers in the array

void printF(int ind, vector<int> & ds, int arr,[], int n){
    if(ind == n){
        for(auto it: ds){
            cout << it << " ";
        }
        if(ds.size() == 0) cout << "{}";
        cout << endl;
        return;
    }

    // take or pick

    ds.push_back(arr[ind]);
    printF(ind+1, ds, arr, n);
    ds.pop_back();
    
    // not pick or not take
    printF(ind+1, ds, arr, n);
}

int arr[] = {3,1,2};
int n = 3;
vector<int> ds
printF(0, ds, arr, n);
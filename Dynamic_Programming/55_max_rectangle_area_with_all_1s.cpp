// given a nxm matrix
// filled with either 1 or 0
// figure out the maximum rectangle with all 1s
// treat the matrix as histogram buildings
// for every row, make the histogram, and run histogram code to get largest rectangle

int largestRectangleArea(vector<int> &histo){
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
            int height = histo[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
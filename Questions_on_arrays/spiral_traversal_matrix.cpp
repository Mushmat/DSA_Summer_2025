// Given a matrix n x m
// Print the elements in a spiral manner
// Only one solution is there : Optimal Solution

// There is a pattern: We move right then bottom then left then top
// And we repeat
// Everytime we do the pattern, one layer gets printed
// Initialize top = 0, bottom = last row, left = 0, right = last column
// first we will print from left to right:
/*
    for(i =  left to right){
        a[top][i] will be printed
    }
*/

// This prints the first thing in the pattern (right)
// Then top goes one down (top++)
// Now we need to print second thing in pattern (bottom)
// Right is constant:
/*
    for(i =  top to bottom){
        a[i][right]
    }
*/

// Now print third thing in pattern (left)
// move right one back (right--)
// for(i = right to left) print a[bottom][i]

// Now print fourth thing in pattern (top)
// Bottom goes up one
// for(i = bottom to top) print a[i][left]

// THis prints the first layer
// Now shift left++, and repeat


/*

    vector<int> spiralMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // Traverse downwards
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Traverse upwards
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

*/

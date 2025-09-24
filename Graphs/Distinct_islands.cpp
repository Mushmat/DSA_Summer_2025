// given a boolean 2d matrix of size N x M
// You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island
// Two islands are considered to be distintc if and only if one island is not equal to another (not considering rotations and reflections)
// return the number of distinct islands 

// we can try storing each shape in a set and then return the size of the set since set is unique
// how do we store the shape?

// we can store the relative coordinates of each cell with respect to the base cell (the first cell that we encounter during DFS)
// for example, if we have an island with coordinates (0,0), (0,1), (1,0)
// we can store the coordinates as (0,0), (0,1), (1,0) - (0,0) = (0,0), (0,1) - (0,0) = (0,1), (1,0) - (0,0) = (1,0)
// so the shape will be stored as {(0,0), (0,1), (1,0)}

// therefore subtract the base coordinates from all the coordinates of the island and store them in a vector
// the two vectors would come out to be the same and hence the set would take care of the uniqueness
// finally return the size of the set

class Solution{

    private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0){
        vis[row][col] = 1;
        vec.push_back({row, row0, col - col0}); //row0 and col0 are base coordinates

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vis, vec,i , j);
                    st.insert(vect);
                }
            }
        }

        return st.size();
    }
}

// TC: O(N*M*4) + O(N*M*4) ~ O(N*M)
// SC: O(N*M) + O(N*M) + O(K*L) ~ O(N*M) (visited matrix + recursion stack space + set space where K is number of distinct islands and L is the max size of an island)
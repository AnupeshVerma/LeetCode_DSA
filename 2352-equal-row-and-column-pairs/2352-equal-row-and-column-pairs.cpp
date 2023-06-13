class Solution {
public:
    int count = 0;
    int bottomUp(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if (m <= 0 || n <= 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];

        vector<int> curr_row = grid[m - 1];
        vector<int> curr_col;

        for (int i = 0; i < grid.size(); i++)
            curr_col.push_back(grid[i][n - 1]);

        if (curr_row == curr_col)
            count++;

        return dp[m][n] = bottomUp(grid, m - 1, n, dp) + bottomUp(grid, m, n - 1, dp);
    }

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // int ans = bottomUp(grid, n, n, dp);
        // return count;
        
        
//         Without Dynamic Programming
        for(int row=0; row<n; row++)
            for(int col=0; col<n; col++)
            {
                bool equal = true;
                for(int k=0; k<n; k++)
                    if(grid[row][k] != grid[k][col])
                        equal = false;
                if(equal)
                    count++;
            }
        return count;
    }
};

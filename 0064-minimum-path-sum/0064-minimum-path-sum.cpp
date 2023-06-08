class Solution {
public:
    int bottomUp(vector<vector<int>>&grid, vector<vector<int>>&dp, int m, int n)
    {
        if(m==0 && n==0)
            return grid[0][0];
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int up=INT_MAX, left=INT_MAX;
        if(m>0) up = grid[m][n] + bottomUp(grid, dp, m-1, n);
        if(n>0) left = grid[m][n] + bottomUp(grid, dp, m, n-1);
        
        return dp[m][n] = min(up, left);
        
            
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         MEMOIZATION
        return bottomUp(grid, dp, m-1, n-1);
        
//         TOP-DOWN APPROACH
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                    dp[0][0] = grid[0][0];
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = dp[i-1][j] + grid[i][j];
                    if(j>0) left = dp[i][j-1] + grid[i][j];

                    dp[i][j] = min(left, up);
                }
            }
        
        return dp[m-1][n-1];
    }
};
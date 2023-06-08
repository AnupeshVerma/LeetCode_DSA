class Solution {
public:
    int bottomUp(vector<vector<int>>&grid, vector<vector<int>>&dp, int m, int n)
    {
        if(grid[m][n] == 1)
            return 0;
        
        if(m==0 && n==0)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        
        int up=0, left=0;
        if(m>0) up = bottomUp(grid, dp, m-1, n);
        if(n>0) left = bottomUp(grid, dp, m, n-1);
        
        return dp[m][n] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         MEMOIZATION or BOTTOM-UP APPROACH
        // return bottomUp(obstacleGrid, dp, m-1, n-1);
        
        
//         TOP_DOWN APPROACH
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n;j++)
            { 
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if(i==0 && j==0)
                    dp[0][0] = 1;
                else
                {
                    int right=0, down=0;
                    if(i>0) right = dp[i-1][j];
                    if(j>0) down = dp[i][j-1];
                    dp[i][j] = right + down;
                }
            }
        return dp[m-1][n-1];
    }
};
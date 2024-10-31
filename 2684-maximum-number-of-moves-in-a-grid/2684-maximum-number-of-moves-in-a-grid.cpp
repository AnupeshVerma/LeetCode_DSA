class Solution {
private:
    int TOTAL_ROW, TOTAL_COL;
    int topDownDP(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row >= TOTAL_ROW || col >= TOTAL_COL)
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];

        int right=0, upper_diagonal=0, lower_diagonal=0;        
        if(row-1 >= 0 && col+1 < TOTAL_COL &&  grid[row][col] < grid[row-1][col+1])
            upper_diagonal = 1 + topDownDP(grid, row-1, col+1, dp);

        if(col+1 < TOTAL_COL && grid[row][col] < grid[row][col+1])
            right = 1 + topDownDP(grid, row, col+1, dp);

        if(row+1 < TOTAL_ROW && col+1 < TOTAL_COL && grid[row][col] < grid[row+1][col+1])
            lower_diagonal = 1 + topDownDP(grid, row+1, col+1, dp);

        return dp[row][col] = max(right, max(upper_diagonal, lower_diagonal));
    }


    int bottomUpDP(vector<vector<int>>& grid, vector<vector<int>>& dp){
        int ans = 0;

        for(int i=0; i<TOTAL_ROW; i++)
            dp[i][0] = 1;

        int max_moves = 0;
        for(int col=1; col<TOTAL_COL; col++) {
            for(int row=0; row<TOTAL_ROW; row++) {
                if(grid[row][col] > grid[row][col-1] && dp[row][col - 1] > 0)
                    dp[row][col] = max(dp[row][col], 1 + dp[row][col-1]);
                
                if(row-1 >= 0 && grid[row][col] > grid[row-1][col-1] && dp[row-1][col - 1] > 0)
                    dp[row][col] = max(dp[row][col], 1 + dp[row-1][col-1]);

                if(row+1 < TOTAL_ROW && grid[row][col] > grid[row+1][col-1] && dp[row+1][col - 1] > 0)
                    dp[row][col] = max(dp[row][col], 1 + dp[row+1][col-1]);

                max_moves = max(max_moves, dp[row][col] -1); 
            }
        }
        return max_moves;
    }


public:
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        TOTAL_ROW = grid.size();
        TOTAL_COL = grid[0].size();

        vector<vector<int>> dp(TOTAL_ROW, vector<int>(TOTAL_COL, -1));

        return bottomUpDP(grid, dp);

        for(int row=0; row<TOTAL_ROW; row++)
            ans = max(ans, topDownDP(grid, row, 0, dp));
        
        return ans;
    }
};
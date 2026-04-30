class Solution {
private:
int rows, cols;
    vector<vector<vector<int>>> dp;

    int helper(vector<vector<int>>& grid, int row, int col, int remainingCost) {
        // Base condition
        if(row >= rows || col >= cols)
            return INT_MIN;

        int cost = grid[row][col] == 0 ? 0 : 1;
        int score= grid[row][col];

        if(cost > remainingCost)
            return INT_MIN;

        // If reach the destination
        if(row == rows -1 && col == cols -1)
            return score;

        if(dp[row][col][remainingCost] != -1)
            return dp[row][col][remainingCost];
            

        int right = helper(grid, row, col+1, remainingCost-cost);
        int down = helper(grid, row+1, col, remainingCost-cost);

        int best = max(right, down);

        return dp[row][col][remainingCost] = best == INT_MIN ? INT_MIN : best + score;
     }
    
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        dp.resize(rows, vector<vector<int>>(cols , vector<int>(k+1, -1)));

        int ans = helper(grid, 0, 0, k);

        return ans < 0 ? -1 : ans;

    }
};
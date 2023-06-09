class Solution {
public:
    int bottomUp(vector<vector<int>> &t, vector<vector<int>> &dp, int row, int ind)
    {
        if(row == t.size())
            return 0;
        
        if(dp[row][ind] !=-1)
            return dp[row][ind];
       
        int down = bottomUp(t, dp, row+1, ind);
        int diagonal = bottomUp(t, dp, row+1, ind+1);
            
        return dp[row][ind] = t[row][ind] + min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return bottomUp(triangle, dp, 0, 0);
        
            
    }
};
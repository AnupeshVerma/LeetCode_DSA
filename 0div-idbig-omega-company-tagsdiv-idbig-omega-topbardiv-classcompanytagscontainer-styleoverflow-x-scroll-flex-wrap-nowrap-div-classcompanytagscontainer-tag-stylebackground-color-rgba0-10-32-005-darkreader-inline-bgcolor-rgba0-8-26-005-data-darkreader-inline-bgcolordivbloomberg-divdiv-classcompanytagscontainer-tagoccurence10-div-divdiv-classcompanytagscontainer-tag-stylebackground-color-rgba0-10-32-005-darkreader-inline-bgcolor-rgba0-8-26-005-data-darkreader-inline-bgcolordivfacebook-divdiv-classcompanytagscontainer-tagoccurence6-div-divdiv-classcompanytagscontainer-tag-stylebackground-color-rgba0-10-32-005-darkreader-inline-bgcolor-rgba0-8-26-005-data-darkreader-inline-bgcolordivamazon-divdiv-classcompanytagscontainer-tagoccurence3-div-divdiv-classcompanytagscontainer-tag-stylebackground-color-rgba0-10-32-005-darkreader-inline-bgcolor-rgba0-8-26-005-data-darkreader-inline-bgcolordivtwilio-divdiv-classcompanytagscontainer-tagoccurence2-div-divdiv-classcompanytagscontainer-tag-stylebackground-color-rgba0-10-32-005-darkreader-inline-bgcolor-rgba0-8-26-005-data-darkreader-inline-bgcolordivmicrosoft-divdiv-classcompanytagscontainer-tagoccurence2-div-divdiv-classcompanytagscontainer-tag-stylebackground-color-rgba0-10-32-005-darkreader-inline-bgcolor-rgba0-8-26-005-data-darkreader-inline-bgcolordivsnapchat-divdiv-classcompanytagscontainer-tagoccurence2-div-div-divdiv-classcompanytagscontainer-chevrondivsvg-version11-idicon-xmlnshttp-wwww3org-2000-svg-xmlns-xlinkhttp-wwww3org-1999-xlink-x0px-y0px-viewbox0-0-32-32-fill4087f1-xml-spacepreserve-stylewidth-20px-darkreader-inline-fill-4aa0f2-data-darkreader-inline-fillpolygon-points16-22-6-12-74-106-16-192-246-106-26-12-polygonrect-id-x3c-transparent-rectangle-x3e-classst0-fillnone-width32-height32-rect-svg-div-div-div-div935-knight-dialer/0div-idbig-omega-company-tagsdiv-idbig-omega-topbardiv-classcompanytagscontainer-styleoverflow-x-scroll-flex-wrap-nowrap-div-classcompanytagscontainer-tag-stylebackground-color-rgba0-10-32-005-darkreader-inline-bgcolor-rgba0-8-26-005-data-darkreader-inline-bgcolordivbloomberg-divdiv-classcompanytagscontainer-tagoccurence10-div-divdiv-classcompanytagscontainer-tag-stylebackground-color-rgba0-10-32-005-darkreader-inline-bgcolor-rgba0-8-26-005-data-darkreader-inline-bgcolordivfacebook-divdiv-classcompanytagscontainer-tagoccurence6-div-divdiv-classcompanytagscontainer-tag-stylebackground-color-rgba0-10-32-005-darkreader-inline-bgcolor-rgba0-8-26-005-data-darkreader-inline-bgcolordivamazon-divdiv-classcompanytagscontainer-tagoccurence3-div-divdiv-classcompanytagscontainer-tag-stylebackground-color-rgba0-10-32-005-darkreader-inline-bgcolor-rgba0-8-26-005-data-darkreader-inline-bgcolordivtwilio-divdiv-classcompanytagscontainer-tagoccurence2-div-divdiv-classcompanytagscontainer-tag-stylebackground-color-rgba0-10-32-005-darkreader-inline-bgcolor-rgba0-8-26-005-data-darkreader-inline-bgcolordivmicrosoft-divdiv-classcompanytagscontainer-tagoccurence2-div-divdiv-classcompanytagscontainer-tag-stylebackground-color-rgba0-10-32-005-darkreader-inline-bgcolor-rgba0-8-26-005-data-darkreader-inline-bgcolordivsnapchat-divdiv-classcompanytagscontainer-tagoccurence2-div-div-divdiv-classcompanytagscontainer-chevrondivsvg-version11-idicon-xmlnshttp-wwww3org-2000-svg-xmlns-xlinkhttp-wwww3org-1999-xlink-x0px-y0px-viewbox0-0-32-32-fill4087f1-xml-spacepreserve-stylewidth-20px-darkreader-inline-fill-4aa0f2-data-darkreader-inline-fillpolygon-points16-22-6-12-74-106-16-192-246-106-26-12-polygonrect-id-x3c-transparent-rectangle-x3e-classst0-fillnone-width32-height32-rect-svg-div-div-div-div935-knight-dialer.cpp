class Solution {
    int mod = 1e9 + 7;
    
    int solve(int n, int row, int col, vector<vector<vector<int>>> &dp)
    {
        if((row==3 && col==0) || (row==3 && col==2))
            return 0;
        if(n==1)
            return 1;
        
        if(dp[n][row][col] != -1)
            return dp[n][row][col];
        
       
        int drow[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dcol[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        long long result = 0;

        for(int i=0; i<8; i++)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            
            if(newRow>=0 && newRow<4 && newCol>=0 && newCol<3)
            {
                result = (result + solve(n-1, newRow, newCol, dp))%mod;
            }
        }
        return dp[n][row][col] = result;
    }
        
public:
    int knightDialer(int n) {
        
        int ans = 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(4, vector<int>(3, -1)));
        
        
        for(int row=0; row<4; row++)
        {
            for(int col=0; col<3; col++)
            {
                ans = (ans + solve(n, row, col, dp))%mod;
            }
        }
        return ans;
    }
};
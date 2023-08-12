class Solution {
public:
    int solve(int amount, vector<int>&coins, vector<vector<int>>&dp, int n)
    {
        if(amount == 0)
            return 1;
        else if(n == 0 || amount<0)
            return 0;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        if(coins[n-1] <= amount)
            return dp[n][amount] = solve(amount, coins, dp, n-1) + solve(amount-coins[n-1], coins, dp, n);
        else
            return dp[n][amount] = solve(amount, coins, dp, n-1);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
//         MEMOIZATION
        // return solve(amount, coins, dp, n);
        
        
//         TOP-DOWN
        for(int i=0; i<n+1; i++)
            for(int j=0; j<amount+1; j++)
            {
                dp[0][j] = 0;
                dp[i][j] = 1;
            }
        
        for(int i=1; i<n+1; i++)
            for(int j=1; j<amount+1; j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
                
        return dp[n][amount];   
    }
};
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
        
        return solve(amount, coins, dp, n);
    }
};
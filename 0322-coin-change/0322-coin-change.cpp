class Solution {
private:
    int solve(vector<int>&coins, int amount, vector<vector<int>>&dp, int n)
    {
        if(amount==0)
            return 0;
        if(n==0)
            return 1e8;
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        if(coins[n-1] <= amount)
            return dp[n][amount] = min(1+solve(coins, amount-coins[n-1], dp, n) ,solve(coins, amount, dp, n-1));
        else
            return dp[n][amount] = solve(coins, amount, dp, n-1);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        
//         MEMOIZATION
        int ans = solve(coins, amount, dp, n);
        return ans == 1e8 ? -1 : ans;
        
//         TOP-Down Approach
        
        
    }
};
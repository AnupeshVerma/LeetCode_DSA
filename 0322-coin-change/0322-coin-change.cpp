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
        int size = coins.size();
        vector<vector<int>>dp(size+1, vector<int>(amount+1, -1));
        
//         MEMOIZATION
        // int ans = solve(coins, amount, dp, n);
        // return ans == 1e8 ? -1 : ans;
        
//         TOP-Down Approach
        for(int n=0; n<size+1; n++)
            for(int amt=0; amt<amount+1; amt++)
            {
                dp[0][amt] = 1e8;
                dp[n][0] = 0;
            }
        
        for(int i=1; i<=size; i++)
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[size][amount]==1e8 ? -1 : dp[size][amount];
    }
};
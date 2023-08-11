class Solution {
private:
    int mod = 1e9 + 7;
public:
    int solve(int low, int high, int zero, int one, int len, vector<int>&dp)
    {
        if(len>high)
            return 0;
        
        if(dp[len] != -1)
            return dp[len];
        
        int appendZero = solve(low, high, zero, one, len+zero, dp);
        int appendOne  = solve(low, high, zero, one, len+one, dp);
        
        return dp[len] = ((len>=low && len<= high) + appendZero + appendOne)%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        return solve(low, high, zero, one, 0, dp);

    }
};
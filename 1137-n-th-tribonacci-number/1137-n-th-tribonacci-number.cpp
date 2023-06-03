class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
    }
    
    int tribonacci(int n) {
//         Take the size of array n+3, if n==0 then dp[1] and dp[2] will not exist.
        vector<int> dp(n+3, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        return solve(n, dp);
    }
};
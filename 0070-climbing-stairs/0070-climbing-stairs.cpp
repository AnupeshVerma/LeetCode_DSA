class Solution {
public:
    int rec(int n)
    {
        if( n<=2)
            return n;
        return rec(n-1) + rec(n-2);
    }
   
    int memo(int n, vector<int> &dp)
    {
        if(n<=2)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = rec(n-1) + rec(n-2);
    }
    int topdown(int n)
    {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<n+1; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        // return rec(n);
        vector<int> dp(n+1, -1);
        // return memo(n, dp);
        
        return topdown(n);
    }
};
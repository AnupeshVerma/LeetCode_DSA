class Solution {
public:
    int rec(vector<int>cost, int n)
    {
//         Base Condition
        if(n<=1)
            return 0;
        
//         Choices---> Either 1 step or two step
        return min(cost[n-1]+rec(cost, n-1), cost[n-2] + rec(cost, n-2));
    }
    
    int memo(vector<int>cost, int n, vector<int>&dp)
    {
        if(n<=1)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = min(cost[n-1]+rec(cost, n-1), cost[n-2] + rec(cost, n-2));
    }
    
    int topdown(vector<int>cost, int n)
    {
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<n+1; i++)
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2]+dp[i-2]);
        
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
//         RECURSION
        // return rec(cost, n);
        
//         MEMOIZATION
        // vector<int> dp(n+1, -1);
        // return memo(cost, n, dp);
        
//         TOP-DOWN
        return topdown(cost, n);
    }
};
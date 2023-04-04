class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n+2);
        int ans = 0;
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=0; 2*i+1 <= n; i++)
        {
            dp[2*i] = dp[i];
            dp[2*i+1] = dp[i] + dp[i+1];
            ans = max({ans, dp[2*i], dp[2*i+1]});
        }
        return ans;
    }
};
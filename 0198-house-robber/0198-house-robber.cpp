class Solution {
public:
    int rec(vector<int>nums, int n, vector<int> &dp)
    {
        if(n<=0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = max(rec(nums, n-2, dp)+nums[n-1], rec(nums, n-1, dp));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        
//         RECURSIVE + MEMO
        // return rec(nums, n, dp);
        
//         TOP_DOWN
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i=2; i<n+1; i++)
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        return dp[n];
    }
};
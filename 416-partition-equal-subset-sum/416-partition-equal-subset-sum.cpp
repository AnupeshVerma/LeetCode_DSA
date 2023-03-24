class Solution {
public:
    
     bool rec(vector<int>arr, int sum, int n)
    {
        // Base Condition
        if(sum==0)
            return true;
        if(n == 0)
            return false;
            
        // Choices
        if(arr[n-1] <= sum)
            return rec(arr, sum-arr[n-1], n-1) || rec(arr, sum, n-1);
        else
            return rec(arr, sum, n-1);
    }
    
    bool memo(vector<int>nums, int sum, int n, vector<vector<int>>dp)
    {
        if(sum == 0)
            return true;
        if(n == 0)
            return false;
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(nums[n-1] <= sum)
            return dp[n][sum] = memo(nums, sum-nums[n-1], n-1, dp) || memo(nums, sum, n-1, dp);
        else
            return dp[n][sum] = memo(nums, sum, n-1, dp);
    }
    
    bool topdown(vector<int>nums, int sum, int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        for(int i=0; i<n+1; i++)
            for(int j=0; j<sum+1; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        for(int i=1; i<n+1; i++)
            for(int j=1; j<sum+1; j++)
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
        
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        long sum = 0;
        int n = nums.size();
        for(auto i:nums)
            sum+=i;
        if(sum%2 != 0)
            return false;
        // return rec(nums, sum/2, n);
        
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
        // return memo(nums, sum/2, n, dp);
        
        return topdown(nums, sum/2, n);
    }
};
class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n <= 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
//         If the number is not taken
        int not_taken = solve(nums, n-1, dp);
        
//         If the number id taken
        int i=n, sum = 0;
        while(i>0 && nums[i-1]==nums[n-1])
        {
            sum += nums[i-1];
            i--;
        } 
        
        while(i>0 && nums[i-1]==nums[n-1]-1)
            i--;
        
        int taken = solve(nums, i, dp);
        
        return dp[n] = max(sum+taken, not_taken);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n+1, -1);
        return solve(nums, n, dp);
        
    }
};
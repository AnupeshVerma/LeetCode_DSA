class Solution {
public:
    int solve(vector<int>&nums, int curr_ind, int prev_ind, vector<vector<int>>&dp)
    {
        if(curr_ind == nums.size())
            return 0;
        if(dp[curr_ind][prev_ind+1] != -1)
            return dp[curr_ind][prev_ind+1];
        
        if(prev_ind==-1 || nums[curr_ind] > nums[prev_ind])
            return dp[curr_ind][prev_ind+1] = max(1 + solve(nums, curr_ind+1, curr_ind, dp), solve(nums, curr_ind+1, prev_ind, dp));
        else
            return dp[curr_ind][prev_ind+1] = solve(nums, curr_ind+1, prev_ind, dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
        
    }
};
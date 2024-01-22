class Solution {
public:
    int memo(vector<int>& nums, vector<int>& dp, int start, int end)
    {
        if(end < start)
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        int choose = memo(nums, dp, start+2, end) + nums[start];
        int skip = memo(nums, dp, start+1, end);
        
        return dp[start] = max(choose, skip);
        
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(n+1, -1);
//         If first element is choosen
        int firstChoosen = memo(nums, dp, 0, n-2);
//         If last elemnet is choosen
        dp.assign(n+1, -1);
        int lastChoosen = memo(nums, dp, 1, n-1);
        
        return max(firstChoosen, lastChoosen);
    }
};
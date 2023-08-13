class Solution {
private:
    bool checkValid(vector<int> &nums, int ind, vector<bool>&dp)
    {
        if(ind < 0)
            return true;
        if(dp[ind] != false)
            return dp[ind];
        
        bool twoEqual=false, threeEqual=false, threeConsInc=false;
        // If two elements are equal
        if(ind>=1 && nums[ind] == nums[ind-1])
            twoEqual = checkValid(nums, ind-2, dp);
        // If three elements are equal
        if(ind>=2 && nums[ind] == nums[ind-1] && nums[ind-1] == nums[ind-2])
            threeEqual = checkValid(nums, ind-3, dp);
        // If three consecutive increasing elements present
        if(ind>=2 && nums[ind] == nums[ind-1]+1 && nums[ind-1] == nums[ind-2]+1)    
            threeConsInc = checkValid(nums, ind-3, dp);
        
        return dp[ind] = twoEqual || threeEqual || threeConsInc;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        return checkValid(nums, n-1, dp);
    }
};
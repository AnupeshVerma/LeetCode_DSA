class Solution {
private:
    int memoization(vector<int>& nums, int target, int n, int sum) {
        if(n == 0)
            return sum == target ? 1 : 0;
        
        int add = memoization(nums, target, n-1, sum + nums[n-1]);
        int subtract = memoization(nums, target, n-1, sum - nums[n-1]);

        return add + subtract;
    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return memoization(nums, target, n, 0);
    }
};
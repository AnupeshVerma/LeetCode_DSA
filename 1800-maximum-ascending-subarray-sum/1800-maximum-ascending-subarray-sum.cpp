class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.length;
        int maxSum = nums[0];

        int tempSum = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                tempSum += nums[i];
                maxSum = Math.max(maxSum, tempSum);
            }
            else {
                tempSum = nums[i];
            }
        }
        return maxSum;
    }
};
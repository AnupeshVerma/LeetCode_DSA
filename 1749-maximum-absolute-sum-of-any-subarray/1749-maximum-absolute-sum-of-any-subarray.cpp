class Solution {
private:
    int bruteForce(vector<int>& nums, int n) {
        int maxSum = 0;

        for(int i=0; i<n; i++) {
            int tempSum = nums[i];
            maxSum = max(maxSum, abs(tempSum));
            for(int j=i+1; j<n; j++) {
                tempSum += nums[j];
                maxSum = max(maxSum, abs(tempSum));
            }
        }
        return maxSum;
    }


    int usingPrefixSum(vector<int>& nums, int n) {
        int minPrefixSum = INT_MAX;
        int maxPrefixSum = INT_MIN;
        int prefixSum = 0, maxSum = 0;

        for(int i=0; i<n; i++) {
            prefixSum += nums[i];

            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);

            if(prefixSum >= 0)
                maxSum = max(maxSum, max(prefixSum, prefixSum - minPrefixSum));
            else
                maxSum = max(maxSum, max(abs(prefixSum), abs(prefixSum - maxPrefixSum)));
        }
        return maxSum;
    }


public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        return usingPrefixSum(nums, n);
        
        return bruteForce(nums, n);
    }
};
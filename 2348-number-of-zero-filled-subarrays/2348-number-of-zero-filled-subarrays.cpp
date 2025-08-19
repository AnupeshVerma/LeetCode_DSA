class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0, zeroCount = 0;
        for (int num : nums) {
            if (num != 0) {
                result += zeroCount * (zeroCount + 1) / 2;
                zeroCount = 0;
            }
            else
                zeroCount++;
        }
        // Add subarrays count for the trailing zeros if present
        result += zeroCount * (zeroCount + 1) / 2;
        return result;
    }
};

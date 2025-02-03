class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        int maxInc = 1, maxDec = 1;

        for(int i=0; i<n-1; i++) {
            if(nums[i] < nums[i+1]) {
                inc++;
                dec = 1;
                maxInc = max(maxInc, inc);
            }
            else if(nums[i] > nums[i+1]) {
                dec++;
                inc = 1;
                maxDec = max(maxDec, dec);
            }
            else {
                dec = 1;
                inc = 1;
            }
        }
        return maxInc > maxDec ? maxInc : maxDec;
    }
};
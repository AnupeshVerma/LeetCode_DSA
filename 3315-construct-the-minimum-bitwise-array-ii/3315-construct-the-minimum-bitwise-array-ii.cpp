class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int& num : nums) {
            int res = -1;
            int d = 1;
            while((d & num) != 0) {
                res = num - d;
                d<<=1;
            }
            num = res;
        }
        return nums;
    }
};
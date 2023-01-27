class Solution {
public:
     bool check(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[i - 1]) 
                k++;
        if (k == 0)
            return true;
        if (k == 1 && nums[0] >= nums[n - 1]) 
            return true;
        return false; 
     }
};
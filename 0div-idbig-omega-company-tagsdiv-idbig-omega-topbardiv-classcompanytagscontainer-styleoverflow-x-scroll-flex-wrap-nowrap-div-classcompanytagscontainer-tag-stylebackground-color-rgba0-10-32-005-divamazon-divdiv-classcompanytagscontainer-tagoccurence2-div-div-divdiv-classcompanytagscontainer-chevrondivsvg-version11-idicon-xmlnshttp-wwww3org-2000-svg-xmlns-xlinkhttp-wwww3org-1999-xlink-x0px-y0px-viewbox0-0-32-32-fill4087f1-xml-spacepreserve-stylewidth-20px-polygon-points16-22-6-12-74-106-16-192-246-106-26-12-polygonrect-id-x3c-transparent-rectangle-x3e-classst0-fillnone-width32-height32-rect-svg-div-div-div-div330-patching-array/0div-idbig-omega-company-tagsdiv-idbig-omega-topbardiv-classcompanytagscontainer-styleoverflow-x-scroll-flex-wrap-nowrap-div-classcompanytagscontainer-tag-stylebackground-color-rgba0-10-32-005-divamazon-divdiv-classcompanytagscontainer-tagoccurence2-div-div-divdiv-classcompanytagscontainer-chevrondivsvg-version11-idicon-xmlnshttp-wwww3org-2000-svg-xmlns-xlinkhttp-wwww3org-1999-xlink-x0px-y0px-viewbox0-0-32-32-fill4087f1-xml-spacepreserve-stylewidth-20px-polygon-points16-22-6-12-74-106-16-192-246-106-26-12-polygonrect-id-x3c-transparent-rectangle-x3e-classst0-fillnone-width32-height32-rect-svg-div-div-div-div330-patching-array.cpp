class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long maxAchievable = 0;
        
        int i = 0;
        while(maxAchievable < n)
        {
            // maxAchievable should be greater than the nums[i]
            if(i<nums.size() && nums[i] <= maxAchievable+1)
            {
                maxAchievable += nums[i];
                i++;
            }
            // Adding patch
            else
            {
                int patchAdded = maxAchievable + 1;
                maxAchievable += patchAdded;
                patches++;
            }
        }
        return patches;
            
    }
};
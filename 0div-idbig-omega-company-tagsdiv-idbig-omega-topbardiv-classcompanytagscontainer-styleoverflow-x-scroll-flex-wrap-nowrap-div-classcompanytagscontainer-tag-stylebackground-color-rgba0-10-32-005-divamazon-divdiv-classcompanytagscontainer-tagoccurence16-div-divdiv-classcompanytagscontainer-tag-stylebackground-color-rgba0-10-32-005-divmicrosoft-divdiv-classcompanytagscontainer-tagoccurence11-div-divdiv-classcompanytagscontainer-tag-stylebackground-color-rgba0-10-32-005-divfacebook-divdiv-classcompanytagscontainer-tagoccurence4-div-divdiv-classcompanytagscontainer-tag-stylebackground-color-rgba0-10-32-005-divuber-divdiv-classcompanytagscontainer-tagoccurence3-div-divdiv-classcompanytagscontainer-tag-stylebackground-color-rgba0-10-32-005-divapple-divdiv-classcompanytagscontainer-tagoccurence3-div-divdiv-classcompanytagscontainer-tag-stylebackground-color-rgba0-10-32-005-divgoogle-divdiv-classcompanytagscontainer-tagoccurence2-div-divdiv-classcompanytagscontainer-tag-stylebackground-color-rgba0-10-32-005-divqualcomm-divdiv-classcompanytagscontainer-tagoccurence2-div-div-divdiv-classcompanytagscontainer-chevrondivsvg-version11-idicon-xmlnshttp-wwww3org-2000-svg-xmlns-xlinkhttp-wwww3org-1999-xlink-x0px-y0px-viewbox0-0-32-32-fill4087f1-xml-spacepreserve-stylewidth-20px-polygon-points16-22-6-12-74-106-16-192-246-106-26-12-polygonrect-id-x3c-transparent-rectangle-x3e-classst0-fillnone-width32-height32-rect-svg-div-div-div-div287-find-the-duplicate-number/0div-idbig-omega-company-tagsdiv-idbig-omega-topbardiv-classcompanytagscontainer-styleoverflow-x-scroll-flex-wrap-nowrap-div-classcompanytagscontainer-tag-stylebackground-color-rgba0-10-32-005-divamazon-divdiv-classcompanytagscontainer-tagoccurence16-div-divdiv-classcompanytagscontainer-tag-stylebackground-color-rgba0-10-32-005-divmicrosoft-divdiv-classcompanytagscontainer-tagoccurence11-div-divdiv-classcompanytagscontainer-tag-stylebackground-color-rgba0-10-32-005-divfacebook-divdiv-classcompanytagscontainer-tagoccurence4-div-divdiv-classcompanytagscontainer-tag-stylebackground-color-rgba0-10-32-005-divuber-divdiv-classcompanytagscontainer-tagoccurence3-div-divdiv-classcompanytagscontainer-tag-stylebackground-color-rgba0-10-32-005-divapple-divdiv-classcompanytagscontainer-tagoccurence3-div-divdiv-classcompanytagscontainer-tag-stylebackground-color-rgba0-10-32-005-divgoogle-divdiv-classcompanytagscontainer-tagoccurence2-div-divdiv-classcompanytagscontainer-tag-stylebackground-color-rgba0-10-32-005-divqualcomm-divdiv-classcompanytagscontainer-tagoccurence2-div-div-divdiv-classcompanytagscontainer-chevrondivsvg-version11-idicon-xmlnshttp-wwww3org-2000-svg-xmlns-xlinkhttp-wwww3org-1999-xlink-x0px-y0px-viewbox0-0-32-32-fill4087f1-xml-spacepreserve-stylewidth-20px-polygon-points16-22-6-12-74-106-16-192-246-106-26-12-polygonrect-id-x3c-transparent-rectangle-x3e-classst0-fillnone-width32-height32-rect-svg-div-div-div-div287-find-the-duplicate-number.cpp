class Solution {
private:
    int bruteForce(vector<int>& nums, int n)
    {
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++)
            if(nums[i] == nums[i+1])
                return nums[i];
        return -1;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        return bruteForce(nums, n);
        
    }
};
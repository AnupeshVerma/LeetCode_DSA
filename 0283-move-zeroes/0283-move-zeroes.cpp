class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind=0, i;
        
        for(i=0; i<nums.size(); i++)
            if(nums[i] == 0)
                continue;
            else nums[ind++] = nums[i];
        
        while(ind < nums.size())
            nums[ind++] = 0;
    }
};
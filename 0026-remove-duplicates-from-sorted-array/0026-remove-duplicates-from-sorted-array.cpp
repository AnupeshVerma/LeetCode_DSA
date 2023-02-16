class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] != nums[i+1])
                nums[ans++] = nums[i];
        }
//      As the last element will never get compared whether it is duplicate or not so add it directly at the end
        nums[ans++] = nums[nums.size()-1];
        return ans;
    }
};
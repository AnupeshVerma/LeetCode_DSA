class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
//         Brute Force Approach
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<n-1; i++)
        //     if(nums[i] == nums[i+1])
        //         return nums[i];
        // return -1;
        
        
//         Optimal Approach (Cyclic Linked List Method)
        int fast=nums[0], slow=nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
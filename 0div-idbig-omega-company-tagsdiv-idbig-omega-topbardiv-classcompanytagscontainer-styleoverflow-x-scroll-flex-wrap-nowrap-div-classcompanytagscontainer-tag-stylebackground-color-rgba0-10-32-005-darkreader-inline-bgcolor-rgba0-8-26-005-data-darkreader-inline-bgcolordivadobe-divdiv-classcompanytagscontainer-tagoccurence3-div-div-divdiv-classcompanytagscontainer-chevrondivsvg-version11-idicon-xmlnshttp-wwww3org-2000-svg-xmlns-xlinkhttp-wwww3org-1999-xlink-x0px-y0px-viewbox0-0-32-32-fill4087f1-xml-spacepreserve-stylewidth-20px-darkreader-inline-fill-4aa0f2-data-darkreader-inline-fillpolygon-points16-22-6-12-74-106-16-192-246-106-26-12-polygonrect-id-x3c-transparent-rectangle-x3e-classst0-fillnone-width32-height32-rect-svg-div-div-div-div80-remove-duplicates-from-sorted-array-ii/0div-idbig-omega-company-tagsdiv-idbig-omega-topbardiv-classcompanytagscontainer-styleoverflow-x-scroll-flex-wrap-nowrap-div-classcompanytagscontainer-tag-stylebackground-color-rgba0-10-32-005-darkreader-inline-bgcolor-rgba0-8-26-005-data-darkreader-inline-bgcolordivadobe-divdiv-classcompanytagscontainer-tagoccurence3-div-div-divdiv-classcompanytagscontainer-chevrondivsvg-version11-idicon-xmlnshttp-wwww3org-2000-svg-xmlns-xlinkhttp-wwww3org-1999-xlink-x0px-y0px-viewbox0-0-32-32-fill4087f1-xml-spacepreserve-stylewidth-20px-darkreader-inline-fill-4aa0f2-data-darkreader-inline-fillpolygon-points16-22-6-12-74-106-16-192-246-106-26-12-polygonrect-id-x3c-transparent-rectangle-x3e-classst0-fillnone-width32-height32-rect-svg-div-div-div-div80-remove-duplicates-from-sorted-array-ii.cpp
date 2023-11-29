class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        
        if(n==1 || n==2)
            return n;
        
        for(int i=0; i<n-2; i++)
        {
            if(nums[i]!=nums[i+2])
                nums[k++] = nums[i];
        }
        
        nums[k++] = nums[n-2];
        nums[k++] = nums[n-1];
        
        return k;
    }
};
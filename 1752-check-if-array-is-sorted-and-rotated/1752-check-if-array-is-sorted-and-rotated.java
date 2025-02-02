class Solution {
    public boolean check(int[] nums) {
        int n = nums.length, k = 0;

        for(int i=0; i<n-1; i++)
            if(nums[i] > nums[i+1])
                k++;

        if(k == 0 )
            return true;

        if(k == 1 && nums[0] >= nums[n-1])
            return true;
    
        return false;
    }
}
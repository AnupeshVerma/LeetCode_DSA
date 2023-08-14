class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
//      Since numbers are from 1 to N => Cycles Sort 
        int n = nums.size();
        int i=0;
        
        while(i<n)
        {
            int correctInd = 1L*nums[i] - 1;
            if(nums[i]<=n && nums[i]>0 && nums[i] != nums[correctInd])
                swap(nums[i], nums[correctInd]);
            else
                i++;
        }
        
        for(int i=0; i<n; i++)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};
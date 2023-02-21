class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-1, mid;
        
        while(low<high)
        {
            mid = (low+high)/2;
            // if mid is at odd index nums[mid] should be equal to nums[mid]
            if(mid==0 || mid==nums.size()-1)  return nums[mid];
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
               return nums[mid];
            else if(mid%2!=0 && nums[mid] != nums[mid-1])
                high=mid-1;
            else if(mid%2==0 && nums[mid] == nums[mid-1])
                high = mid-1;
            
            else low = mid+1;
            
        }
        return nums[low];
    }
};
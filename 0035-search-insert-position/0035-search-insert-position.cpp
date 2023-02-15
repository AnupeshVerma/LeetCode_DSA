class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front=nums.size()-1;
        int back=0, mid;
        
        while(front >= back)
        {
            mid = (front+back)/2;
            
            if(nums[mid] == target)
                return mid;
            if(target >= nums[mid])
                back = mid+1;
            else front = mid-1;
            
        }
        return back;
    }
};
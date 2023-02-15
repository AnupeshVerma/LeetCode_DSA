class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = nums.size()-1;
        int back = 0, mid;
        
        while(front >= back)
        {
            mid = (front+back)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
            {
                back = mid+1;
                continue;
            }
            else front = mid-1;
        }
        return -1;
    }
};
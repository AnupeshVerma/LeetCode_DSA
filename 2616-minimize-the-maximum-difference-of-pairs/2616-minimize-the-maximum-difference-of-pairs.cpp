class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low=0, high = nums[n-1]-nums[0];
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            
//             Find total adjacent pairs whose difference less than mid
            int pairs = 0;
            for(int i=1; i<n && pairs<p; i++)
                if(nums[i] - nums[i-1] <= mid)
                {
                    pairs++;
                    i++;    //so that same no. will not counted in next pair
                }
            if(pairs >= p)
                high = mid;
            else
                low  = mid+1;
        }
        return low;
    }
};
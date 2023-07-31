class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
//         Two Traversal
        int n = nums.size();
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        bool zeroPresent = false;
        
        int product = 1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                zeroPresent = true;
                product = 1;
            }
            else
            {
                product*=nums[i];
                maxLeft = max(maxLeft, product);
            }
        }
        
        product = 1;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] == 0)
                product = 1;
            else
            {
                product *= nums[i];
                maxRight = max(maxRight, product);
            }
        }
        if(zeroPresent)
            return max(max(maxLeft, maxRight), 0);
        else 
            return max(maxLeft, maxRight);
    }
};
class Solution {
private:
    int slidingWindow(vector<int>& nums, int k, int n)
    { 
        int odds = 0, ans = 0, left = 0;

        for (int right = 0; right<n; right++) 
        {
            odds += nums[right] % 2;
           
            while(odds > k) 
                odds -= nums[left++] % 2;
            
            ans += right - left + 1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        return slidingWindow(nums, k, n) - slidingWindow(nums, k-1, n);
    }
};
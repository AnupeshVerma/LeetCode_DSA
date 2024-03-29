class Solution {
private:
    long long bruteForce(vector<int>& nums, int k, int n)
    {
        int maxNum = nums[0], count = 0;
        for(int num : nums)
            maxNum = max(maxNum, num);
        
        for(int i=0; i<n; i++)
        {
            int freq = 0;
            for(int j=i; j<n; j++)
            {
                if(nums[j] == maxNum)
                    freq++;
                if(freq >= k)
                    count++;
            }
        }
        return count;
    }
    
    long long slidingWindow(vector<int>&nums, int k, int n)
    {
        int maxNum = nums[0];
        long long count = 0;
        for(int num : nums)
            maxNum = max(maxNum, num);
        
        int front=0, back=0, freq=0;
        while(front < n)
        {
            if(nums[front] == maxNum)
                freq++;
            
            while(freq >= k)
            {
                if(nums[back] == maxNum)
                    freq--;
                back++;
            }
            count += back;
            front++;
        }
        return count;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // return bruteForce(nums, k, n);  
        
        return slidingWindow(nums, k, n);
    }
};
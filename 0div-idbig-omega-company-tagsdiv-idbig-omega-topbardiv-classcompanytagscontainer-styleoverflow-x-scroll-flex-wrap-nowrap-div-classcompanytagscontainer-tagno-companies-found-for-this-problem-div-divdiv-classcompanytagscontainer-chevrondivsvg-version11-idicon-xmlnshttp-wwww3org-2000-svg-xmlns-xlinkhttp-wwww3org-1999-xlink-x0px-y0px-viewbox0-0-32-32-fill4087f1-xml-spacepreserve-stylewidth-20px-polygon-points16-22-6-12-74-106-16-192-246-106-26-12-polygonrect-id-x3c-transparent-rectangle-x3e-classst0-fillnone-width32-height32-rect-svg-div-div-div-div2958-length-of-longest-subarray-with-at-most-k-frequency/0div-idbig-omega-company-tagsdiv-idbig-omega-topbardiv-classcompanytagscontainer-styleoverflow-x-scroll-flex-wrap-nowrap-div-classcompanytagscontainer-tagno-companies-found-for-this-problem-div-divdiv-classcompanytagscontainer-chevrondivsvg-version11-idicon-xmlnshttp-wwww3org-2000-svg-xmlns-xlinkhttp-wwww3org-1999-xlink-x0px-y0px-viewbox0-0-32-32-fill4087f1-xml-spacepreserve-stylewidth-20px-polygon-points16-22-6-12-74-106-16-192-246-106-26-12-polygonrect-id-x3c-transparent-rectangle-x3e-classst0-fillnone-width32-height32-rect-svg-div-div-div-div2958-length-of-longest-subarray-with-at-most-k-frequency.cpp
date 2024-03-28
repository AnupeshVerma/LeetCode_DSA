class Solution {
private:
    int bruteForce(vector<int>& nums, int k, int n)
    {
        int maxSize = 0;
        
        for(int i=0; i<n; i++)
        {
            unordered_map<int, int>freq;
            for(int j=i; j<n; j++)
            {
                freq[nums[j]]++;
                if(freq[nums[j]] <= k)
                    maxSize = max(maxSize, j-i+1);
                else
                    break;
            }
        }
        return maxSize;
    }
    
    int slidingWindow(vector<int>& nums, int k, int n)
    {
        int maxSize=0;
        int front=0, back=0;
        unordered_map<int, int>freq;
        
        while(front < n)
        {
            freq[nums[front]]++;
            
            while(freq[nums[front]] > k)
                freq[nums[back++]]--;
            
            maxSize = max(maxSize, front-back+1);
            front++;
        }
        
        return maxSize;
    }


public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // return bruteForce(nums, k, n);
        
        return slidingWindow(nums, k, n);
    }
};
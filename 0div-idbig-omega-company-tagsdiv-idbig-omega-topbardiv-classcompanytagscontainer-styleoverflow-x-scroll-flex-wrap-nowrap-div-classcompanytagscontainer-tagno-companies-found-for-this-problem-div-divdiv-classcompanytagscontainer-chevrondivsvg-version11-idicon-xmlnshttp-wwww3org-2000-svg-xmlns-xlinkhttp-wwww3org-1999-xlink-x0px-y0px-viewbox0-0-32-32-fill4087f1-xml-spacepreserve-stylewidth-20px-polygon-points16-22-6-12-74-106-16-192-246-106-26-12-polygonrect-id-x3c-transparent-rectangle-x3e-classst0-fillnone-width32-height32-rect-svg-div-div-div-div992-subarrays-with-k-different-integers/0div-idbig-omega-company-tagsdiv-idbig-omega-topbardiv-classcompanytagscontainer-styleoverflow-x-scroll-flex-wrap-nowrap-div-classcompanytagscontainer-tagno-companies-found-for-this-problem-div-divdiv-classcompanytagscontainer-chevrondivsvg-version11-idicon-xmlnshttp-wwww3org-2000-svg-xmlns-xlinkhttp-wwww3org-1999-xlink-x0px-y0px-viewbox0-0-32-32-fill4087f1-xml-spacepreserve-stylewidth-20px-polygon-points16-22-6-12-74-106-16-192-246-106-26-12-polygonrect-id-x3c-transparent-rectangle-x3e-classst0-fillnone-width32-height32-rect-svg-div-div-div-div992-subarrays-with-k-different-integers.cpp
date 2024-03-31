class Solution {
private:
    int bruteForce(vector<int>& nums, int k, int n)
    {
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            unordered_set<int>st;
            for(int j=i; j<n; j++)
            {
                st.insert(nums[j]);
                if(st.size() == k)
                    count++;
                else if(st.size() > k)
                    break;
            }
        }
        return count;
    }
    
    int slidingWindow(vector<int>& nums, int k, int n)
    {
        int count = 0;
        int front=0, back=0;
        unordered_map<int, int>freq;
        
        while(front < n)
        {
            freq[nums[front]]++;
            
            while(freq.size() > k)
            {
                freq[nums[back]]--;
                if(freq[nums[back]] == 0)
                    freq.erase(nums[back]);
                back++;
            }
            count += front-back+1;
            front++;
        }
        return count;
    }
    
     int slidingWindowOnePass(vector<int>& nums, int k, int n)
    {
        int currCount=0, totalCount=0;
        int front=0, back=0, distinct=0;
       unordered_map<int, int>freq;
        
        while(front < n)
        {
            freq[nums[front]]++;
            
            // If there is a new element, decrement k
            if(freq[nums[front]] == 1)
                distinct++;
            
            // Move back pointer until k becomes valid again
            if(distinct > k)
            {
                freq[nums[back++]]--;
                distinct--;
                currCount = 0;
            }
            
            // If k becomes zero, calculate subarrays
            if(distinct == k)
            {
                // If any num have frequency zero, break loop
                while(freq[nums[back]] > 1)
                {
                    freq[nums[back++]]--;
                    currCount++;
                }
                totalCount += currCount + 1;
            }
            front++;
        }
        return totalCount;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        // return bruteForce(nums, k, n);
        
        // return slidingWindow(nums, k, n) - slidingWindow(nums, k-1, n);
        
        return slidingWindowOnePass(nums, k, n);
    }
};
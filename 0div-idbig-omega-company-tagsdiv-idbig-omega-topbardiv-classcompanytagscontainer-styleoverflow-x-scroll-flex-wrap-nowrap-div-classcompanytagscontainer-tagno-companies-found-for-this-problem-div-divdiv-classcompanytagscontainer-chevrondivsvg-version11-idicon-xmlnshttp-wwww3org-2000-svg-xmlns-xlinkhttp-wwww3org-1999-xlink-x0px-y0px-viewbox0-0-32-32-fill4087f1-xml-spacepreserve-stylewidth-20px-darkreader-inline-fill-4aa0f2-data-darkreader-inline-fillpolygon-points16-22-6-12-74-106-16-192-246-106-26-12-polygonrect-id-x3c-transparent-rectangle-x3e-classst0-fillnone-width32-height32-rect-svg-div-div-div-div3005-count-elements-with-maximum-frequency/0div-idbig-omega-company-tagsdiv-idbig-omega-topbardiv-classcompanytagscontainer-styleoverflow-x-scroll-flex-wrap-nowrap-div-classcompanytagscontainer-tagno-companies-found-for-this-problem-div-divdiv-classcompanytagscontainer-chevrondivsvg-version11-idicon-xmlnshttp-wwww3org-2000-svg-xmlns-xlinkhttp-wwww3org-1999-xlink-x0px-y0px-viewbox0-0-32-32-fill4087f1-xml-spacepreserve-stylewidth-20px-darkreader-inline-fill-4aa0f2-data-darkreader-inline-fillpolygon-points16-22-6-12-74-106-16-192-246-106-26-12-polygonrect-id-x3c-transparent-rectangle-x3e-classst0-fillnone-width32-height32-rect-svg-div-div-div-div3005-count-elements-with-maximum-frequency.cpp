class Solution {
private:
    int bruteForce(vector<int>& nums)
    {
        unordered_map<int, int>mp;
        
        for(auto num : nums)
            mp[num]++;
        
        int maxFreq=0;
        for(auto a:mp)
            maxFreq = max(maxFreq, a.second);
        
        int ans = 0;
        for(auto a:mp)
            if(a.second == maxFreq)
                ans += maxFreq;

        return ans;
    }
    
    int usingSort(vector<int>& nums)
    {
        vector<int>freq(101, 0);
        
        for(auto num:nums)
            freq[num]++;
        

        sort(freq.begin(), freq.end());
        
        int n = 101;
        int i = n-2, ans = freq[n-1]; cout<<ans;
        while(i>=0 && freq[i]==freq[n-1])
            ans += freq[i--];
        
        return ans;    
    }
    
    int singleLoop(vector<int>& nums)
    {
        vector<int>freq(101, 0);
        int maxFreq=0, ans=0;
        
        for(int num:nums)
        {
            freq[num]++;
            
            if(freq[num] > maxFreq)
            {
                maxFreq = freq[num];
                ans = maxFreq;
            }
            else if(freq[num] == maxFreq)
                ans += maxFreq;
        }
        return ans;
    }
public:
    int maxFrequencyElements(vector<int>& nums) {
       
        
        // return bruteForce(nums);
        
        // return usingSort(nums);
        
        return singleLoop(nums);
    }
};
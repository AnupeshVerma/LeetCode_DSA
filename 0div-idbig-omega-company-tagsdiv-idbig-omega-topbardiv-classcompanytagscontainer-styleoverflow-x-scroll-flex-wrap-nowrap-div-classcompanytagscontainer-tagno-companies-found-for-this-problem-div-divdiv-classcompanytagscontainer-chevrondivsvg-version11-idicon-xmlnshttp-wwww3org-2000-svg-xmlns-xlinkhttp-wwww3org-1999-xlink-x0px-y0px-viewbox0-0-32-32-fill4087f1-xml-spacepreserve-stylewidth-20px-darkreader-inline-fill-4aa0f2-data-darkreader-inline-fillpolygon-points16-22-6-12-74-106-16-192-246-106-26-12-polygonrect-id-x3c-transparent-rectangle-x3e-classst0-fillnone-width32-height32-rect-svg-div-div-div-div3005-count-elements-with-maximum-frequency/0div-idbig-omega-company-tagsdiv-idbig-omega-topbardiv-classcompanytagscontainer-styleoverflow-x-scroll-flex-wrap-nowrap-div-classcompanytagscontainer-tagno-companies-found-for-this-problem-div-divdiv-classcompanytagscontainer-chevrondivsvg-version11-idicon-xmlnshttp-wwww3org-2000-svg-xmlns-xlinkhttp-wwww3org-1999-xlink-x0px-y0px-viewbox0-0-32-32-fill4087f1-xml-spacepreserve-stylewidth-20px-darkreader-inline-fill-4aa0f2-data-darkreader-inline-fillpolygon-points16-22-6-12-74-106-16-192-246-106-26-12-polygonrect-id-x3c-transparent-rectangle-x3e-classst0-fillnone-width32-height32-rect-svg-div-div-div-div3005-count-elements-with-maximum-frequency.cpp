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
public:
    int maxFrequencyElements(vector<int>& nums) {
       
        
        return bruteForce(nums);
    }
};
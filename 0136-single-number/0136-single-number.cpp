class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int, int>mp;
        for(auto i:nums)
            mp[i]++;
        
        
        for(auto i:mp)
            if(i.second != 2)
            {
                ans = i.first;
                break;
            }
        return ans;
            
    }
};
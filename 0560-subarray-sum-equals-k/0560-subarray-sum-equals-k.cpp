class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, ans=0;
        unordered_map<int, int>mp;
        mp[sum]++;
        
        for(int i:nums)
        {
             sum+=i;
            if(mp.find(sum-k) != mp.end() || i==k)
                ans+=mp[sum-k];
           
            mp[sum]++;
            
        }
        return ans;
    }
};
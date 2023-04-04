class Solution {
public:
    int partitionString(string s) {
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(auto i:s)
        {
            if(mp.find(i) != mp.end())
            {
                mp.clear();
                ans++;
            }
            mp[i]++;
        }
        if(!mp.empty())
            ans++;
        return ans;
    }
};
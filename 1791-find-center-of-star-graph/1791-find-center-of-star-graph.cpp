class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int>mp;
        
        for(auto i:edges)
            for(auto j:i)
            {
                mp[j]++;
            }
        int ans, freq=0;
        for(auto it:mp)
        {
            cout<<it.second;
            if(it.second > freq)
            {
                ans = it.first;
                freq = it.second;
            }
        }
        return ans;
    }
};
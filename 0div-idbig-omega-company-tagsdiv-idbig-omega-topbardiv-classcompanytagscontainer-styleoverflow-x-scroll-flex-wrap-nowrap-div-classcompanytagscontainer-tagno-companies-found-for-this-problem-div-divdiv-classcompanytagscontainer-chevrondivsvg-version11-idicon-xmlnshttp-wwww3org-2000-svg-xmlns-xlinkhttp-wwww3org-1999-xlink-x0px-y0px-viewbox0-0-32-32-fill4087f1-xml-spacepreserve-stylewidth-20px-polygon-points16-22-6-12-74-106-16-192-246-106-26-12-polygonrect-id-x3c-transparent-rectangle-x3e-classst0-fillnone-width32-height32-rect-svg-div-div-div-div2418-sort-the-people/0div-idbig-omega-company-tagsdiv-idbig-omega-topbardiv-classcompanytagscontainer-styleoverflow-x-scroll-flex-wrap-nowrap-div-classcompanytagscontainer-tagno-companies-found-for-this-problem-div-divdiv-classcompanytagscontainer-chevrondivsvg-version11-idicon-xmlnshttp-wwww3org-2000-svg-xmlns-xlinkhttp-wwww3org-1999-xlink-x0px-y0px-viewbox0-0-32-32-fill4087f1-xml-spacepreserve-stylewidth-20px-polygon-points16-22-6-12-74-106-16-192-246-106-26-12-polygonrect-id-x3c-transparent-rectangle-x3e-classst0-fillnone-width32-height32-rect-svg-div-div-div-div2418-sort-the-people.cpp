class Solution {
private:
    vector<string> bruteForce(vector<string>& names, vector<int>& h, int n)
    {
        map<int, string> mp;
        
        for(int i=0; i<n; i++)
            mp[h[i]] = names[i];
        
        vector<string> ans;
        for(auto it:mp)
            ans.push_back(it.second);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        return bruteForce(names, heights, n);
    }
};
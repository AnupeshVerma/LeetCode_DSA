class Solution {
private:
    vector<vector<int>>dp;
    unordered_map<int, int>mp;
    int solve(vector<int>&stones, int ind, int k)
    {
        if(ind == stones.size()-1)
            return true;
        if(ind >= stones.size())
            return 0;
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
        
        int a=false, b=false, c=false;
        if(mp.find(stones[ind]+k-1) != mp.end() && k>1)
            a = solve(stones, mp[stones[ind]+k-1], k-1);
        
        if(mp.find(stones[ind]+k) != mp.end())
            b = solve(stones, mp[stones[ind]+k], k);
        
        if(mp.find(stones[ind]+k+1) != mp.end())
            c = solve(stones, mp[stones[ind]+k+1], k+1);
        
        return dp[ind][k] = a || b || c;
        
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1)
            return false;
        dp.resize(n+1, vector<int>(n+1, -1));
        
        for(int i=0; i<n; i++)
            mp[stones[i]] = i;
        
        return solve(stones, 1, 1);
    }
};
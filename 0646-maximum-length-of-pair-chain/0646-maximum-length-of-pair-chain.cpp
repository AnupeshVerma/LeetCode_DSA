class Solution {
private:
    int solve(vector<vector<int>>& pairs, int ind, int last, vector<vector<int>>&dp)
    {
        if(ind >= pairs.size())
            return 0;
        
        if(dp[ind][last] != -1)
            return dp[ind][last];
        
        if(pairs[ind][0]+1001 > last)
        {
            int take = 1 + solve(pairs, ind+1, pairs[ind][1]+1001, dp);
            int not_take = solve(pairs, ind+1, last, dp);
            return dp[ind][last] = max(take, not_take);
        }
        else
            return dp[ind][last] = solve(pairs, ind+1, last, dp);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>>dp(n+1, vector<int>(2005, -1));
        return solve(pairs, 0, 0, dp);
    }
};
class Solution {
public:
    bool solve(unordered_set<string>&words, string &s, int i, int j, vector<vector<int>>&dp)
    {
        if(i>j)
            return false;
        
        if(words.find(s.substr(i, j-i+1)) != words.end())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        for(int k=i; k<=j-1; k++)
            if(solve(words, s, i, k, dp) && solve(words, s, k+1, j, dp))
                return dp[i][j] = true;
        return dp[i][j] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>words(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(words, s, 0, n-1, dp);
    }
};
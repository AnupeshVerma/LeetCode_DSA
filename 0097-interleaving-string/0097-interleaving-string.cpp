class Solution {
private:
    bool solve(string s1, string s2, string s3,  vector<vector<int>>&dp)
    {
        if(s1.empty() && s2.empty() && s3.empty())
            return true;
        
        if(s3.empty())
            return false;
        
        if(dp[s1.size()][s2.size()] != -1)
            return dp[s1.size()][s2.size()];
        
        bool fir = s1[0]==s3[0] && solve(s1.substr(1), s2, s3.substr(1), dp);
        bool sec = s2[0]==s3[0] && solve(s1, s2.substr(1), s3.substr(1), dp);
        
        return dp[s1.size()][s2.size()] = fir || sec;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s1.size() + s2.size()))
            return false;
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(s1, s2, s3, dp);
    }
};
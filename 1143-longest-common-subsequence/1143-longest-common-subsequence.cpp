class Solution {
public:
    int bottomUp(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(s1[m-1] == s2[n-1])
            return dp[m][n] = 1 + bottomUp(s1, s2, m-1, n-1, dp);
        else
            return dp[m][n] = max(bottomUp(s1, s2, m-1, n, dp), bottomUp(s1, s2, m, n-1, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         Bottom-Up OR Memoization Approach
        // return bottomUp(s1, s2, m, n, dp);
        
//         Top-Down Approach
        for(int i=0; i<m+1; i++)
            for(int j=0; j<n+1; j++)
                 if(i==0 || j==0)
                    dp[i][j]=0;
                
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {              
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};
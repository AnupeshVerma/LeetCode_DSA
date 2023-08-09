class Solution {
public:
    int LCS(string s, string t, int n, int m, vector<vector<int>>&dp)
    {
        if(m==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s[n-1] == t[m-1])
         
            return dp[n][m] = LCS(s, t, n-1, m-1, dp) + LCS(s, t, n-1, m, dp);
        else
            return dp[n][m] = LCS(s, t, n-1, m, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>>dp(n+1, vector<double>(m+1, -1));
        //        MEMOIZATION
        // return LCS(s, t, n, m, dp);
        
        
//         TOP-DOWN APPROACH
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        
         for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][m];
    }
};
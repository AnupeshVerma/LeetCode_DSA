class Solution {
    private:
    int lcs(string s1, string s2, int n, int m, vector<vector<int>>&memo)
    {
        if(n==0 || m==0)
            return 0;
        if(memo[n][m] != -1)
            return memo[n][m];
        
        if(s1[n-1] == s2[m-1])
            return memo[n][m] = s1[n-1] + lcs(s1, s2, n-1, m-1, memo);
        else
            return memo[n][m] = max(lcs(s1, s2, n-1, m, memo), lcs(s1, s2, n, m-1, memo));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        

        int total_sum1 = 0;
        int total_sum2 = 0;

        for(int i=0; i<n; i++)
            total_sum1 += s1[i];
        for(int i=0; i<m; i++)
            total_sum2 += s2[i];
        // Memoization
//         int LCS_sum = lcs(s1, s2, n, m, memo);
//         return (total_sum1-LCS_sum) + (total_sum2 - LCS_sum);
        
//         Top Down Approach
        for(int i=0; i<=n; i++)
             for(int j=0; j<=m; j++)
                 if(i==0 || j==0)
                     dp[i][j] = 0;
        
        for(int i=1; i<=n; i++)
             for(int j=1;j<=m; j++)
             {
                 if(s1[i-1] == s2[j-1])
                     dp[i][j] = s1[i-1] + dp[i-1][j-1];
                 else
                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
        return (total_sum1-dp[n][m]) + (total_sum2-dp[n][m]);
    }
};
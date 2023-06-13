class Solution {
public:
    int lcs(vector<int>& n1, vector<int>& n2, int m, int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(n1[m-1] == n2[n-1])
            return dp[m][n] =  1 + lcs(n1, n2, m-1, n-1, dp);
        else
            return dp[m][n] = max(lcs(n1, n2, m-1, n, dp), lcs(n1, n2, m, n-1, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return lcs(nums1, nums2, m, n, dp);
    }
};
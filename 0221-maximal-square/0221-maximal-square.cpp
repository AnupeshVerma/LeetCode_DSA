class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        
//         TOP-DOWN APPROACH
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0)
                    if(matrix[i][j] == '0')
                        dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = 1;
                        maxi=1;
                    }
            }
        
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];
                    int diagonal = dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min({left, up, diagonal});
                    maxi = max(maxi, dp[i][j]);
                }
            }
        return maxi*maxi;
    }
};
class Solution {
private:
    int mod = 1e9+7;
    vector<vector<int>> memo;

    int solve(int n, int k, int i) {
        if(k == 0)
            return 1;
        if(i >= n) 
            return 0;
        
        if(memo[k][i] != -1)
            return memo[k][i];

        //Skip this starting point
        long long skip = solve(n, k, i+1);

        //Start from ith point and end at j
        long long take = 0;
        for(int j=i+1; j<n ;j++) {
            take += solve(n, k-1, j) % mod;
        }
        return memo[k][i] = (skip + take) % mod;
    }

    int bottomUp(int n, int K) {
        vector<vector<int>> dp(K+1, vector<int>(n+1, 0));

        //Base condition
        for(int i=0; i<n; i++) {
            dp[0][i] = 1;
        }

        for(int k=1; k<=K; k++) {
            for(int i=n-1; i>=0; i--) {
                long long skip = dp[k][i+1];

                long long take = 0;
                for(int j=i+1; j<n; j++) {
                    take = (take + dp[k-1][j]) % mod;
                }
            dp[k][i] = (skip + take) % mod;
            }
        }
        return dp[K][0];
    }

        int optimizedBottomUp(int n, int K) {
        vector<vector<int>> dp(K+1, vector<int>(n+1, 0));

        //Base condition
        for(int i=0; i<n; i++) {
            dp[0][i] = 1;
        }

        for(int k=1; k<=K; k++) {

            vector<int> prevRowSum(n+1, 0);
            for(int x = n-1; x>=0; x--){
                prevRowSum[x] = (prevRowSum[x+1] + dp[k-1][x]) % mod;
            }

            for(int i=n-1; i>=0; i--) {
                int skip = dp[k][i+1];
                int take = prevRowSum[i+1];

            dp[k][i] = (skip + take) % mod;
            }
        }
        return dp[K][0];
    }

public:
    int numberOfSets(int n, int k) {
        memo.resize(k+1, vector<int>(n+1, -1));

        return optimizedBottomUp(n, k);
        
        return bottomUp(n, k);

        return solve(n, k, 0);
    }
};
class Solution {
#define MOD 1000000007

vector<vector<int>> dp;
private:
    int useKnapsackDP(int n, int x, int i, int currSum) {
        int powerVal = pow(i, x);

        if(currSum == n)
            return 1;

        if(currSum > n || powerVal > n)
            return 0;
        
        if(dp[i][currSum] != -1)
            return dp[i][currSum];
        
        int included = 0;
        if(currSum + powerVal <= n)
            included = useKnapsackDP(n, x, i + 1, currSum + powerVal);

        int not_included = useKnapsackDP(n, x, i+1, currSum);

        return dp[i][currSum] = (int)((included + not_included) % MOD);
    }


public:
    int numberOfWays(int n, int x) {
        dp.assign(n + 2, vector<int>(n + 1, -1));

        return useKnapsackDP(n, x, 1, 0);
    }
};
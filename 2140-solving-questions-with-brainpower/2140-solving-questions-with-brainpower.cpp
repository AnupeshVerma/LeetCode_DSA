class Solution {
public:
    long long solve(vector<vector<int>>&qns, vector<long long>&dp, int ind)
    {
        if(ind >= qns.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
//         Solved
        long long solved = qns[ind][0] + solve(qns, dp, ind+qns[ind][1]+1);
        long long skipped= solve(qns, dp, ind+1);
        
        return dp[ind] = max(solved, skipped);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1, -1);
        
//         MEMOIZATION
        return solve(questions, dp, 0);
    }
};
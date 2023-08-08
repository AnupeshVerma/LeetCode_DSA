class Solution {
private:
    int solve(vector<vector<int>>&scoreAge, vector<vector<int>>&dp, int i, int last_age)
    {
        if(i>=scoreAge.size())
            return 0;
        if(dp[i][last_age] != -1)
            return dp[i][last_age];
        
        if(last_age<=scoreAge[i][1])
            return dp[i][last_age] = max(scoreAge[i][0]+solve(scoreAge, dp, i+1, scoreAge[i][1]), solve(scoreAge, dp, i+1, last_age));
        else
            return dp[i][last_age] = solve(scoreAge, dp, i+1, last_age);
    }
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>>dp(n+1, vector<int>(1001, -1));
        
        vector<vector<int>>scoreAge;
        for(int i=0; i<n; i++)
            scoreAge.push_back({scores[i], ages[i]});
        
        sort(scoreAge.begin(), scoreAge.end());
        return solve(scoreAge, dp, 0, 0);
    }
};
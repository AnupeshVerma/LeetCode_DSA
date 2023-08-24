class Solution {
private:
    vector<int>temp, dp;
    int solve(vector<vector<int>>&of, vector<int>&dp, int ind)
    {
        if(ind >= of.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int not_take = solve(of, dp, ind+1);
        
        int next_ind = lower_bound(temp.begin(), temp.end(), of[ind][1]+1) - temp.begin();
        int take = of[ind][2] + solve(of, dp, next_ind);
        
        return dp[ind] = max(take, not_take);
    
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        dp.resize(offers.size()+1, -1);
        for(auto it:offers)
            temp.push_back(it[0]);
        
        return solve(offers, dp, 0);
        
    }
};
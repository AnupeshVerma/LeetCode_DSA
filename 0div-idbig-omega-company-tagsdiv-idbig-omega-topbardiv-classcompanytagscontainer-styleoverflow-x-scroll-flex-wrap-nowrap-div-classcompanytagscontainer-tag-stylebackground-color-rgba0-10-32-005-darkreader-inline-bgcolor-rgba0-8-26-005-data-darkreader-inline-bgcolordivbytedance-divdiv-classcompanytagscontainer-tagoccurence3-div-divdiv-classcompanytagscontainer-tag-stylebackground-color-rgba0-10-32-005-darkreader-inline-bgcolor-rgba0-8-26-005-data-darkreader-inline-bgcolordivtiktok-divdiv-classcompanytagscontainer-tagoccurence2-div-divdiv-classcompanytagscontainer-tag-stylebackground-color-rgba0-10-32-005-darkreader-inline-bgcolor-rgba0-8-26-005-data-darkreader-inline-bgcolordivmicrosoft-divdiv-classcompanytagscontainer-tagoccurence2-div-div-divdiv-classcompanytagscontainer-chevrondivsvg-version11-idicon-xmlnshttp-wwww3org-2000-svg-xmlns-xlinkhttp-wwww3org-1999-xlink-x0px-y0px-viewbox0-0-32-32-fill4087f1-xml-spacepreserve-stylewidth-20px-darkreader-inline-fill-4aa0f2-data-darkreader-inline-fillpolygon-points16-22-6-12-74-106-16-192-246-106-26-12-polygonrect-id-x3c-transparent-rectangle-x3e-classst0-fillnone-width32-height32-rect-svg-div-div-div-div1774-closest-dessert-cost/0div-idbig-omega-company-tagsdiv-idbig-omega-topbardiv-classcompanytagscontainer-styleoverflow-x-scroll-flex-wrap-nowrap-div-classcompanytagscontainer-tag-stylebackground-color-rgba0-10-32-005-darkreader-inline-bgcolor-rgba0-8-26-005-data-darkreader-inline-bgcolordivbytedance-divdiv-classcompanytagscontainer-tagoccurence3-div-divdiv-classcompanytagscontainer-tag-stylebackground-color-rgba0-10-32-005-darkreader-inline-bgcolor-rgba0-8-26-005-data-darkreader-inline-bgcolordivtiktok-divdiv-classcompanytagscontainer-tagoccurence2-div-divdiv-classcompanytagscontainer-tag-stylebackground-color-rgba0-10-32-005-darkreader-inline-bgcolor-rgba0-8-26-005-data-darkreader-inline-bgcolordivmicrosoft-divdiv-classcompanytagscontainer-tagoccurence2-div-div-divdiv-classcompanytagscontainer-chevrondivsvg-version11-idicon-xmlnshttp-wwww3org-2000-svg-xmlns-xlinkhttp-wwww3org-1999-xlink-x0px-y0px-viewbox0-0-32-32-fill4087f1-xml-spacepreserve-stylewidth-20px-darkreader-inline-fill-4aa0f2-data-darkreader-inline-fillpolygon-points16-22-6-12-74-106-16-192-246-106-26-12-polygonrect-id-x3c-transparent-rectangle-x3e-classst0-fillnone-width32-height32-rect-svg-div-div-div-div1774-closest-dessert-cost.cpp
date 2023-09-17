class Solution {
private:
    int ans = INT_MAX;
    void solve(vector<int>&tCost, int target, int n, int currCost)
    {
        if(n<=0)
        {
            if(abs(currCost-target) < abs(ans-target))
                ans = currCost;
            else if(abs(currCost-target) == abs(ans-target))
                ans = min(ans, currCost);
            return;
        }
        
        solve(tCost, target, n-1, currCost);
        solve(tCost, target, n-1, currCost + tCost[n-1]);
        solve(tCost, target, n-1, currCost + tCost[n-1]*2);
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = toppingCosts.size();
        for(auto baseCost:baseCosts)
            solve(toppingCosts, target, n, baseCost);
        return ans;
    }
};
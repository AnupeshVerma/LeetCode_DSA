class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //----naive approach
        /*
        int ans =0;
        for(int i=0; i<prices.size(); i++)
        {
            for(int j=i; j<prices.size(); j++)
            {
                ans  = max(ans, prices[j]-prices[i]);
            }
        }
        return ans;
        */
        
        
        //----Better Approach
        
        int profit = 0, max_profit=0, mini=INT_MAX;
        
        for(int i:prices)
        {
            mini = min(mini, i);
            profit = i - mini;
            max_profit = max(profit, max_profit);
        }
        return max_profit;
    }
};
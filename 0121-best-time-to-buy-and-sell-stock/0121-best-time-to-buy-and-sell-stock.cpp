class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int mini = INT_MAX;
        int profit=0, max_profit = 0;
        
        for(int i=0; i<p.size(); i++)
        {
            if(mini > p[i])
                mini = p[i];
            
            profit = p[i] - mini;
            max_profit = max(max_profit, profit);
        }
        
        return max_profit;
    }
};
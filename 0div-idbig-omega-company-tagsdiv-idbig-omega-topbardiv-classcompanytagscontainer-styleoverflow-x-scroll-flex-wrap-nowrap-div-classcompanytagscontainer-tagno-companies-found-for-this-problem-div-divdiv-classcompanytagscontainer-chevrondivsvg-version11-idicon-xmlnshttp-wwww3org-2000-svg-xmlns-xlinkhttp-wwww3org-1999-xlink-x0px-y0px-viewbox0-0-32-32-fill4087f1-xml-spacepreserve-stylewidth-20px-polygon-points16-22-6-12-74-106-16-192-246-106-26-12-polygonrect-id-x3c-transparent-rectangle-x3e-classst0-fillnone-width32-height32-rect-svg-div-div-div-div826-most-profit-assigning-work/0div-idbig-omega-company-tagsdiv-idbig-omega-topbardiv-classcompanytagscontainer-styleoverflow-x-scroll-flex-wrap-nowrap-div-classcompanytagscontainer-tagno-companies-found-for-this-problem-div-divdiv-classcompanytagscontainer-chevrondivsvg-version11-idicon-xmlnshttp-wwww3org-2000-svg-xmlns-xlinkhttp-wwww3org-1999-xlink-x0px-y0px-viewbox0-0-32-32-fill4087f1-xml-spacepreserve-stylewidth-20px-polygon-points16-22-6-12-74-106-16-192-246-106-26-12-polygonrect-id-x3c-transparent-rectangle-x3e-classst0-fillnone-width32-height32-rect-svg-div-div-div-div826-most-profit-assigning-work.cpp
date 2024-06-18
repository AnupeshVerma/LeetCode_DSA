class Solution {
private:
    int bruteForce(vector<int>& d, vector<int>& p, vector<int>& w)
    {   
        int totalProfit = 0;
        for(int i=0; i<w.size(); i++)
        {
            int maxProfit = 0;
            for(int j=0; j<d.size(); j++)
            {
                if(d[j] <= w[i])
                    maxProfit = max(maxProfit, p[j]);
            }
            totalProfit += maxProfit;
        }
        return totalProfit;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = worker.size();
        int n = profit.size();
        
        return bruteForce(difficulty, profit, worker);
    }
};
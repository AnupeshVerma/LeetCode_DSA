class Solution {
private:
    int slidingWindow(vector<int>& c, vector<int>& g, int m, int n)
    {
        int unsatisfied = 0;
        for(int i=0; i<m; i++)
            unsatisfied += c[i]*g[i];
        
        int maxUnsatisfied = unsatisfied;
        for(int i=m; i<n; i++)
        {
            unsatisfied += c[i]*g[i];
            unsatisfied -= c[i-m]*g[i-m];
            
            maxUnsatisfied = max(unsatisfied, maxUnsatisfied);
        }
        
        int satisfied = maxUnsatisfied;
        for(int i=0; i<n; i++)
            satisfied += c[i]*(1-g[i]);
        
        return satisfied;
    }
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        return slidingWindow(customers, grumpy, minutes, n);
        
    }
};
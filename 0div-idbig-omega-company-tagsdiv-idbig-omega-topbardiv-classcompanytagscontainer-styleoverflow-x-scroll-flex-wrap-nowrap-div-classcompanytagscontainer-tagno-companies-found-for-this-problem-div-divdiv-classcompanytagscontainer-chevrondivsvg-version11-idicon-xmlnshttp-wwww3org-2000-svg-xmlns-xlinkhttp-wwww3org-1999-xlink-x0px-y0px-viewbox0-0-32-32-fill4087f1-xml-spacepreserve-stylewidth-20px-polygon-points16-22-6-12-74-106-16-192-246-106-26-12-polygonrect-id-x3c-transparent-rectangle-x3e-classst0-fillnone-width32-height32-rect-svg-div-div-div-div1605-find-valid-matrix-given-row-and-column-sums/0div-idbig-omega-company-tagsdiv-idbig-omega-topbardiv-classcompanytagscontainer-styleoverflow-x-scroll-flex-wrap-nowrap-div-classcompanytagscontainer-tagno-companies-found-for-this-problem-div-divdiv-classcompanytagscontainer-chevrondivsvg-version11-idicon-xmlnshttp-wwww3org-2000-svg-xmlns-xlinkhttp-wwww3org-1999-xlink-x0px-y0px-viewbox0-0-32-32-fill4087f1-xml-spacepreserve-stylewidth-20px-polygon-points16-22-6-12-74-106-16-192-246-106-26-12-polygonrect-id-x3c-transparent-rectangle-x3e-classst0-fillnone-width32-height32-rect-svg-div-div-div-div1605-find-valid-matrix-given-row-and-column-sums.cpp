class Solution {
private:
    vector<vector<int>> greedy(vector<int>& rowSum, vector<int>& colSum, int n, int m)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<int> currRowSum(n, 0);
        vector<int> currColSum(m, 0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j] = min(rowSum[i]-currRowSum[i], colSum[j]-currColSum[j]);
                
                currRowSum[i] += ans[i][j];
                currColSum[j] += ans[i][j];
            }
        }
        return ans;
    }
    
    vector<vector<int>> optimized(vector<int> rowSum, vector<int> colSum, int n, int m)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        int i=0, j=0;
        while(i<n && j<m)
        {
            ans[i][j] = min(rowSum[i], colSum[j]);
            
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            
            rowSum[i]==0 ? i++ : j++;
        }
        return ans;
    }
    
    
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        
        // Greedy approach --> O(nxm)
        // return greedy(rowSum, colSum, n, m);
        
        // Time optimized --> O(n+m)
        return optimized(rowSum, colSum, n, m);
    }
};